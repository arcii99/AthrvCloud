//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Linus Torvalds
#include <stdio.h>

struct Token {
    char* name;
    enum TokenType {
        KEYWORD,
        IDENTIFIER,
        OPERATOR
    } type;
};

typedef struct Token Token;

void parse(char* source_code) {
    Token tokens[100];
    int num_tokens = 0;
    char* current_token = strtok(source_code, " ");

    while (current_token != NULL) {
        if (strcmp(current_token, "int") == 0 || strcmp(current_token, "char") == 0) {
            Token new_token = {
                .name = current_token,
                .type = KEYWORD
            };
            tokens[num_tokens++] = new_token;
        }
        else if (strlen(current_token) == 1 && strchr("+-*/%=!<>", current_token[0]) != NULL) {
            Token new_token = {
                .name = current_token,
                .type = OPERATOR
            };
            tokens[num_tokens++] = new_token;
        }
        else {
            Token new_token = {
                .name = current_token,
                .type = IDENTIFIER
            };
            tokens[num_tokens++] = new_token;
        }

        current_token = strtok(NULL, " ");
    }

    printf("Parsed %d tokens:\n", num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        printf("%s (Type: ", tokens[i].name);
        switch(tokens[i].type) {
            case KEYWORD:
                printf("Keyword");
                break;
            case IDENTIFIER:
                printf("Identifier");
                break;
            case OPERATOR:
                printf("Operator");
                break;
            default:
                printf("Unknown");
                break;
        }
        printf(")\n");
    }
}

int main() {
    char source_code[] = "int x = 5 + 3; char y = 'c'; x += 1; if (x > 7 && y == 'c') { printf('Success!'); }";
    parse(source_code);
    return 0;
}