//FormAI DATASET v1.0 Category: Syntax parsing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token {
    char *lexeme;
    int type;
    int line;
} Token;

enum TokenTypes {
    INT = 1,
    FLOAT = 2,
    CHAR = 3,
    STRING = 4,
    IDENTIFIER = 5
};

void parseProgram();
void parseVarDecl();
void parseType();
void parseIdentList();
void parseStmt();

char *program = "int main() {\n    int i;\n    float f;\n    i = 10;\n    f = 3.14;\n    printf(\"%d %f\", i, f);\n    return 0;\n}";

Token *tokens = NULL;
int numTokens = 0;

int main() {
    // split the program into tokens
    char *delimiters = " \n\t(){}[];,";
    char *tok = strtok(program, delimiters);
    while (tok != NULL) {
        Token *t = (Token *) malloc(sizeof(Token));
        t->lexeme = strdup(tok);
        t->type = 0;
        t->line = 0;
        tokens = (Token *) realloc(tokens, sizeof(Token) * ++numTokens);
        tokens[numTokens-1] = *t;
        free(t);
        tok = strtok(NULL, delimiters);
    }

    // parse the program
    parseProgram();

    return 0;
}

void parseProgram() {
    // just parse var decls and stmts for now
    parseVarDecl();
    parseStmt();
}

void parseVarDecl() {
    // check for variable declaration keywords "int" or "float"
    if (strcmp(tokens[0].lexeme, "int") == 0 || strcmp(tokens[0].lexeme, "float") == 0) {
        // parse the rest of the declaration
        parseType();
        parseIdentList();
        if (strcmp(tokens[numTokens-1].lexeme, ";") != 0) {
            printf("error: expected ; at end of var decl\n");
        }
    }
    else {
        printf("error: expected variable declaration\n");
    }
}

void parseType() {
    // check for type keywords "int" or "float"
    if (strcmp(tokens[0].lexeme, "int") == 0) {
        tokens[0].type = INT;
    }
    else if (strcmp(tokens[0].lexeme, "float") == 0) {
        tokens[0].type = FLOAT;
    }
    else {
        printf("error: expected type\n");
    }
}

void parseIdentList() {
    // check for an identifier
    if (tokens[0].type == IDENTIFIER) {
        // parse the rest of the identifier list if there is one
        int i = 1;
        while (strcmp(tokens[i].lexeme, ",") == 0) {
            i++;
            if (tokens[i].type != IDENTIFIER) {
                printf("error: expected identifier\n");
                break;
            }
            i++;
        }
    }
    else {
        printf("error: expected identifier list\n");
    }
}

void parseStmt() {
    // check for statement keyword "printf"
    if (strcmp(tokens[0].lexeme, "printf") == 0) {
        // parse the rest of the statement
        if (strcmp(tokens[1].lexeme, "(") != 0) {
            printf("error: expected (\n");
            return;
        }
        int i = 2;
        while (strcmp(tokens[i].lexeme, ")") != 0) {
            if (tokens[i].type == IDENTIFIER) {
                // do nothing
            }
            else if (strcmp(tokens[i].lexeme, ",") != 0) {
                printf("error: expected ,\n");
                break;
            }
            i++;
        }
        if (strcmp(tokens[++i].lexeme, ";") != 0) {
            printf("error: expected ; at end of stmt\n");
        }
    }
    else {
        printf("error: expected statement\n");
    }
}