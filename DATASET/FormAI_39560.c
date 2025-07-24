//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
// Welcome to our JSON Parser example program!
// This program reads a JSON file and creates a C struct to hold the data.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_TYPE_NULL,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NUMBER,
    JSON_TYPE_STRING,
    JSON_TYPE_ARRAY,
    JSON_TYPE_OBJECT
} json_type;

typedef struct {
    json_type type;
    union {
        int boolean_value;
        double number_value;
        char *string_value;
        struct json_value *array_items;
        struct json_pair *object_items;
    } value;
} json_value;

typedef struct json_pair {
    char *key;
    struct json_value *value;
    struct json_pair *next;
} json_pair;

json_value *parse_value(char **p);

json_value *parse_null(char **p) {
    if (strncmp(*p, "null", 4) == 0) {
        *p += 4;
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_TYPE_NULL;
        return value;
    }
    return NULL;
}

json_value *parse_boolean(char **p) {
    if (strncmp(*p, "true", 4) == 0) {
        *p += 4;
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_TYPE_BOOLEAN;
        value->value.boolean_value = 1;
        return value;
    } else if (strncmp(*p, "false", 5) == 0) {
        *p += 5;
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_TYPE_BOOLEAN;
        value->value.boolean_value = 0;
        return value;
    }
    return NULL;
}

json_value *parse_number(char **p) {
    char *end;
    double value = strtod(*p, &end);
    if (*p != end) {
        *p = end;
        json_value *json_value = malloc(sizeof(json_value));
        json_value->type = JSON_TYPE_NUMBER;
        json_value->value.number_value = value;
        return json_value;
    }
    return NULL;
}

json_value *parse_string(char **p) {
    if (**p == '"') {
        char *end = *p + 1;
        while (*end != '"') {
            if (*end == '\\') {
                ++end;
            }
            ++end;
        }
        json_value *json_value = malloc(sizeof(json_value));
        json_value->type = JSON_TYPE_STRING;
        json_value->value.string_value = strndup(*p + 1, end - *p - 1);
        *p = end + 1;
        return json_value;
    }
    return NULL;
}

json_value *parse_array(char **p) {
    if (**p == '[') {
        json_value *items = NULL;
        json_value *item = parse_value(p);
        while (item != NULL) {
            json_value *temp = items;
            items = item;
            item->value.array_items = temp;
            item = parse_value(p);
        }
        if (**p == ']') {
            ++*p;
            json_value *json_value = malloc(sizeof(json_value));
            json_value->type = JSON_TYPE_ARRAY;
            json_value->value.array_items = items;
            return json_value;
        }
    }
    return NULL;
}

json_pair *parse_pair(char **p) {
    json_value *value = NULL;
    char *key = parse_string(p)->value.string_value;
    if (**p == ':') {
        ++*p;
        value = parse_value(p);
        if (key != NULL && value != NULL) {
            json_pair *pair = malloc(sizeof(json_pair));
            pair->key = key;
            pair->value = value;
            pair->next = NULL;
            return pair;
        }
    }
    return NULL;
}

json_value *parse_object(char **p) {
    if (**p == '{') {
        json_pair *pairs = NULL;
        json_pair *pair = parse_pair(p);
        while (pair != NULL) {
            json_pair *temp = pairs;
            pairs = pair;
            pair->next = temp;
            pair = parse_pair(p);
        }
        if (**p == '}') {
            ++*p;
            json_value *json_value = malloc(sizeof(json_value));
            json_value->type = JSON_TYPE_OBJECT;
            json_value->value.object_items = pairs;
            return json_value;
        }
    }
    return NULL;
}

json_value *parse_value(char **p) {
    json_value *value = NULL;
    while (**p != '\0' && isspace(**p)) {
        ++*p;
    }
    if ((value = parse_null(p)) != NULL ||
        (value = parse_boolean(p)) != NULL ||
        (value = parse_number(p)) != NULL ||
        (value = parse_string(p)) != NULL ||
        (value = parse_array(p)) != NULL ||
        (value = parse_object(p)) != NULL) {
        return value;
    }
    return NULL;
}

void print_json_value(json_value *value) {
    if (value == NULL) {
        printf("NULL\n");
        return;
    }
    switch (value->type) {
        case JSON_TYPE_NULL:
            printf("null");
            break;
        case JSON_TYPE_BOOLEAN:
            printf(value->value.boolean_value ? "true" : "false");
            break;
        case JSON_TYPE_NUMBER:
            printf("%lf", value->value.number_value);
            break;
        case JSON_TYPE_STRING:
            printf("\"%s\"", value->value.string_value);
            break;
        case JSON_TYPE_ARRAY:
            {
                printf("[");
                json_value *items = value->value.array_items;
                while (items != NULL) {
                    print_json_value(items);
                    items = items->value.array_items;
                    if (items != NULL) {
                        printf(", ");
                    }
                }
                printf("]");
            }
            break;
        case JSON_TYPE_OBJECT:
            {
                printf("{");
                json_pair *pairs = value->value.object_items;
                while (pairs != NULL) {
                    printf("\"%s\": ", pairs->key);
                    print_json_value(pairs->value);
                    pairs = pairs->next;
                    if (pairs != NULL) {
                        printf(", ");
                    }
                }
                printf("}");
            }
            break;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <json_file>\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }
    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    char *input_buffer = malloc(input_file_size);
    fread(input_buffer, sizeof(char), input_file_size, input_file);
    fclose(input_file);
    char *input = input_buffer;
    json_value *json_value = parse_value(&input);
    if (json_value == NULL) {
        printf("Error: invalid json file %s\n", argv[1]);
        return 1;
    }
    print_json_value(json_value);
    free(input_buffer);
    return 0;
}