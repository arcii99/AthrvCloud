//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_MSG_LEN 100

typedef enum {
    TYPE_UNKNOWN,
    TYPE_OBJECT,
    TYPE_ARRAY,
    TYPE_STRING,
    TYPE_NUMBER,
    TYPE_BOOLEAN,
    TYPE_NULL
} JsonType;

typedef struct {
    char *key;
    JsonType type;
    void *value;
} JsonItem;

typedef struct {
    JsonItem *items;
    size_t count;
} JsonObject;

typedef struct {
    JsonType type;
    void *value;
} JsonValue;

typedef struct {
    JsonValue *values;
    size_t count;
} JsonArray;

typedef struct {
    char *data;
    size_t len;
    size_t idx;
    char error_msg[ERROR_MSG_LEN];
} JsonParser;

// Forward declarations
JsonParser *new_json_parser(char *json_str);
void free_json_parser(JsonParser *parser);
bool match(JsonParser *parser, char expected);
char peek(JsonParser *parser);
char next(JsonParser *parser);
bool is_eof(JsonParser *parser);
bool is_whitespace(char ch);
void skip_whitespace(JsonParser *parser);
char *parse_string(JsonParser *parser);
JsonValue *parse_value(JsonParser *parser);
JsonArray *parse_array(JsonParser *parser);
void free_array(JsonArray *array);
JsonObject *parse_object(JsonParser *parser);
void free_object(JsonObject *object);
void free_json_value(JsonValue *value);

JsonParser *new_json_parser(char *json_str) {
    JsonParser *parser = malloc(sizeof(JsonParser));
    if (!parser) {
        return NULL;
    }

    parser->data = json_str;
    parser->len = strlen(json_str);
    parser->idx = 0;
    memset(parser->error_msg, 0, ERROR_MSG_LEN);
    return parser;
}

void free_json_parser(JsonParser *parser) {
    free(parser);
}

bool match(JsonParser *parser, char expected) {
    if (is_eof(parser)) {
        snprintf(
            parser->error_msg, ERROR_MSG_LEN,
            "Expected '%c' but found EOF at index %zd",
            expected, parser->idx - 1
        );
        return false;
    }

    if (parser->data[parser->idx] != expected) {
        snprintf(
            parser->error_msg, ERROR_MSG_LEN,
            "Expected '%c' but found '%c' at index %zd",
            expected, parser->data[parser->idx], parser->idx
        );
        return false;
    }

    parser->idx++;
    return true;
}

char peek(JsonParser *parser) {
    if (is_eof(parser)) {
        return EOF;
    }

    return parser->data[parser->idx];
}

char next(JsonParser *parser) {
    char ch = peek(parser);
    parser->idx++;
    return ch;
}

bool is_eof(JsonParser *parser) {
    return parser->idx >= parser->len;
}

bool is_whitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';
}

void skip_whitespace(JsonParser *parser) {
    while (is_whitespace(peek(parser))) {
        next(parser);
    }
}

char *parse_string(JsonParser *parser) {
    if (!match(parser, '\"')) {
        return NULL;
    }

    size_t start = parser->idx;
    char ch;
    bool escape_next = false;

    do {
        ch = next(parser);

        if (ch == '\\') {
            escape_next = true;
        } else if (!escape_next && ch != '\"') {
            escape_next = false;
        }
    } while (!is_eof(parser) && (escape_next || ch != '\"'));

    if (is_eof(parser)) {
        snprintf(
            parser->error_msg, ERROR_MSG_LEN,
            "Unterminated string at index %zd", start
        );
        return NULL;
    }

    size_t len = parser->idx - start - 1;
    char *value = malloc(sizeof(char) * (len + 1));
    if (!value) {
        return NULL;
    }

    strncpy(value, parser->data + start, len);
    value[len] = '\0';
    return value;
}

JsonValue *parse_value(JsonParser *parser) {
    skip_whitespace(parser);

    char ch = peek(parser);
    JsonValue *value = malloc(sizeof(JsonValue));
    if (!value) {
        return NULL;
    }

    if (ch == '\"') {
        value->type = TYPE_STRING;
        value->value = parse_string(parser);
    } else if (ch == '[') {
        value->type = TYPE_ARRAY;
        value->value = parse_array(parser);
    } else if (ch == '{') {
        value->type = TYPE_OBJECT;
        value->value = parse_object(parser);
    } else if (ch >= '0' && ch <= '9') {
        value->type = TYPE_NUMBER;
        // TODO: Implement parsing of numbers
        value->value = NULL;
    } else if (ch == 't') {
        value->type = TYPE_BOOLEAN;
        // TODO: Implement parsing of boolean values
        value->value = NULL;
    } else if (ch == 'f') {
        value->type = TYPE_BOOLEAN;
        // TODO: Implement parsing of boolean values
        value->value = NULL;
    } else if (ch == 'n') {
        value->type = TYPE_NULL;
        next(parser);
        value->value = NULL;
    } else {
        snprintf(
            parser->error_msg, ERROR_MSG_LEN,
            "Invalid value found at index %zd", parser->idx
        );
        free(value);
        return NULL;
    }

    if (!value->value && value->type != TYPE_NULL) {
        free(value);
        return NULL;
    }

    return value;
}

JsonArray *parse_array(JsonParser *parser) {
    if (!match(parser, '[')) {
        return NULL;
    }

    JsonArray *array = malloc(sizeof(JsonArray));
    if (!array) {
        return NULL;
    }

    skip_whitespace(parser);
    if (peek(parser) == ']') {
        array->values = NULL;
        array->count = 0;
        next(parser);
        return array;
    }

    array->values = malloc(sizeof(JsonValue));
    if (!array->values) {
        return NULL;
    }

    array->count = 1;
    array->values[0] = *parse_value(parser);

    while (match(parser, ',')) {
        array->count++;
        array->values = realloc(array->values, sizeof(JsonValue) * array->count);
        if (!array->values) {
            return NULL;
        }

        array->values[array->count - 1] = *parse_value(parser);
    }

    if (!match(parser, ']')) {
        free_array(array);
        return NULL;
    }

    return array;
}

