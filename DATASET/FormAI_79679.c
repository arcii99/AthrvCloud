//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_DEPTH 10
#define MAX_JSON_KEY_LENGTH 50
#define MAX_JSON_VALUE_LENGTH 100

typedef enum {
    JSON_KEY,
    JSON_VALUE
} json_type_t;

typedef struct {
    unsigned char depth;
    char keys[MAX_JSON_DEPTH][MAX_JSON_KEY_LENGTH];
    char values[MAX_JSON_DEPTH][MAX_JSON_VALUE_LENGTH];
} json_parser_stack_t;


void json_parser_push(json_parser_stack_t* stack, char* key, char* value) {
    if (stack->depth < MAX_JSON_DEPTH) {
        strncpy(stack->keys[stack->depth], key, MAX_JSON_KEY_LENGTH - 1);
        strncpy(stack->values[stack->depth], value, MAX_JSON_VALUE_LENGTH - 1);
        stack->depth++;
    } else {
        printf("Maximum JSON depth exceeded\n");
        exit(EXIT_FAILURE);
    }
}

char* json_parser_pop(json_parser_stack_t* stack, char* key) {
    if (stack->depth > 0) {
        strncpy(key, stack->keys[--stack->depth], MAX_JSON_KEY_LENGTH - 1);
        return stack->values[stack->depth];
    } else {
        printf("JSON stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

void json_parser(char* json_input) {
    static json_parser_stack_t stack;
    char current_key[MAX_JSON_KEY_LENGTH], current_value[MAX_JSON_VALUE_LENGTH];
    json_type_t current_type = JSON_KEY;
    int i, j;

    stack.depth = 0;

    for (i = 0; i < strlen(json_input); i++) {
        switch (json_input[i]) {
            case '{':
                if (stack.depth == 0) {
                    printf("JSON root object not allowed\n");
                    exit(EXIT_FAILURE);
                }
                current_type = JSON_KEY;
                break;
            case '}':
                if (current_type == JSON_VALUE) {
                    json_parser_pop(&stack, current_key);
                }
                current_type = JSON_KEY;
                break;
            case ':':
                current_type = JSON_VALUE;
                break;
            case ',':
                if (current_type == JSON_VALUE) {
                    json_parser_pop(&stack, current_key);
                }
                current_type = JSON_KEY;
                break;
            default:
                if (current_type == JSON_KEY) {
                    for (j = i; j < strlen(json_input); j++) {
                        if (json_input[j] == ':') {
                            strncpy(current_key, &json_input[i], j - i);
                            current_key[j - i] = '\0';
                            i = j;
                            break;
                        }
                    }
                } else {
                    for (j = i; j < strlen(json_input); j++) {
                        if (json_input[j] == ',' || json_input[j] == '}') {
                            strncpy(current_value, &json_input[i], j - i);
                            current_value[j - i] = '\0';
                            i = j - 1;
                            json_parser_push(&stack, current_key, current_value);
                            break;
                        }
                    }
                }
                break;
        }
    }
}

int main() {
    char json_input[] = "{\"name\": \"John Smith\", \"age\": 42, \"address\": {\"street\": \"123 Main St\", \"city\": \"Anywhere\", \"state\": \"CA\"}}";
    json_parser(json_input);
    return 0;
}