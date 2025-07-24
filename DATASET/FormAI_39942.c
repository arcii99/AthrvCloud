//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    char phrase[100];
    int i, j, k;

    printf("Enter a phrase in C Cat Language: ");
    fgets(phrase, 100, stdin);

    for (i = 0; phrase[i] != '\0'; i++) {
        if (phrase[i] == 'm') {
            printf("printf(\"Hello World\\n\");\n");
            i++;
        }
        else if (phrase[i] == 'f') {
            printf("for (i = 0; i < 10; i++) {\n");
            for (j = i+1; phrase[j] != 's'; j++) {
                if (phrase[j] == 'm') {
                    printf("printf(\"Hello World\\n\");\n");
                }
                else if (phrase[j] == 'p') {
                    printf("printf(\"%%c\", phrase[%d]);\n", j+1);
                    j++;
                }
            }
            printf("}\n");
            i = j;
        }
        else if (phrase[i] == 'w') {
            printf("while(1) {\n");
            for (j = i+1; phrase[j] != 's'; j++) {
                if (phrase[j] == 'm') {
                    printf("printf(\"Hello World\\n\");\n");
                }
                else if (phrase[j] == 'p') {
                    printf("printf(\"%%c\", phrase[%d]);\n", j+1);
                    j++;
                }
            }
            printf("}\n");
            i = j;
        }
        else if (phrase[i] == 'i') {
            printf("if(1) {\n");
            for (j = i+1; phrase[j] != 'e'; j++) {
                if (phrase[j] == 'm') {
                    printf("printf(\"Hello World\\n\");\n");
                }
                else if (phrase[j] == 'p') {
                    printf("printf(\"%%c\", phrase[%d]);\n", j+1);
                    j++;
                }
            }
            printf("}\n");
            i = j+1;
        }
        else if (phrase[i] == 'e') {
            printf("else {\n");
            for (j = i+1; phrase[j] != 'e'; j++) {
                if (phrase[j] == 'm') {
                    printf("printf(\"Hello World\\n\");\n");
                }
                else if (phrase[j] == 'p') {
                    printf("printf(\"%%c\", phrase[%d]);\n", j+1);
                    j++;
                }
            }
            printf("}\n");
            i = j+1;
        }
        else if (phrase[i] == 'd') {
            printf("do {\n");
            for (j = i+1; phrase[j] != 'l'; j++) {
                if (phrase[j] == 'm') {
                    printf("printf(\"Hello World\\n\");\n");
                }
                else if (phrase[j] == 'p') {
                    printf("printf(\"%%c\", phrase[%d]);\n", j+1);
                    j++;
                }
            }
            printf("} while(1);\n");
            i = j+1;
        }
        else if (phrase[i] == 'l') {
            printf("break;\n");
        }
        else if (phrase[i] == 'c') {
            printf("continue;\n");
        }
        else if (phrase[i] == 'r') {
            printf("return 0;\n");
        }
        else if (phrase[i] == 's') {
            break;
        }
    }

    return 0;
}