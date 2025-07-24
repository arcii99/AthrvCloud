//FormAI DATASET v1.0 Category: Syntax parsing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_VARIABLES 10

int main() {
    char input[MAX_INPUT_LENGTH];
    char variables[MAX_VARIABLES][MAX_INPUT_LENGTH];
    int num_variables = 0;

    printf("Enter C code: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    char* token = strtok(input, " {;}()=\n");

    while(token != NULL) {
        if(strcmp(token, "int") == 0 || strcmp(token, "char") == 0) {
            token = strtok(NULL, " {;}()=\n");
            strcpy(variables[num_variables], token);
            num_variables++;
        }
        token = strtok(NULL, " {;}()=\n");
    }

    printf("Your code declares %d variables:\n", num_variables);

    for(int i = 0; i < num_variables; i++) {
        printf("%s\n", variables[i]);
    }

    return 0;
}