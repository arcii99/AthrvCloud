//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 64

typedef enum {
    TOKEN_NONE,
    TOKEN_OBJECT_BEGIN,
    TOKEN_OBJECT_END,
    TOKEN_ARRAY_BEGIN,
    TOKEN_ARRAY_END,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL,
    TOKEN_COMMA,
    TOKEN_COLON,
    TOKEN_END
} token_type_t;

typedef struct {
    token_type_t type;
    union {
        char *string;
        double number;
    } value;
} token_t;

typedef struct {
    char *data;
    size_t size;
    size_t idx;
} input_t;

input_t *input_create(char *data) {
    input_t *input = malloc(sizeof(input_t));
    input->data = data;
    input->size = strlen(data);
    input->idx = 0;
    return input;
}

void input_destroy(input_t *input) {
    free(input);
}

token_t *token_create() {
    token_t *token = malloc(sizeof(token_t));
    token->type = TOKEN_NONE;
    return token;
}

void token_destroy(token_t *token) {
    switch (token->type) {
        case TOKEN_STRING:
            free(token->value.string);
            break;
        default:
            break;
    }
    free(token);
}

char input_peek(input_t *input) {
    if (input->idx < input->size) {
        return input->data[input->idx];
    }
    return '\0';
}

char input_next(input_t *input) {
    if (input->idx < input->size) {
        return input->data[input->idx++];
    }
    return '\0';
}

void input_skip_whitespace(input_t *input) {
    while (input_peek(input) == ' ' || input_peek(input) == '\t' || input_peek(input) == '\n' || input_peek(input) == '\r') {
        input_next(input);
    }
}

void token_set_string(token_t *token, char *str) {
    token->type = TOKEN_STRING;
    token->value.string = malloc(strlen(str) + 1);
    strncpy(token->value.string, str, strlen(str) + 1);
}

int token_parse_string(input_t *input, token_t *token) {
    char str[MAX_DEPTH];
    char c = input_next(input);
    int i = 0;
    while (c != '\"' && i < MAX_DEPTH) {
        if (c == '\\') {
            c = input_next(input);
            switch (c) {
                case '\"':
                    str[i++] = '\"';
                    break;
                case '\\':
                    str[i++] = '\\';
                    break;
                case '/':
                    str[i++] = '/';
                    break;
                case 'b':
                    str[i++] = '\b';
                    break;
                case 'f':
                    str[i++] = '\f';
                    break;
                case 'n':
                    str[i++] = '\n';
                    break;
                case 'r':
                    str[i++] = '\r';
                    break;
                case 't':
                    str[i++] = '\t';
                    break;
                case 'u':
                    // unsupported unicode escape
                    return 0;
                default:
                    return 0;
            }
        } else {
            str[i++] = c;
        }
        c = input_next(input);
    }
    if (c != '\"') {
        return 0;
    }
    str[i] = '\0';
    token_set_string(token, str);
    return 1;
}

int token_parse_number(input_t *input, token_t *token) {
    char str[MAX_DEPTH];
    char c = input_peek(input);
    int i = 0;
    int is_decimal = 0;
    while ((c >= '0' && c <= '9') || c == '-' || c == '+' || (!is_decimal && c == '.')) {
        input_next(input);
        str[i++] = c;
        if (c == '.') {
            is_decimal = 1;
        }
        c = input_peek(input);
    }
    str[i] = '\0';
    char *end;
    double number = strtod(str, &end);
    if (str == end) {
        return 0;
    }
    token->type = TOKEN_NUMBER;
    token->value.number = number;
    return 1;
}

int token_parse_true(input_t *input, token_t *token) {
    if (input_next(input) != 't') {
        return 0;
    }
    if (input_next(input) != 'r') {
        return 0;
    }
    if (input_next(input) != 'u') {
        return 0;
    }
    if (input_next(input) != 'e') {
        return 0;
    }
    token->type = TOKEN_TRUE;
    return 1;
}

int token_parse_false(input_t *input, token_t *token) {
    if (input_next(input) != 'f') {
        return 0;
    }
    if (input_next(input) != 'a') {
        return 0;
    }
    if (input_next(input) != 'l') {
        return 0;
    }
    if (input_next(input) != 's') {
        return 0;
    }
    if (input_next(input) != 'e') {
        return 0;
    }
    token->type = TOKEN_FALSE;
    return 1;
}

int token_parse_null(input_t *input, token_t *token) {
    if (input_next(input) != 'n') {
        return 0;
    }
    if (input_next(input) != 'u') {
        return 0;
    }
    if (input_next(input) != 'l') {
        return 0;
    }
    if (input_next(input) != 'l') {
        return 0;
    }
    token->type = TOKEN_NULL;
    return 1;
}

