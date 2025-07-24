//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef enum { STRING, NUMBER, L_BRACE, R_BRACE, COMMA, COLON, TRUE, FALSE, NULL_TYPE, UNKNOWN } token_type;

typedef struct {
    token_type type;
    char value[MAX_TOKEN_LEN];
} token_t;

typedef struct {
    char key[MAX_TOKEN_LEN];
    char value[MAX_TOKEN_LEN];
} json_object_t;

int index_of(char c, char* str) {
    char* p = strchr(str, c);
    if (p) {
        return p - str;
    }
    return -1;
}

void parse_tokens(char* json_str, token_t* tokens, int* num_tokens) {
    *num_tokens = 0;
    char* p = json_str;
    while (*p) {
        if (*p == '{') {
            tokens[(*num_tokens)++] = (token_t){L_BRACE, "{"};
        } else if (*p == '}') {
            tokens[(*num_tokens)++] = (token_t){R_BRACE, "}"};
        } else if (*p == ',') {
            tokens[(*num_tokens)++] = (token_t){COMMA, ","};
        } else if (*p == ':') {
            tokens[(*num_tokens)++] = (token_t){COLON, ":"};
        } else if (*p == '\"' || *p == '\'') {
            char* q = strchr(p + 1, *p);
            int len = q - p - 1;
            strncpy(tokens[(*num_tokens)++].value, p + 1, len);
            tokens[(*num_tokens) - 1].value[len] = '\0';
            tokens[(*num_tokens) - 1].type = STRING;
            p = q;
        } else if (*p >= '0' && *p <= '9') {
            char* q = p;
            while ((*q >= '0' && *q <= '9') || *q == '.') {
                q++;
            }
            int len = q - p;
            strncpy(tokens[(*num_tokens)++].value, p, len);
            tokens[(*num_tokens) - 1].value[len] = '\0';
            tokens[(*num_tokens) - 1].type = NUMBER;
            p = q - 1;
        } else if (strncmp(p, "true", 4) == 0) {
            tokens[(*num_tokens)++] = (token_t){TRUE, "true"};
            p += 3;
        } else if (strncmp(p, "false", 5) == 0) {
            tokens[(*num_tokens)++] = (token_t){FALSE, "false"};
            p += 4;
        } else if (strncmp(p, "null", 4) == 0) {
            tokens[(*num_tokens)++] = (token_t){NULL_TYPE, "null"};
            p += 3;
        } else if (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t') {
            // ignore whitespace
        } else {
            int len = strcspn(p + 1, ",:{}");
            strncpy(tokens[(*num_tokens)++].value, p, len);
            tokens[(*num_tokens) - 1].value[len] = '\0';
            tokens[(*num_tokens) - 1].type = UNKNOWN;
            p += len - 1;
        }
        p++;
    }
}

void parse_object(token_t* tokens, int* index, json_object_t* obj) {
    obj->key[0] = '\0';
    obj->value[0] = '\0';
    while (tokens[*index].type != R_BRACE) {
        if (tokens[*index].type == STRING && tokens[*index + 1].type == COLON) {
            // key-value pair
            strncpy(obj->key, tokens[*index].value, MAX_TOKEN_LEN - 1);
            (*index) += 2;
            if (tokens[*index].type == STRING || tokens[*index].type == NUMBER) {
                strncpy(obj->value, tokens[*index].value, MAX_TOKEN_LEN - 1);
            }
            (*index)++;
        } else if (tokens[*index].type == COMMA) {
            // next key-value pair
            (*index)++;
            if (tokens[*index].type == STRING && tokens[*index + 1].type == COLON) {
                (*index)++;
                continue;
            }
            return;
        } else {
            (*index)++;
        }
    }
}

void print_object(json_object_t* obj) {
    printf("{ \"%s\": %s }\n", obj->key, obj->value);
}

void parse_json(char* json_str) {
    token_t tokens[MAX_TOKENS];
    int num_tokens = 0;
    parse_tokens(json_str, tokens, &num_tokens);

    int index = 0;
    json_object_t obj;
    while (index < num_tokens) {
        if (tokens[index].type == L_BRACE) {
            printf("{\n");
            while (tokens[index].type != R_BRACE) {
                parse_object(tokens, &index, &obj);
                if (strlen(obj.key) > 0 && strlen(obj.value) > 0) {
                    print_object(&obj);
                }
            }
            printf("}\n");
            index++;
        } else if (tokens[index].type == COMMA) {
            index++;
        } else {
            index++;
        }
    }
}

int main() {
    char* json_str = "{ \"name\": \"Alice\", \"age\": 30, \"isStudent\": true, \"courses\": [\"Math\", \"Science\"] }";
    parse_json(json_str);
    return 0;
}