//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUF 1024

typedef enum {
    JSON_NULL,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN
} json_type_t;

typedef struct json_value_s json_value_t;
typedef struct json_element_s json_element_t;
typedef struct json_object_s json_object_t;
typedef struct json_array_s json_array_t;

struct json_value_s {
    json_type_t type;
    union {
        json_element_t *element;
        json_object_t *object;
        json_array_t *array;
        char *string;
        double number;
        int boolean;
    } data;
};

struct json_element_s {
    char *key;
    json_value_t *value;
    json_element_t *next;
};

struct json_object_s {
    json_element_t *elements;
};

struct json_array_s {
    json_value_t **values;
    int length;
};

void skip_whitespace(char **json)
{
    while (**json && isspace((unsigned char) **json)) {
        ++*json;
    }
}

json_value_t *parse_object(char **json);
json_value_t *parse_array(char **json);
json_value_t *parse_string(char **json);
json_value_t *parse_number(char **json);
json_value_t *parse_boolean(char **json);
json_value_t *parse_null(char **json);

json_value_t *parse_value(char **json)
{
    skip_whitespace(json);

    switch (**json) {
        case '{':
            return parse_object(json);
        case '[':
            return parse_array(json);
        case '\"':
            return parse_string(json);
        case '-':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return parse_number(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case 'n':
            return parse_null(json);
    }

    return NULL;
}

json_value_t *parse_object(char **json)
{
    ++*json;

    json_value_t *object = malloc(sizeof(json_value_t));
    object->type = JSON_OBJECT;
    object->data.object = malloc(sizeof(json_object_t));
    object->data.object->elements = NULL;

    skip_whitespace(json);

    if (**json == '}') {
        ++*json;
        return object;
    }

    while (1) {
        skip_whitespace(json);

        if (**json != '\"') {
            fprintf(stderr, "Expected object key, got %c\n", **json);
            exit(1);
        }

        char *key = parse_string(json)->data.string;

        skip_whitespace(json);

        if (**json != ':') {
            fprintf(stderr, "Expected object key/value separator, got %c\n", **json);
            exit(1);
        }

        ++*json;

        json_element_t *element = malloc(sizeof(json_element_t));
        element->key = key;
        element->value = parse_value(json);
        element->next = object->data.object->elements;
        object->data.object->elements = element;

        skip_whitespace(json);

        if (**json == '}') {
            ++*json;
            return object;
        }

        if (**json != ',') {
            fprintf(stderr, "Expected object element separator, got %c\n", **json);
            exit(1);
        }

        ++*json;
    }
}

json_value_t *parse_array(char **json)
{
    ++*json;

    json_value_t *array = malloc(sizeof(json_value_t));
    array->type = JSON_ARRAY;
    array->data.array = malloc(sizeof(json_array_t));
    array->data.array->values = NULL;
    array->data.array->length = 0;

    skip_whitespace(json);

    if (**json == ']') {
        ++*json;
        return array;
    }

    while (1) {
        json_value_t *value = parse_value(json);

        array->data.array->values = realloc(array->data.array->values, sizeof(json_value_t *) * (array->data.array->length + 1));
        array->data.array->values[array->data.array->length++] = value;

        skip_whitespace(json);

        if (**json == ']') {
            ++*json;
            return array;
        }

        if (**json != ',') {
            fprintf(stderr, "Expected array element separator, got %c\n", **json);
            exit(1);
        }

        ++*json;
    }
}

json_value_t *parse_string(char **json)
{
    char buf[MAX_BUF];
    char *ptr = buf;

    ++*json;

    while (**json && **json != '\"') {
        if (**json == '\\') {
            ++*json;

            switch (**json) {
                case '\"':
                    *ptr++ = '\"';
                    ++*json;
                    break;
                case '\\':
                    *ptr++ = '\\';
                    ++*json;
                    break;
                case '/':
                    *ptr++ = '/';
                    ++*json;
                    break;
                case 'b':
                    *ptr++ = '\b';
                    ++*json;
                    break;
                case 'f':
                    *ptr++ = '\f';
                    ++*json;
                    break;
                case 'n':
                    *ptr++ = '\n';
                    ++*json;
                    break;
                case 'r':
                    *ptr++ = '\r';
                    ++*json;
                    break;
                case 't':
                    *ptr++ = '\t';
                    ++*json;
                    break;
                default:
                    fprintf(stderr, "Unknown escape character %c\n", **json);
                    exit(1);
                    break;
            }
        } else {
            *ptr++ = **json;
            ++*json;
        }
    }

    *ptr = '\0';

    if (**json != '\"') {
        fprintf(stderr, "Expected end of string, got %c\n", **json);
        exit(1);
    }

    ++*json;

    json_value_t *string = malloc(sizeof(json_value_t));
    string->type = JSON_STRING;
    string->data.string = strdup(buf);

    return string;
}

json_value_t *parse_number(char **json)
{
    char buf[MAX_BUF];
    char *ptr = buf;

    while (**json && (**json == '-' || isdigit((unsigned char) **json))) {
        *ptr++ = **json;
        ++*json;
    }

    *ptr = '\0';

    json_value_t *number = malloc(sizeof(json_value_t));
    number->type = JSON_NUMBER;
    number->data.number = strtod(buf, NULL);

    return number;
}

json_value_t *parse_boolean(char **json)
{
    if (**json == 't') {
        if (strncmp(*json, "true", 4) != 0) {
            fprintf(stderr, "Invalid boolean value\n");
            exit(1);
        }

        *json += 4;

        json_value_t *boolean = malloc(sizeof(json_value_t));
        boolean->type = JSON_BOOLEAN;
        boolean->data.boolean = 1;

        return boolean;
    } else {
        if (strncmp(*json, "false", 5) != 0) {
            fprintf(stderr, "Invalid boolean value\n");
            exit(1);
        }

        *json += 5;

        json_value_t *boolean = malloc(sizeof(json_value_t));
        boolean->type = JSON_BOOLEAN;
        boolean->data.boolean = 0;

        return boolean;
    }
}

json_value_t *parse_null(char **json)
{
    if (strncmp(*json, "null", 4) != 0) {
        fprintf(stderr, "Invalid null value\n");
        exit(1);
    }

    *json += 4;

    json_value_t *null = malloc(sizeof(json_value_t));
    null->type = JSON_NULL;

    return null;
}

int main()
{
    char json[] = "{\"name\": \"John Doe\", \"age\": 30, \"isMarried\": false, \"phoneNumbers\": [\"+1 555-555-5555\", \"+1 555-555-5556\"]}";

    json_value_t *value = parse_value(&json);
    printf("type: %d\n", value->type);

    json_element_t *element = value->data.object->elements;
    while (element) {
        printf("key: %s\n", element->key);

        switch (element->value->type) {
            case JSON_NULL:
                printf("value: null\n");
                break;
            case JSON_OBJECT:
                printf("value: object\n");
                break;
            case JSON_ARRAY:
                printf("value: array\n");
                break;
            case JSON_STRING:
                printf("value: %s\n", element->value->data.string);
                break;
            case JSON_NUMBER:
                printf("value: %f\n", element->value->data.number);
                break;
            case JSON_BOOLEAN:
                printf("value: %s\n", element->value->data.boolean ? "true" : "false");
                break;
        }

        element = element->next;
    }

    return 0;
}