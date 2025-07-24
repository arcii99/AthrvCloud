//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_LEN 1024

typedef enum {
    JSON_TYPE_NONE,
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY,
    JSON_TYPE_STRING,
    JSON_TYPE_NUMBER,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NULL
} json_type;

typedef struct json_value_t {
    union {
        char *string_value;
        double number_value;
        int boolean_value;
        struct json_object_t *object_value;
        struct json_array_t *array_value;
    } value;
    json_type type;
} json_value;

typedef struct json_member_t {
    char *key;
    json_value *value;
} json_member;

typedef struct json_object_t {
    json_member *members;
    int count;
} json_object;

typedef struct json_array_t {
    json_value **items;
    int count;
} json_array;

char json[MAX_JSON_LEN];
json_value *root = NULL;

json_value *parse_json_value(char **json);
json_object *parse_json_object(char **json);
json_array *parse_json_array(char **json);

void eat_spaces(char **json) {
    while (isspace(**json))
        ++(*json);
}

void eat_string(char **json, char *s) {
    int len = strlen(s);
    if (strncmp(*json, s, len) == 0)
        (*json) += len;
}

void parse_error(char *error_message) {
    printf("Error parsing JSON: %s\n", error_message);
    exit(1);
}

json_value *parse_json_value(char **json) {
    eat_spaces(json);
    json_value *value = (json_value *)malloc(sizeof(json_value));
    if (**json == '{') {
        ++(*json);
        value->value.object_value = parse_json_object(json);
        value->type = JSON_TYPE_OBJECT;
    } else if (**json == '[') {
        ++(*json);
        value->value.array_value = parse_json_array(json);
        value->type = JSON_TYPE_ARRAY;
    } else if (**json == '\"') {
        ++(*json);
        char *s = *json;
        while (*s != '\"')
            ++s;
        int len = s - (*json);
        ++s;
        value->value.string_value = (char *)malloc(sizeof(char) * (len + 1));
        strncpy(value->value.string_value, *json, len);
        value->value.string_value[len] = '\0';
        *json = s;
        value->type = JSON_TYPE_STRING;
    } else if (isdigit(**json) || **json == '-') {
        char *s = *json;
        while (isdigit(*s) || *s == '-' || *s == '.')
            ++s;
        int len = s - (*json);
        char *number_string = (char *)malloc(sizeof(char) * (len + 1));
        strncpy(number_string, *json, len);
        *json = s;
        number_string[len] = '\0';
        value->value.number_value = atof(number_string);
        value->type = JSON_TYPE_NUMBER;
        free(number_string);
    } else if (strncmp(*json, "true", 4) == 0) {
        value->value.boolean_value = 1;
        value->type = JSON_TYPE_BOOLEAN;
        (*json) += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->value.boolean_value = 0;
        value->type = JSON_TYPE_BOOLEAN;
        (*json) += 5;
    } else if (strncmp(*json, "null", 4) == 0) {
        value->type = JSON_TYPE_NULL;
        (*json) += 4;
    } else {
        parse_error("Unexpected JSON value");
    }
    eat_spaces(json);
    return value;
}

json_object *parse_json_object(char **json) {
    eat_spaces(json);
    json_object *object = (json_object *)malloc(sizeof(json_object));
    object->members = (json_member *)malloc(sizeof(json_member));
    int size = 1;
    int count = 0;
    while (**json != '}') {
        char *key = NULL;
        json_value *value = NULL;
        if (count > 0) {
            eat_string(json, ",");
            eat_spaces(json);
        }
        if (**json != '\"')
            parse_error("Unexpected token in JSON object");
        char *s = *json;
        while (*s != '\"')
            ++s;
        int len = s - (*json);
        ++s;
        key = (char *)malloc(sizeof(char) * (len + 1));
        strncpy(key, *json, len);
        key[len] = '\0';
        *json = s;
        eat_spaces(json);
        eat_string(json, ":");
        eat_spaces(json);
        value = parse_json_value(json);
        ++count;
        if (count > size) {
            size *= 2;
            object->members = (json_member *)realloc(object->members, sizeof(json_member) * size);
        }
        json_member m = {key, value};
        object->members[count - 1] = m;
    }
    object->count = count;
    ++(*json);
    return object;
}

json_array *parse_json_array(char **json) {
    eat_spaces(json);
    json_array *array = (json_array *)malloc(sizeof(json_array));
    array->items = (json_value **)malloc(sizeof(json_value *));
    int size = 1;
    int count = 0;
    while (**json != ']') {
        json_value *value = NULL;
        if (count > 0) {
            eat_string(json, ",");
            eat_spaces(json);
        }
        value = parse_json_value(json);
        ++count;
        if (count > size) {
            size *= 2;
            array->items = (json_value **)realloc(array->items, sizeof(json_value *) * size);
        }
        array->items[count - 1] = value;
    }
    array->count = count;
    ++(*json);
    return array;
}

int main() {

    strcpy(json, "{ \"Name\": \"Romeo\", \"Age\": 25, \"Gender\": \"Male\", \"Hobbies\": [\"Writing Love Letters\", \"Fighting\", \"Crying like a baby\"] }");
    char *ptr = json;
    root = parse_json_value(&ptr);

    if (root->type == JSON_TYPE_OBJECT) {
        json_object *object_value = root->value.object_value;
        printf("Name: %s\n", object_value->members[0].value->value.string_value);
        printf("Age: %.2f\n", object_value->members[1].value->value.number_value);
        printf("Gender: %s\n", object_value->members[2].value->value.string_value);
        printf("Hobbies:\n");
        json_array *array_value = object_value->members[3].value->value.array_value;
        for (int i = 0; i < array_value->count; ++i) {
            printf("\t%s\n", array_value->items[i]->value.string_value);
        }
    }
    return 0;
}