void free_array(JsonArray *array) {
    if (!array) {
        return;
    }

    for (size_t i = 0; i < array->count; i++) {
        free_json_value(&array->values[i]);
    }

    free(array->values);
    free(array);
}

JsonObject *parse_object(JsonParser *parser) {
    if (!match(parser, '{')) {
        return NULL;
    }

    JsonObject *object = malloc(sizeof(JsonObject));
    if (!object) {
        return NULL;
    }

    skip_whitespace(parser);
    if (peek(parser) == '}') {
        object->items = NULL;
        object->count = 0;
        next(parser);
        return object;
    }

    object->items = malloc(sizeof(JsonItem));
    if (!object->items) {
        return NULL;
    }

    object->count = 1;
    object->items[0].key = parse_string(parser);
    if (!match(parser, ':')) {
        free_object(object);
        return NULL;
    }

    object->items[0].type = TYPE_UNKNOWN;
    object->items[0].value = (void *) parse_value(parser);

    while (match(parser, ',')) {
        object->count++;
        object->items = realloc(object->items, sizeof(JsonItem) * object->count);
        if (!object->items) {
            return NULL;
        }

        object->items[object->count - 1].key = parse_string(parser);
        if (!match(parser, ':')) {
            free_object(object);
            return NULL;
        }

        object->items[object->count - 1].type = TYPE_UNKNOWN;
        object->items[object->count - 1].value = (void *) parse_value(parser);
    }

    if (!match(parser, '}')) {
        free_object(object);
        return NULL;
    }

    return object;
}

void free_object(JsonObject *object) {
    if (!object) {
        return;
    }

    for (size_t i = 0; i < object->count; i++) {
        free(object->items[i].key);
        free_json_value(object->items[i].value);
    }

    free(object->items);
    free(object);
}

void free_json_value(JsonValue *value) {
    if (!value) {
        return;
    }

    if (value->type == TYPE_STRING) {
        free(value->value);
    } else if (value->type == TYPE_ARRAY) {
        free_array(value->value);
    } else if (value->type == TYPE_OBJECT) {
        free_object(value->value);
    }

    free(value);
}

int main() {
    JsonParser *parser = new_json_parser("{\"foo\":\"bar\",\"baz\":42,\"qux\":true,\"quux\":[1,2,3],\"corge\":{\"grault\":1.23,\"garply\":null}}");
    if (!parser) {
        fprintf(stderr, "Failed to create JSON parser");
        return 1;
    }

    JsonObject *object = parse_object(parser);
    if (!object) {
        fprintf(stderr, "Failed to parse JSON: %s", parser->error_msg);
        free_json_parser(parser);
        return 1;
    }

    printf("Parsed JSON:\n");
    for (size_t i = 0; i < object->count; i++) {
        JsonItem item = object->items[i];
        printf("  %s: ", item.key);

        if (item.type == TYPE_STRING) {
            printf("\"%s\"", (char *) item.value);
        } else if (item.type == TYPE_NUMBER) {
            printf("%f", *(double *) item.value);
        } else if (item.type == TYPE_BOOLEAN) {
            printf("%s", *(bool *) item.value ? "true" : "false");
        } else if (item.type == TYPE_ARRAY) {
            JsonArray *array = (JsonArray *) item.value;
            printf("[");
            for (size_t j = 0; j < array->count; j++) {
                JsonValue value = array->values[j];
                if (value.type == TYPE_STRING) {
                    printf("\"%s\"", (char *) value.value);
                } else if (value.type == TYPE_NUMBER) {
                    printf("%f", *(double *) value.value);
                } else if (value.type == TYPE_BOOLEAN) {
                    printf("%s", *(bool *) value.value ? "true" : "false");
                }

                if (j < array->count - 1) {
                    printf(", ");
                }
            }
            printf("]");
        } else if (item.type == TYPE_OBJECT) {
            JsonObject *nested_object = (JsonObject *) item.value;
            printf("{\n");
            for (size_t j = 0; j < nested_object->count; j++) {
                JsonItem nested_item = nested_object->items[j];
                printf("    %s: ", nested_item.key);

                if (nested_item.type == TYPE_STRING) {
                    printf("\"%s\"", (char *) nested_item.value);
                } else if (nested_item.type == TYPE_NUMBER) {
                    printf("%f", *(double *) nested_item.value);
                } else if (nested_item.type == TYPE_BOOLEAN) {
                    printf("%s", *(bool *) nested_item.value ? "true" : "false");
                } else if (nested_item.type == TYPE_ARRAY) {
                    JsonArray *array = (JsonArray *) nested_item.value;
                    printf("[");
                    for (size_t k = 0; k < array->count; k++) {
                        JsonValue value = array->values[k];
                        if (value.type == TYPE_STRING) {
                            printf("\"%s\"", (char *) value.value);
                        } else if (value.type == TYPE_NUMBER) {
                            printf("%f", *(double *) value.value);
                        } else if (value.type == TYPE_BOOLEAN) {
                            printf("%s", *(bool *) value.value ? "true" : "false");
                        }

                        if (k < array->count - 1) {
                            printf(", ");
                        }
                    }
                    printf("]");
                }

                printf("\n");
            }
            printf("  }");
        } else if (item.type == TYPE_NULL) {
            printf("null");
        }

        printf("\n");
    }

    free_object(object);
    free_json_parser(parser);
    return 0;
}