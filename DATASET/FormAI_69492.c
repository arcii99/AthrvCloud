//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_JSON_DEPTH 10

typedef enum {
    JSON_TOKEN_EMPTY,
    JSON_TOKEN_STRING,
    JSON_TOKEN_NUMBER,
    JSON_TOKEN_OBJECT_START,
    JSON_TOKEN_OBJECT_END,
    JSON_TOKEN_ARRAY_START,
    JSON_TOKEN_ARRAY_END,
    JSON_TOKEN_TRUE,
    JSON_TOKEN_FALSE,
    JSON_TOKEN_NULL,
    JSON_TOKEN_COLON,
    JSON_TOKEN_COMMA
} json_token_t;

typedef struct {
    json_token_t type;
    char content[MAX_STRING_LENGTH];
    int depth;
} json_token;

json_token tokens[MAX_STRING_LENGTH];
int token_count = 0;

void parse_json(char *json_string);
void parse_object(int depth, char *json);
void parse_array(int depth, char *json);
void parse_value(int depth, char *json);
void add_token(json_token_t type, char *content, int depth);

int main() {
    char json_string[] = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    parse_json(json_string);

    for (int i = 0; i < token_count; i++) {
        printf("Type: %d, Content: %s, Depth: %d\n", tokens[i].type, tokens[i].content, tokens[i].depth);
    }

    return 0;
}

void parse_json(char *json_string) {
    int current_depth = 0;
    char *current_json = json_string;

    while (*current_json != '\0') {
        switch (*current_json) {
            case '{':
                add_token(JSON_TOKEN_OBJECT_START, NULL, current_depth);
                current_depth++;
                break;
            case '}':
                add_token(JSON_TOKEN_OBJECT_END, NULL, current_depth);
                current_depth--;
                break;
            case '[':
                add_token(JSON_TOKEN_ARRAY_START, NULL, current_depth);
                current_depth++;
                break;
            case ']':
                add_token(JSON_TOKEN_ARRAY_END, NULL, current_depth);
                current_depth--;
                break;
            case ':':
                add_token(JSON_TOKEN_COLON, NULL, current_depth);
                break;
            case ',':
                add_token(JSON_TOKEN_COMMA, NULL, current_depth);
                break;
            default:
                parse_value(current_depth, current_json);
                break;
        }

        current_json++;
    }
}

void parse_object(int depth, char *json) {
    int object_depth = 0;
    char *current_object = json;

    while (*current_object != '\0') {
        switch (*current_object) {
            case '{':
                if (object_depth == 0) {
                    add_token(JSON_TOKEN_OBJECT_START, NULL, depth);
                }

                object_depth++;
                break;
            case '}':
                object_depth--;

                if (object_depth == 0) {
                    add_token(JSON_TOKEN_OBJECT_END, NULL, depth);
                    return;
                }

                break;
            case ':':
                add_token(JSON_TOKEN_COLON, NULL, depth + object_depth);
                break;
            case ',':
                add_token(JSON_TOKEN_COMMA, NULL, depth + object_depth);
                break;
            case '"':
                char *string_start = ++current_object;
                char *string_end = strchr(string_start, '"');

                if (string_end == NULL) {
                    fprintf(stderr, "Error: Unterminated string literal\n");
                    exit(1);
                }

                int string_length = string_end - string_start;

                if (string_length >= MAX_STRING_LENGTH) {
                    fprintf(stderr, "Error: String too long\n");
                    exit(1);
                }

                char *string = malloc(string_length * sizeof(char));
                strncpy(string, string_start, string_length);
                add_token(JSON_TOKEN_STRING, string, depth + object_depth);
                current_object = string_end;
                break;
            case 't':
                add_token(JSON_TOKEN_TRUE, "true", depth + object_depth);
                current_object += 3;
                break;
            case 'f':
                add_token(JSON_TOKEN_FALSE, "false", depth + object_depth);
                current_object += 4;
                break;
            case 'n':
                add_token(JSON_TOKEN_NULL, "null", depth + object_depth);
                current_object += 3;
                break;
            default:
                char *number_start = current_object;
                char *number_end;

                while (*current_object != ',' && *current_object != ']' && *current_object != '}') {
                    current_object++;
                }

                number_end = current_object;

                int number_length = number_end - number_start;
                char *number = malloc(number_length * sizeof(char));
                strncpy(number, number_start, number_length);
                add_token(JSON_TOKEN_NUMBER, number, depth + object_depth);
        }

        current_object++;
    }

    fprintf(stderr, "Error: Unterminated object\n");
    exit(1);
}

void parse_array(int depth, char *json) {
    int array_depth = 0;
    char *current_array = json;

    while (*current_array != '\0') {
        switch (*current_array) {
            case '[':
                if (array_depth == 0) {
                    add_token(JSON_TOKEN_ARRAY_START, NULL, depth);
                }

                array_depth++;
                break;
            case ']':
                array_depth--;

                if (array_depth == 0) {
                    add_token(JSON_TOKEN_ARRAY_END, NULL, depth);
                    return;
                }

                break;
            case ',':
                add_token(JSON_TOKEN_COMMA, NULL, depth + array_depth);
                break;
            default:
                parse_value(depth + array_depth, current_array);
                break;
        }

        current_array++;
    }

    fprintf(stderr, "Error: Unterminated array\n");
    exit(1);
}

void parse_value(int depth, char *json) {
    if (*json == '{') {
        parse_object(depth, json);
    } else if (*json == '[') {
        parse_array(depth, json);
    } else if (*json == '"') {
        char *string_start = ++json;
        char *string_end = strchr(string_start, '"');

        if (string_end == NULL) {
            fprintf(stderr, "Error: Unterminated string literal\n");
            exit(1);
        }

        int string_length = string_end - string_start;

        if (string_length >= MAX_STRING_LENGTH) {
            fprintf(stderr, "Error: String too long\n");
            exit(1);
        }

        char *string = malloc(string_length * sizeof(char));
        strncpy(string, string_start, string_length);
        add_token(JSON_TOKEN_STRING, string, depth);
        json = string_end;
    } else if (*json == 't') {
        add_token(JSON_TOKEN_TRUE, "true", depth);
        json += 3;
    } else if (*json == 'f') {
        add_token(JSON_TOKEN_FALSE, "false", depth);
        json += 4;
    } else if (*json == 'n') {
        add_token(JSON_TOKEN_NULL, "null", depth);
        json += 3;
    } else {
        char *number_start = json;
        char *number_end;

        while (*json != ',' && *json != ']' && *json != '}') {
            json++;
        }

        number_end = json;

        int number_length = number_end - number_start;
        char *number = malloc(number_length * sizeof(char));
        strncpy(number, number_start, number_length);
        add_token(JSON_TOKEN_NUMBER, number, depth);
    }
}

void add_token(json_token_t type, char *content, int depth) {
    json_token token = {type, "", depth};

    if (content != NULL) {
        strncpy(token.content, content, MAX_STRING_LENGTH);
    }

    tokens[token_count++] = token;
}