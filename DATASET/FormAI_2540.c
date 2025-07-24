//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 32
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 64

enum JsonType {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
};

struct JsonPair {
    char key[MAX_KEY_SIZE];
    enum JsonType type;
    union {
        char string_value[MAX_VALUE_SIZE];
        double number_value;
        int boolean_value;
    } value;
};

struct JsonObject {
    struct JsonPair pairs[MAX_STACK_SIZE];
    int count;
};

struct JsonParser {
    char *json;
    int index;
    struct JsonObject stack[MAX_STACK_SIZE];
    int top;
};

void skip_whitespace(struct JsonParser *parser) {
    while (isspace(parser->json[parser->index])) {
        parser->index++;
    }
}

char *parse_string(struct JsonParser *parser) {
    char buffer[MAX_VALUE_SIZE];
    int i = 0;
    parser->index++; // skip the opening quote
    while (parser->json[parser->index] != '"' && i < MAX_VALUE_SIZE - 1) {
        if (parser->json[parser->index] == '\\') {
            parser->index++;
            switch (parser->json[parser->index]) {
                case '"':
                    buffer[i] = '"';
                    break;
                case '\\':
                    buffer[i] = '\\';
                    break;
                case '/':
                    buffer[i] = '/';
                    break;
                case 'b':
                    buffer[i] = '\b';
                    break;
                case 'f':
                    buffer[i] = '\f';
                    break;
                case 'n':
                    buffer[i] = '\n';
                    break;
                case 'r':
                    buffer[i] = '\r';
                    break;
                case 't':
                    buffer[i] = '\t';
                    break;
                default:
                    buffer[i] = parser->json[parser->index];
                    break;
            }
        } else {
            buffer[i] = parser->json[parser->index];
        }
        i++;
        parser->index++;
    }
    buffer[i] = '\0';
    parser->index++; // skip the closing quote
    return strdup(buffer);
}

double parse_number(struct JsonParser *parser) {
    char buffer[MAX_VALUE_SIZE];
    int i = 0;
    while (isdigit(parser->json[parser->index]) || parser->json[parser->index] == '.') {
        buffer[i++] = parser->json[parser->index++];
    }
    buffer[i] = '\0';
    return atof(buffer);
}

void parse_pair(struct JsonParser *parser, struct JsonPair *pair) {
    pair->type = JSON_STRING;
    strcpy(pair->key, parse_string(parser));
    skip_whitespace(parser);
    parser->index++; // skip the colon
    skip_whitespace(parser);
    switch (parser->json[parser->index]) {
        case '[': {
            pair->type = JSON_ARRAY;
            parser->index++;
            break;
        }
        case '{': {
            pair->type = JSON_OBJECT;
            parser->index++;
            break;
        }
        case '"': {
            pair->type = JSON_STRING;
            strcpy(pair->value.string_value, parse_string(parser));
            break;
        }
        case 't': {
            pair->type = JSON_BOOLEAN;
            pair->value.boolean_value = 1;
            parser->index += 4;
            break;
        }
        case 'f': {
            pair->type = JSON_BOOLEAN;
            pair->value.boolean_value = 0;
            parser->index += 5;
            break;
        }
        case 'n': {
            pair->type = JSON_NULL;
            parser->index += 4;
            break;
        }
        default: {
            if (isdigit(parser->json[parser->index]) || parser->json[parser->index] == '-') {
                pair->type = JSON_NUMBER;
                pair->value.number_value = parse_number(parser);
            }
            break;
        }
    }
}

void push_object(struct JsonParser *parser) {
    parser->top++;
    parser->stack[parser->top].count = 0;
}

void pop_object(struct JsonParser *parser) {
    parser->top--;
}

void push_pair(struct JsonParser *parser, struct JsonPair *pair) {
    parser->stack[parser->top].pairs[parser->stack[parser->top].count++] = *pair;
}

struct JsonObject *parse_json(char *json) {
    struct JsonParser parser = {
        .json = json,
        .index = 0,
        .top = -1
    };
    push_object(&parser);
    skip_whitespace(&parser);
    if (parser.json[parser.index] == '{') {
        parser.index++;
        skip_whitespace(&parser);
        if (parser.json[parser.index] == '}') {
            parser.index++;
            return &parser.stack[0];
        }
        while (1) {
            skip_whitespace(&parser);
            struct JsonPair pair;
            parse_pair(&parser, &pair);
            push_pair(&parser, &pair);
            skip_whitespace(&parser);
            if (parser.json[parser.index] == ',') {
                parser.index++;
                continue;
            } else if (parser.json[parser.index] == '}') {
                parser.index++;
                break;
            } else {
                break;
            }
        }
    }
    return NULL;
}

int main() {
    char *json = "{\"name\": \"John\", \"age\": 30, \"employed\": true, \"salary\": null}";
    struct JsonObject *object = parse_json(json);
    if (object) {
        for (int i = 0; i < object->count; i++) {
            struct JsonPair *pair = &object->pairs[i];
            printf("%s: ", pair->key);
            switch (pair->type) {
                case JSON_OBJECT:
                    printf("JSON_OBJECT\n");
                    break;
                case JSON_ARRAY:
                    printf("JSON_ARRAY\n");
                    break;
                case JSON_STRING:
                    printf("JSON_STRING: %s\n", pair->value.string_value);
                    break;
                case JSON_NUMBER:
                    printf("JSON_NUMBER: %f\n", pair->value.number_value);
                    break;
                case JSON_BOOLEAN:
                    printf("JSON_BOOLEAN: %s\n", pair->value.boolean_value ? "true" : "false");
                    break;
                case JSON_NULL:
                    printf("JSON_NULL\n");
                    break;
            }
        }
    } else {
        printf("Failed to parse JSON!\n");
    }
    return 0;
}