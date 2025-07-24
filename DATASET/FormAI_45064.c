//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL,
    JSON_OBJECT_START,
    JSON_OBJECT_END,
    JSON_ARRAY_START,
    JSON_ARRAY_END,
    JSON_COLON,
    JSON_COMMA
} JsonToken;

typedef struct {
    JsonToken token;
    int start_index;
    int end_index;
} JsonTokenInfo;

typedef struct {
    char *json_string;
    int curr_index;
} JsonParserState;

char *read_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening file %s", filename);
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    char *buffer = (char *)malloc(size+1);
    fseek(f, 0, SEEK_SET);
    fread(buffer, 1, size, f);
    fclose(f);
    buffer[size] = '\0';
    return buffer;
}

JsonToken next_token(char *json, int start, int end, int *next_pos) {
    if (start >= end) {
        *next_pos = start;
        return JSON_NULL;
    }
    switch (json[start]) {
        case '"':
            return JSON_STRING;
        case '{':
            return JSON_OBJECT_START;
        case '}':
            return JSON_OBJECT_END;
        case '[':
            return JSON_ARRAY_START;
        case ']':
            return JSON_ARRAY_END;
        case ':':
            return JSON_COLON;
        case ',':
            return JSON_COMMA;
        default:
            // check if its a number or boolean
            int pos = start;
            bool is_float = false;
            while (pos < end && json[pos] != ',' && json[pos] != '}' && json[pos] != ']') {
                if (json[pos] == '.') {
                    is_float = true;
                } else if (json[pos] == 'e' || json[pos] == 'E') {
                    // e/E means its a float
                    is_float = true;
                    pos++;
                    if (pos < end && (json[pos] == '+' || json[pos] == '-')) {
                        pos++;
                    }
                    while (pos < end && isdigit(json[pos])) {
                        pos++;
                    }
                    break;
                } else if (!isdigit(json[pos]) && !(is_float && json[pos] == '-')) {
                    // not a number or boolean
                    break;
                }
                pos++;
            }
            *next_pos = pos;
            if (is_float || strchr(json+start, '.')) {
                return JSON_NUMBER;
            } else {
                char *str = strndup(json+start, pos-start);
                if (strcmp(str, "true") == 0 || strcmp(str, "false") == 0) {
                    return JSON_BOOL;
                } else if (strcmp(str, "null") == 0) {
                    return JSON_NULL;
                } else {
                    return JSON_NUMBER;
                }
            }
    }
}

JsonTokenInfo *next_token_info(JsonParserState *state) {
    char *json = state->json_string;
    int start = state->curr_index;
    int end = strlen(json);
    JsonToken token = next_token(json, start, end, &state->curr_index);
    if (token == JSON_NULL) {
        return NULL;
    }
    JsonTokenInfo *token_info = (JsonTokenInfo *)malloc(sizeof(JsonTokenInfo));
    token_info->token = token;
    token_info->start_index = start;
    token_info->end_index = state->curr_index-1;
    return token_info;
}

void free_token_info(JsonTokenInfo *token_info) {
    if (token_info != NULL) {
        free(token_info);
    }
}

void skip_whitespace(JsonParserState *state) {
    char *json = state->json_string;
    int i = state->curr_index;
    while (i < strlen(json)) {
        char c = json[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
            i++;
        } else {
            break;
        }
    }
    state->curr_index = i;
}

void free_parser_state(JsonParserState *state) {
    if (state != NULL) {
        free(state->json_string);
        free(state);
    }
}

void parse_object(JsonParserState *state) {
    bool done = false;
    while (!done) {
        skip_whitespace(state);
        if (state->curr_index >= strlen(state->json_string)) {
            // end of JSON string
            break;
        }
        char c = state->json_string[state->curr_index];
        if (c == '}') {
            // end of object
            state->curr_index++;
            break;
        }
        // parse key
        JsonTokenInfo *key_info = next_token_info(state);
        if (key_info == NULL || key_info->token != JSON_STRING) {
            fprintf(stderr, "Error parsing JSON object key at position %d", state->curr_index);
            exit(1);
        }
        printf("Found key: %.*s\n", key_info->end_index-key_info->start_index+1, state->json_string+key_info->start_index);

        // parse colon
        skip_whitespace(state);
        JsonTokenInfo *colon_info = next_token_info(state);
        if (colon_info == NULL || colon_info->token != JSON_COLON) {
            fprintf(stderr, "Error parsing JSON colon at position %d", state->curr_index);
            exit(1);
        }

        // parse value
        skip_whitespace(state);
        JsonTokenInfo *value_info = next_token_info(state);
        if (value_info == NULL) {
            fprintf(stderr, "Error parsing JSON value at position %d", state->curr_index);
            exit(1);
        }
        switch (value_info->token) {
            case JSON_STRING:
                printf("Found string value: %.*s\n", value_info->end_index-value_info->start_index+1, state->json_string+value_info->start_index);
                break;
            case JSON_NUMBER:
                printf("Found number value: %.*s\n", value_info->end_index-value_info->start_index+1, state->json_string+value_info->start_index);
                break;
            case JSON_BOOL:
                printf("Found boolean value: %.*s\n", value_info->end_index-value_info->start_index+1, state->json_string+value_info->start_index);
                break;
            case JSON_NULL:
                printf("Found null value\n");
                break;
            case JSON_OBJECT_START:
                printf("Found nested object\n");
                parse_object(state);
                break;
            case JSON_ARRAY_START:
                printf("Found array\n");
                // skip array for now
                while (value_info->token != JSON_ARRAY_END) {
                    value_info = next_token_info(state);
                }
                break;
            default:
                fprintf(stderr, "Error parsing JSON value at position %d", state->curr_index);
                exit(1);
        }

        // parse comma or end
        skip_whitespace(state);
        JsonTokenInfo *comma_info = next_token_info(state);
        if (comma_info == NULL) {
            fprintf(stderr, "Error parsing JSON object comma or end at position %d", state->curr_index);
            exit(1);
        }
        if (comma_info->token == JSON_COMMA) {
            // more items in object
            free_token_info(key_info);
            free_token_info(colon_info);
            free_token_info(value_info);
        } else if (comma_info->token == JSON_OBJECT_END) {
            // end of object
            free_token_info(key_info);
            free_token_info(colon_info);
            free_token_info(value_info);
            done = true;
        } else {
            fprintf(stderr, "Error parsing JSON object comma or end at position %d", state->curr_index);
            exit(1);
        }
    }
}

void parse_json(char *json_string) {
    JsonParserState *state = (JsonParserState *)malloc(sizeof(JsonParserState));
    state->json_string = json_string;
    state->curr_index = 0;

    JsonTokenInfo *token_info = next_token_info(state);
    if (token_info == NULL) {
        fprintf(stderr, "Error parsing empty JSON string");
        exit(1);
    }

    if (token_info->token != JSON_OBJECT_START) {
        fprintf(stderr, "Error parsing JSON object start at position %d", state->curr_index);
        exit(1);
    }

    parse_object(state);

    // check for end of JSON string
    skip_whitespace(state);
    if (state->curr_index < strlen(state->json_string)) {
        fprintf(stderr, "Error parsing JSON - unexpected character at position %d", state->curr_index);
        exit(1);
    }

    free_token_info(token_info);
    free_parser_state(state);
}

int main() {
    // read JSON string from file
    char *json_string = read_file("example.json");

    // parse JSON string
    parse_json(json_string);

    // free memory
    free(json_string);

    return 0;
}