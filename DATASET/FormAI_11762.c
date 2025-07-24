//FormAI DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include<stdio.h>
#include<string.h>

int main(){

    char str[100];
    printf("Enter the C program code:\n");

    // Read the C program code input from user
    fgets(str, 100, stdin);

    // Loop through the code and look for semicolons (;) to identify statements
    for(int i=0; i<strlen(str); i++){
        if(str[i] == ';'){
            printf("Found a statement!\n");
        }
    }

    // Parse the code to identify function names
    char* token = strtok(str, " \n\t(){};");
    while (token != NULL)
    {
        if(strcmp(token, "int") == 0 || strcmp(token, "void") == 0){
            // Found a function declaration
            token = strtok(NULL, " \n\t(){};");
            printf("Function name: %s\n", token);
        }
        token = strtok(NULL, " \n\t(){};");
    }

    return 0;
}