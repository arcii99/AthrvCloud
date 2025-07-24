//FormAI DATASET v1.0 Category: Syntax parsing ; Style: introspective
#include <stdio.h>

// This program is a simple C syntax parser that reads in a C file and identifies various syntax elements such as variables, loops, and conditionals.

int main() {
    char filename[100];
    FILE *fp;
    char c;
    int in_comment = 0, in_quotes = 0, in_single_quotes = 0, in_variable = 0, in_function = 0;
    int open_paren_count = 0, close_paren_count = 0, open_bracket_count = 0, close_bracket_count = 0, open_brace_count = 0, close_brace_count = 0;
    int first_word = 1, i, j = 0, k, line_number = 1, function_line_number, variable_line_number;
    char variable_name[100];
    char function_name[100];

    printf("Enter the file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            line_number++;
            first_word = 1;
        }

        if (in_comment) {
            if (c == '*' && (c = fgetc(fp)) == '/') {
                in_comment = 0;
            }
        } else if (c == '/') {
            if ((c = fgetc(fp)) == '/') {
                while ((c = fgetc(fp)) != '\n') {}
            } else if (c == '*') {
                in_comment = 1;
            }
        } else if (!in_quotes && !in_single_quotes) {
            if (c == '(' && !in_function) {
                in_function = 1;
                open_paren_count = 1;
                function_line_number = line_number;
                i = j = 0;
            } else if (c == '{' && !in_function && !in_variable) {
                open_brace_count++;
            } else if (c == '(' && in_function) {
                open_paren_count++;
            } else if (c == ')' && in_function) {
                close_paren_count++;
                if (open_paren_count == close_paren_count) {
                    in_function = 0;

                    printf("Function: %s\n", function_name);
                    printf("Line Number: %d\n", function_line_number);
                }
            } else if (c == '[' && !in_function && !in_variable) {
                open_bracket_count++;
            } else if (c == '{' && in_variable) {
                open_brace_count++;
            } else if (c == '(' && in_variable) {
                open_paren_count++;
            } else if (c == ')' && in_variable) {
                close_paren_count++;
            } else if (c == ';' && in_variable) {
                in_variable = 0;
                printf("Variable: %s\n", variable_name);
                printf("Line Number: %d\n", variable_line_number);
            } else if (c == ';' && !in_function && !in_variable) {
                first_word = 1;
            } else if (c == '=') {
                in_variable = 1;
                variable_line_number = line_number;
                j = 0;
            } else if (c == ' ') {
                if (!first_word) {
                    if (strcmp(variable_name, "for") == 0) {
                        printf("Loop Found\n");
                    } else if (strcmp(variable_name, "while") == 0) {
                        printf("Loop Found\n");
                    } else if (strcmp(variable_name, "if") == 0) {
                        printf("Conditional Found\n");
                    } else if (strcmp(variable_name, "else") == 0) {
                        printf("Conditional Found\n");
                    } else if (strcmp(variable_name, "switch") == 0) {
                        printf("Switch Found\n");
                    } else if (strcmp(variable_name, "case") == 0) {
                        printf("Case Found\n");
                    } else if (strcmp(variable_name, "default") == 0) {
                        printf("Default Found\n");
                    } else if (strcmp(variable_name, "do") == 0) {
                        printf("Do While Loop Found\n");
                    } else if (strcmp(variable_name, "int") == 0) {
                        j = 0;
                    } else if (strcmp(variable_name, "char") == 0) {
                        j = 0;
                    } else if (strcmp(variable_name, "float") == 0) {
                        j = 0;
                    } else if (strcmp(variable_name, "double") == 0) {
                        j = 0;
                    } else if (strcmp(variable_name, "long") == 0) {
                        j = 0;
                    } else if (strcmp(variable_name, "short") == 0) {
                        j = 0;
                    }

                    for (k = 0; k < j; k++) {
                        variable_name[k] = '\0';
                    }

                    j = 0;
                } else {
                    first_word = 0;
                }
            } else {
                if (!in_function && !in_variable) {
                    variable_name[j] = c;
                    j++;
                } else if (in_function && open_paren_count == 1) {
                    function_name[i] = c;
                    i++;
                } else if (in_variable) {
                    variable_name[j] = c;
                    j++;
                }
            }
        }

        if (c == '\"' && !in_single_quotes) {
            if (in_quotes) {
                in_quotes = 0;
            } else {
                in_quotes = 1;
            }
        } else if (c == '\'' && !in_quotes) {
            if (in_single_quotes) {
                in_single_quotes = 0;
            } else {
                in_single_quotes = 1;
            }
        }

    }

    fclose(fp);

    return 0;
}