int token_parse(input_t *input, token_t *token) {
    input_skip_whitespace(input);
    char c = input_peek(input);
    switch (c) {
        case '{':
            token->type = TOKEN_OBJECT_BEGIN;
            input_next(input);
            break;
        case '}':
            token->type = TOKEN_OBJECT_END;
            input_next(input);
            break;
        case '[':
            token->type = TOKEN_ARRAY_BEGIN;
            input_next(input);
            break;
        case ']':
            token->type = TOKEN_ARRAY_END;
            input_next(input);
            break;
        case '\"':
            return token_parse_string(input, token);
        case '-':
        case '+':
        case '0' ... '9':
            return token_parse_number(input, token);
        case 't':
            return token_parse_true(input, token);
        case 'f':
            return token_parse_false(input, token);
        case 'n':
            return token_parse_null(input, token);
        case ':':
            token->type = TOKEN_COLON;
            input_next(input);
            break;
        case ',':
            token->type = TOKEN_COMMA;
            input_next(input);
            break;
        case '\0':
            token->type = TOKEN_END;
            break;
        default:
            return 0;
    }
    return 1;
}

int token_expect(input_t *input, token_type_t type) {
    token_t *token = token_create();
    if (token_parse(input, token) && token->type == type) {
        token_destroy(token);
        return 1;
    }
    token_destroy(token);
    return 0;
}

void token_print(token_t *token) {
    switch (token->type) {
        case TOKEN_OBJECT_BEGIN:
            printf("{");
            break;
        case TOKEN_OBJECT_END:
            printf("}");
            break;
        case TOKEN_ARRAY_BEGIN:
            printf("[");
            break;
        case TOKEN_ARRAY_END:
            printf("]");
            break;
        case TOKEN_STRING:
            printf("\"%s\"", token->value.string);
            break;
        case TOKEN_NUMBER:
            printf("%lf", token->value.number);
            break;
        case TOKEN_TRUE:
            printf("true");
            break;
        case TOKEN_FALSE:
            printf("false");
            break;
        case TOKEN_NULL:
            printf("null");
            break;
        case TOKEN_COLON:
            printf(":");
            break;
        case TOKEN_COMMA:
            printf(",");
            break;
        default:
            break;
    }
}

void parse_value(input_t *input) {
    token_t *token = token_create();
    if (token_parse(input, token)) {
        token_print(token);
        switch (token->type) {
            case TOKEN_OBJECT_BEGIN:
                printf("\n");
                parse_object(input);
                break;
            case TOKEN_ARRAY_BEGIN:
                printf("\n");
                parse_array(input);
                break;
            default:
                break;
        }
    }
    token_destroy(token);
}

void parse_array(input_t *input) {
    token_print(token_create(TOKEN_ARRAY_BEGIN, NULL));
    if (!token_expect(input, TOKEN_ARRAY_END)) {
        while (1) {
            printf("\n");
            parse_value(input);
            if (token_expect(input, TOKEN_ARRAY_END)) {
                break;
            }
            token_expect(input, TOKEN_COMMA);
        }
    }
    token_print(token_create(TOKEN_ARRAY_END, NULL));
}

void parse_object(input_t *input) {
    token_print(token_create(TOKEN_OBJECT_BEGIN, NULL));
    if (!token_expect(input, TOKEN_OBJECT_END)) {
        while (1) {
            printf("\n");
            token_t *key = token_create();
            if (token_parse_string(input, key) && token_expect(input, TOKEN_COLON)) {
                printf("\"%s\": ", key->value.string);
                parse_value(input);
                if (token_expect(input, TOKEN_OBJECT_END)) {
                    break;
                }
                token_expect(input, TOKEN_COMMA);
            }
            token_destroy(key);
        }
    }
    token_print(token_create(TOKEN_OBJECT_END, NULL));
}

void parse_json(char *json) {
    input_t *input = input_create(json);
    parse_value(input);
    input_destroy(input);
}

int main() {
    char *json = "{"
        "\"id\": 1,"
        "\"name\": \"John Smith\","
        "\"age\": 32,"
        "\"is_active\": true,"
        "\"scores\": ["
            "10,"
            "20,"
            "30"
        "],"
        "\"address\": {"
            "\"street\": \"123 Main St\","
            "\"city\": \"Anytown\","
            "\"state\": \"CA\","
            "\"zip\": \"12345\""
        "},"
        "\"friends\": ["
            "{ \"name\": \"Alice\", \"age\": 25 },"
            "{ \"name\": \"Bob\", \"age\": 27 }"
        "]"
    "}";
    parse_json(json);
    return 0;
}