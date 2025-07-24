//FormAI DATASET v1.0 Category: Syntax parsing ; Style: decentralized
#include <stdio.h>
#include <string.h>

typedef struct SymTab {
    char* name;
    char* type;
} SymTab;

SymTab symbol_table[100];
int symtab_size = 0;

void print_symbol_table() {
    printf("Symbol table:\n");
    for (int i = 0; i < symtab_size; i++) {
        printf("Name: %s, Type: %s\n", symbol_table[i].name, symbol_table[i].type);
    }
}

int main() {
    char input[1000];
    printf("Enter a C program:\n");
    fgets(input, 1000, stdin);
    char* token = strtok(input, "(){};, ");
    while (token != NULL) {
        if (strcmp(token, "int") == 0 || strcmp(token, "float") == 0) {
            char* name = strtok(NULL, "(){};, ");
            symbol_table[symtab_size].name = name;
            symbol_table[symtab_size].type = token;
            symtab_size++;
        }
        token = strtok(NULL, "(){};, ");
    }
    print_symbol_table();
    return 0;
}