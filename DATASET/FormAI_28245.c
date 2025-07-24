//FormAI DATASET v1.0 Category: Syntax parsing ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a struct for our variables
typedef struct {
    char name[50];
    int line_num;
} variable;

int main() {
    // Open the file
    FILE *fp;
    fp = fopen("program.c", "r");
    char buffer[1000];
    int line_num = 1;
    int var_count = 0;
    variable vars[100];

    // Loop through each line of the file
    while(fgets(buffer, sizeof(buffer), fp)) {
        char *token = strtok(buffer, " ");

        // Look for declarations of int variables
        while(token != NULL) {
            if(strcmp(token, "int") == 0) {
                token = strtok(NULL, " ");

                // Add the variable to our list of variables
                strcpy(vars[var_count].name, token);
                vars[var_count].line_num = line_num;
                var_count++;
            }
            token = strtok(NULL, " ");
        }

        line_num++;
    }

    // Print out the variables we found
    printf("Found %d variables:\n", var_count);
    for(int i = 0; i < var_count; i++) {
        printf("Variable %s declared on line %d\n", vars[i].name, vars[i].line_num);
    }

    // Close the file and exit the program
    fclose(fp);
    return 0;
}