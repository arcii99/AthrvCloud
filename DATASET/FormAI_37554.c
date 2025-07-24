//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JSON_SIZE 1000

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL,
    JSON_OBJECT,
    JSON_ARRAY
} json_type;

typedef struct json_value {
    json_type type;
    union {
        char *string_value;
        double number_value;
        bool bool_value;
        struct json_object *object_value;
        struct json_array *array_value;
    } data;
} json_value;

typedef struct json_pair {
    char *key;
    struct json_value *value;
} json_pair;

typedef struct json_object {
    struct json_pair **pairs;
    int num_pairs;
} json_object;

typedef struct json_array {
    struct json_value **values;
    int num_values;
} json_array;

char *read_file(char *file_path) {
    FILE *fp;
    char *json_string = malloc(MAX_JSON_SIZE);

    fp = fopen(file_path, "r");
    if (fp == NULL) {
        perror("Unable to open file");
        exit(1);
    }

    fgets(json_string, MAX_JSON_SIZE, fp);
    fclose(fp);

    return json_string;
}

json_value *parse_value(char *json_string, int *i);

json_object *parse_object(char *json_string, int *i) {
    json_object *object = malloc(sizeof(json_object));
    object->num_pairs = 0;
    object->pairs = NULL;

    char c = json_string[*i];
    (*i)++; // advance past opening brace

    if (c != '{') {
        fprintf(stderr, "Expected opening brace\n");
        exit(1);
    }

    while (true) {
        c = json_string[*i];

        if (c == '}') {
            (*i)++; // advance past closing brace
            break;
        }

        if (c != '"') {
            fprintf(stderr, "Expected object key to start with double quotes\n");
            exit(1);
        }

        (*i)++; // advance past opening double quote
        char *key_start = json_string + *i;
        int key_len = 0;
        while (json_string[*i] != '"') {
            (*i)++;
            key_len++;
        }
        char *key = strndup(key_start, key_len);
        (*i)++; // advance past closing double quote

        c = json_string[*i];
        if (c != ':') {
            fprintf(stderr, "Expected colon after object key\n");
            exit(1);
        }

        (*i)++; // advance past colon
        json_value *value = parse_value(json_string, i);

        json_pair *pair = malloc(sizeof(json_pair));
        pair->key = key;
        pair->value = value;

        object->num_pairs++;
        object->pairs = realloc(object->pairs, sizeof(json_pair*) * object->num_pairs);
        object->pairs[object->num_pairs - 1] = pair;

        if (json_string[*i] == ',') {
            (*i)++; // advance past comma
        }
    }

    return object;
}

json_array *parse_array(char *json_string, int *i) {
    json_array *array = malloc(sizeof(json_array));
    array->num_values = 0;
    array->values = NULL;

    char c = json_string[*i];
    (*i)++; // advance past opening bracket

    if (c != '[') {
        fprintf(stderr, "Expected opening bracket\n");
        exit(1);
    }

    while (true) {
        if (json_string[*i] == ']') {
            (*i)++; // advance past closing bracket
            break;
        }

        json_value *value = parse_value(json_string, i);

        array->num_values++;
        array->values = realloc(array->values, sizeof(json_value*) * array->num_values);
        array->values[array->num_values - 1] = value;

        if (json_string[*i] == ',') {
            (*i)++; // advance past comma
        }
    }

    return array;
}

json_value *parse_value(char *json_string, int *i) {
    char c = json_string[*i];

    if (c == '{') {
        return (json_value*) parse_object(json_string, i);
    } else if (c == '[') {
        return (json_value*) parse_array(json_string, i);
    } else if (c == '"') {
        (*i)++; // advance past opening double quote
        char *string_start = json_string + *i;
        int string_len = 0;
        while (json_string[*i] != '"') {
            (*i)++;
            string_len++;
        }
        char *string = strndup(string_start, string_len);
        (*i)++; // advance past closing double quote

        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_STRING;
        value->data.string_value = string;
        return value;
    } else if (c == 't' || c == 'f') {
        char *bool_str = json_string + *i;
        if (strncmp(bool_str, "true", 4) == 0) {
            (*i) += 4;
            json_value *value = malloc(sizeof(json_value));
            value->type = JSON_BOOL;
            value->data.bool_value = true;
            return value;
        } else if (strncmp(bool_str, "false", 5) == 0) {
            (*i) += 5;
            json_value *value = malloc(sizeof(json_value));
            value->type = JSON_BOOL;
            value->data.bool_value = false;
            return value;
        } else {
            fprintf(stderr, "Invalid boolean value\n");
            exit(1);
        }
    } else if (c == 'n') {
        (*i) += 4; // advance past "null"
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_NULL;
        return value;
    } else if (c >= '0' && c <= '9' || c == '-') {
        char *num_str = json_string + *i;
        int num_len = 0;
        while (json_string[*i] >= '0' && json_string[*i] <= '9' ||
               json_string[*i] == '.' || json_string[*i] == '-') {
            (*i)++;
            num_len++;
        }
        char num_str_trimmed[num_len + 1];
        strncpy(num_str_trimmed, num_str, num_len);
        num_str_trimmed[num_len] = '\0';

        double number = atof(num_str_trimmed);
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_NUMBER;
        value->data.number_value = number;
        return value;
    } else {
        fprintf(stderr, "Unexpected character: '%c'\n", c);
        exit(1);
    }
}

void print_json_object(json_object *object) {
    printf("{");
    for (int i = 0; i < object->num_pairs; i++) {
        printf("\"%s\": ", object->pairs[i]->key);
        print_json_value(object->pairs[i]->value);

        if (i < object->num_pairs - 1) {
            printf(", ");
        }
    }
    printf("}");
}

void print_json_array(json_array *array) {
    printf("[");
    for (int i = 0; i < array->num_values; i++) {
        print_json_value(array->values[i]);

        if (i < array->num_values - 1) {
            printf(", ");
        }
    }
    printf("]");
}

void print_json_value(json_value *value) {
    switch (value->type) {
        case JSON_STRING:
            printf("\"%s\"", value->data.string_value);
            break;
        case JSON_NUMBER:
            printf("%f", value->data.number_value);
            break;
        case JSON_BOOL:
            printf("%s", value->data.bool_value ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null");
            break;
        case JSON_OBJECT:
            print_json_object(value->data.object_value);
            break;
        case JSON_ARRAY:
            print_json_array(value->data.array_value);
            break;
    }
}

json_value *parse_json(char *json_string) {
    int i = 0;
    return parse_value(json_string, &i);
}

int main() {
    char *json_string = read_file("example.json");
    json_value *root = parse_json(json_string);
    print_json_value(root);
    printf("\n");
    return 0;
}