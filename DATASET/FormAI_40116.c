//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Input a sentence in C Cat Language: ");
    fgets(input, 100, stdin);

    int len = strlen(input);
    char output[100] = "";

    for (int i = 0; i < len; i++) {
        // Convert meows to C
        if (input[i] == 'm' && i+2 < len && input[i+1] == 'e' && input[i+2] == 'o') {
            strcat(output, "C");
            i += 2;
        }
        // Convert purrs to spaces
        else if (input[i] == 'p' && i+2 < len && input[i+1] == 'u' && input[i+2] == 'r') {
            strcat(output, " ");
            i += 2;
        }
        // Convert hisses to semicolons
        else if (input[i] == 'h' && i+3 < len && input[i+1] == 'i' && input[i+2] == 's' && input[i+3] == 's') {
            strcat(output, ";");
            i += 3;
        }
        // Convert growls to comments
        else if (input[i] == 'g' && i+4 < len && input[i+1] == 'r' && input[i+2] == 'o' && input[i+3] == 'w' && input[i+4] == 'l') {
            strcat(output, "//");
            while (i+1 < len && input[i+1] != '\n') {
                strcat(output, &input[i+1]);
                i++;
            }
            strcat(output, "\n");
            break;
        }
        // Keep everything else the same
        else {
            char c[2] = {input[i]};
            strcat(output, c);
        }
    }

    printf("Translated sentence in C: %s", output);
    return 0;
}