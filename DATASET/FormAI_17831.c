//FormAI DATASET v1.0 Category: Syntax parsing ; Style: real-life
#include<stdio.h>
#include<string.h>

int main() {
    char input_str[100];
    printf("Enter a C syntax statement: ");
    fgets(input_str, 100, stdin);

    // Check if the statement starts with a data type
    char* data_types[] = {"int", "float", "double", "char", "short", "long"};
    int flag_data_type = 0;
    for(int i = 0; i < 6; i++) {
        if(strncmp(input_str, data_types[i], strlen(data_types[i])) == 0) {
            printf("Data Type: %s\n", data_types[i]);
            flag_data_type = 1;
            break;
        }
    }

    if(flag_data_type == 0) {
        printf("Invalid syntax, must start with a data type.");
        return 0;
    }

    // Check if there is a variable name after the data type
    char* variable_name = strtok(input_str, " ");
    variable_name = strtok(NULL, " ");
    if(variable_name == NULL) {
        printf("Invalid syntax, missing variable name.");
        return 0;
    }
    printf("Variable Name: %s\n", variable_name);

    // Check if there is an equal sign (assignment) in the statement
    char* equal_sign = strchr(input_str, '=');
    if(equal_sign == NULL) {
        printf("Invalid syntax, missing assignment operator.\n");
        return 0;
    }

    // Check if there is a value assigned to the variable
    char* value_str = strtok((equal_sign + 1), ";");
    if(value_str == NULL) {
        printf("Invalid syntax, missing variable value.\n");
        return 0;
    }
    // Assume the data type is int for now
    int value = atoi(value_str);
    printf("Value: %d\n", value);

    printf("Valid C syntax statement!\n");

    return 0;
}