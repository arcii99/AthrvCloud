//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEPTH 32

typedef enum {
    TOKEN_NULL,
    TOKEN_BOOL,
    TOKEN_NUMBER,
    TOKEN_STRING,
    TOKEN_OBJECT_START,
    TOKEN_OBJECT_END,
    TOKEN_ARRAY_START,
    TOKEN_ARRAY_END,
    TOKEN_COMMA,
    TOKEN_COLON,
} Token;

typedef struct {
    Token token;
    char *value;
} ParseToken;

typedef struct {
    char *data;
    int index;
    int length;
} ParseState;

bool parse_string(ParseState *state, char **string_out);
bool parse_number(ParseState *state, double *number_out);
bool parse_token(ParseState *state, Token token);
bool parse_value(ParseState *state);
bool parse_object(ParseState *state);
bool parse_array(ParseState *state);

ParseToken tokens[MAX_DEPTH];
int token_depth = 0;

bool parse_string(ParseState *state, char **string_out) {
    int start = state->index++;
    while (state->index < state->length) {
        if (state->data[state->index] == '\"') {
            int end = state->index++;
            int length = end - start - 1;
            *string_out = strndup(state->data + start + 1, length);
            return true;
        }
        state->index++;
    }
    return false;
}

bool parse_number(ParseState *state, double *number_out) {
    int start = state->index;
    while (state->index < state->length) {
        char c = state->data[state->index];
        if (c < '0' || c > '9') {
            break;
        }
        state->index++;
    }
    int length = state->index - start;
    char *string = strndup(state->data + start, length);
    *number_out = atof(string);
    free(string);
    return true;
}

bool parse_token(ParseState *state, Token token) {
    while (state->index < state->length) {
        char c = state->data[state->index];
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
            state->index++;
            continue;
        }
        if (c == token) {
            state->index++;
            return true;
        }
        break;
    }
    return false;
}

bool parse_value(ParseState *state) {
    char c = state->data[state->index];
    if (c == '\"') {
        char *string;
        if (!parse_string(state, &string)) {
            return false;
        }
        tokens[token_depth++] = (ParseToken){TOKEN_STRING, string};
        return true;
    }
    if (c == '-' || (c >= '0' && c <= '9')) {
        double number;
        if (!parse_number(state, &number)) {
            return false;
        }
        tokens[token_depth++] = (ParseToken){TOKEN_NUMBER, &number};
        return true;
    }
    if (c == 't' || c == 'f' || c == 'n') {
        if (c == 't') {
            if (!parse_token(state, 't') || !parse_token(state, 'r') || !parse_token(state, 'u') || !parse_token(state, 'e')) {
                return false;
            }
            tokens[token_depth++] = (ParseToken){TOKEN_BOOL, "true"};
            return true;
        }
        if (c == 'f') {
            if (!parse_token(state, 'f') || !parse_token(state, 'a') || !parse_token(state, 'l') || !parse_token(state, 's') || !parse_token(state, 'e')) {
                return false;
            }
            tokens[token_depth++] = (ParseToken){TOKEN_BOOL, "false"};
            return true;
        }
        if (c == 'n') {
            if (!parse_token(state, 'n') || !parse_token(state, 'u') || !parse_token(state, 'l') || !parse_token(state, 'l')) {
                return false;
            }
            tokens[token_depth++] = (ParseToken){TOKEN_NULL, "null"};
            return true;
        }
    }
    if (c == '{') {
        if (!parse_token(state, '{')) {
            return false;
        }
        tokens[token_depth++] = (ParseToken){TOKEN_OBJECT_START, "{"};
        if (!parse_object(state)) {
            return false;
        }
        tokens[token_depth++] = (ParseToken){TOKEN_OBJECT_END, "}"};
        return true;
    }
    if (c == '[') {
        if (!parse_token(state, '[')) {
            return false;
        }
        tokens[token_depth++] = (ParseToken){TOKEN_ARRAY_START, "["};
        if (!parse_array(state)) {
            return false;
        }
        tokens[token_depth++] = (ParseToken){TOKEN_ARRAY_END, "]"};
        return true;
    }
    return false;
}

bool parse_object(ParseState *state) {
    while (state->index < state->length) {
        if (!parse_token(state, '\"')) {
            break;
        }
        char *key;
        if (!parse_string(state, &key)) {
            break;
        }
        tokens[token_depth++] = (ParseToken){TOKEN_STRING, key};
        if (!parse_token(state, ':')) {
            break;
        }
        if (!parse_value(state)) {
            break;
        }
        if (!parse_token(state, ',')) {
            break;
        }
    }
    return true;
}

bool parse_array(ParseState *state) {
    while (state->index < state->length) {
        if (!parse_value(state)) {
            break;
        }
        if (!parse_token(state, ',')) {
            break;
        }
    }
    return true;
}

int main() {
    char *json = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\",\"pets\":[{\"name\":\"Dog\",\"breed\":\"Labrador Retriever\"},{\"name\":\"Cat\",\"breed\":\"Siamese\"}]}";
    ParseState state = {json, 0, strlen(json)};
    parse_object(&state);
    for (int i = 0; i < token_depth; i++) {
        ParseToken token = tokens[i];
        printf("Token %d: ", i);
        switch (token.token) {
            case TOKEN_NULL:
                printf("null\n");
                break;
            case TOKEN_BOOL:
                printf("bool(%s)\n", token.value);
                break;
            case TOKEN_NUMBER:
                printf("number(%f)\n", *(double *)token.value);
                break;
            case TOKEN_STRING:
                printf("string(%s)\n", token.value);
                break;
            case TOKEN_OBJECT_START:
                printf("object start(%s)\n", token.value);
                break;
            case TOKEN_OBJECT_END:
                printf("object end(%s)\n", token.value);
                break;
            case TOKEN_ARRAY_START:
                printf("array start(%s)\n", token.value);
                break;
            case TOKEN_ARRAY_END:
                printf("array end(%s)\n", token.value);
                break;
            case TOKEN_COMMA:
                printf("comma\n");
                break;
            case TOKEN_COLON:
                printf("colon\n");
                break;
        }
        free(token.value);
    }
    return 0;
}