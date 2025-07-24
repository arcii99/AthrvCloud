//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Please enter a C program in Cat Language:\n");
    fgets(input, 1000, stdin);

    // Transform Cat Language code into valid C code
    char output[10000] = "";
    char* line = strtok(input, "\n");
    while (line != NULL) {
        int length = strlen(line);
        if (line[0] == 'p' && line[1] == 'u' && line[2] == 'r' && line[3] == 'r' && line[4] == 'r') {
            strcat(output, "int ");
            for (int i = 5; i < length; i++) {
                if (line[i] == ' ') {
                    strcat(output, "_");
                } else {
                    strcat(output, (char[]){line[i], '\0'});
                }
            }
            strcat(output, " = 0;\n");
        } else if (line[0] == 'm' && line[1] == 'e' && line[2] == 'o' && line[3] == 'w') {
            char* variable = strtok(line + 4, " ");
            char* operation = strtok(NULL, " ");
            char* value = strtok(NULL, " ");
            strcat(output, variable);
            if (strcmp(operation, "inc") == 0) {
                strcat(output, "++");
            } else if (strcmp(operation, "dec") == 0) {
                strcat(output, "--");
            }
            strcat(output, ";\n");
        }
        line = strtok(NULL, "\n");
    }

    printf("\nYour C program is:\n%s", output);

    return 0;
}