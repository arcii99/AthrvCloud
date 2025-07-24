//FormAI DATASET v1.0 Category: Syntax parsing ; Style: portable
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    char keywords[10][10] = {"if", "else", "for", "while", "do", "return", "switch", "case", "break", "default"};
    char operators[] = "+-*/%=><&|!";
    int i, j, flag;
    printf("Enter a line of C code: ");
    fgets(input, 100, stdin);

    // Removing newline character from input
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
        input[strlen(input) - 1] = '\0';

    // Parsing the input
    for (i = 0; i < strlen(input); i++) {
        // Check for operator
        for (j = 0; j < strlen(operators); j++) {
            if (input[i] == operators[j]) {
                printf("%c\t<operator>\n", input[i]);
                break;
            }
        }
        if (j != strlen(operators))
            continue;
            
        // Check for keyword or identifier
        j = 0;
        flag = 0;
        while (input[i] != ' ' && input[i] != '\0') {
            if (flag == 0) {
                for (int k = 0; k < 10; k++) {
                    if (strncmp(&input[i], keywords[k], strlen(keywords[k])) == 0) {
                        printf("%s\t<keyword>\n", keywords[k]);
                        i += strlen(keywords[k]) - 1;
                        flag = 1;
                        break;
                    }
                }
            }

            if (flag == 0) {
                if (j == 0 && (input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z')) {
                    break;
                }
                else {
                    printf("%c", input[i]);
                    j++;
                    flag = 1;
                }
            }
            i++;
        }
        if (flag == 1) {
            printf("\t<identifier>\n");
        }
    }
    return 0;
}