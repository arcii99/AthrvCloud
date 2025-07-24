//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// define constants
#define MAX_JSON_SIZE 1024
#define MAX_TOKENS 256
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 128

// define token type
typedef enum {
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_BOOL,
    TOKEN_NULL,
    TOKEN_OBJECT_START,
    TOKEN_OBJECT_END,
    TOKEN_ARRAY_START,
    TOKEN_ARRAY_END,
    TOKEN_KEY_VALUE_SEP,
    TOKEN_ITEM_SEP
} token_type;

// define token struct
typedef struct {
    token_type type;
    char value[MAX_VALUE_SIZE];
} token;

// declare functions
void parse_json(char* json_string);
void tokenize_json(char* json_string, token tokens[]);
void parse_object(token tokens[], int* index);
void parse_array(token tokens[], int* index);
void parse_value(token tokens[], int* index);
void print_token(token t);

// main function
int main()
{
    char sample_json[] = "{\"name\": \"John Doe\", \"age\": 25, \"is_married\": true, \"hobbies\": [\"reading\", \"sports\"]}";
    parse_json(sample_json);
    return 0;
}

// function to parse json
void parse_json(char* json_string)
{
    token tokens[MAX_TOKENS];
    int index = 0;
    tokenize_json(json_string, tokens);
    parse_object(tokens, &index);
}

// function to tokenize json string
void tokenize_json(char* json_string, token tokens[])
{
    char* ptr = json_string;
    token_type t = TOKEN_NULL;
    char temp[MAX_VALUE_SIZE] = "";
    int index = 0;

    while (*ptr != '\0') {
        switch (*ptr) {
            case '{':
                t = TOKEN_OBJECT_START;
                break;
            case '}':
                t = TOKEN_OBJECT_END;
                break;
            case '[':
                t = TOKEN_ARRAY_START;
                break;
            case ']':
                t = TOKEN_ARRAY_END;
                break;
            case ':':
                t = TOKEN_KEY_VALUE_SEP;
                break;
            case ',':
                t = TOKEN_ITEM_SEP;
                break;
            case '\"':
                ptr++;
                index = 0;
                while (*ptr != '\"') {
                    temp[index++] = *ptr++;
                }
                temp[index] = '\0';
                strcpy(tokens[ptr - json_string].value, temp);
                t = TOKEN_STRING;
                break;
            case 't':
            case 'f':
                t = TOKEN_BOOL;
                if (*ptr == 't') {
                    strcpy(tokens[ptr - json_string].value, "true");
                } else {
                    strcpy(tokens[ptr - json_string].value, "false");
                }
                ptr += 3;
                break;
            case 'n':
                t = TOKEN_NULL;
                strcpy(tokens[ptr - json_string].value, "null");
                ptr += 3;
                break;
            default:
                if (*ptr >= '0' && *ptr <= '9') {
                    index = 0;
                    while (*ptr >= '0' && *ptr <= '9') {
                        temp[index++] = *ptr++;
                    }
                    if (*ptr == '.') {
                        temp[index++] = *ptr++;
                        while (*ptr >= '0' && *ptr <= '9') {
                            temp[index++] = *ptr++;
                        }
                    }
                    temp[index] = '\0';
                    strcpy(tokens[ptr - json_string].value, temp);
                    t = TOKEN_NUMBER;
                }
                break;
        }
        tokens[ptr - json_string].type = t;
        ptr++;
    }
}

// function to parse object
void parse_object(token tokens[], int* index)
{
    while (tokens[*index].type != TOKEN_OBJECT_END) {
        if (tokens[*index].type == TOKEN_STRING) {
            printf("%s: ", tokens[*index].value);
            (*index)++;
            if (tokens[*index].type == TOKEN_KEY_VALUE_SEP) {
                (*index)++;
                parse_value(tokens, index);
                if (tokens[*index].type == TOKEN_ITEM_SEP) {
                    printf(", ");
                    (*index)++;
                }
            }
        } else {
            (*index)++;
        }
    }
    (*index)++;
}

// function to parse array
void parse_array(token tokens[], int* index)
{
    printf("[");
    while (tokens[*index].type != TOKEN_ARRAY_END) {
        parse_value(tokens, index);
        if (tokens[*index].type == TOKEN_ITEM_SEP) {
            printf(", ");
            (*index)++;
        }
    }
    printf("]");
    (*index)++;
}

// function to parse value
void parse_value(token tokens[], int* index)
{
    switch (tokens[*index].type) {
        case TOKEN_STRING:
        case TOKEN_NUMBER:
        case TOKEN_BOOL:
        case TOKEN_NULL:
            printf("%s", tokens[*index].value);
            (*index)++;
            break;
        case TOKEN_OBJECT_START:
            printf("{");
            (*index)++;
            parse_object(tokens, index);
            printf("}");
            break;
        case TOKEN_ARRAY_START:
            (*index)++;
            parse_array(tokens, index);
            break;
        default:
            break;
    }
}

// function to print token for testing purposes
void print_token(token t)
{
    printf("Type: %d, Value: %s\n", t.type, t.value);
}