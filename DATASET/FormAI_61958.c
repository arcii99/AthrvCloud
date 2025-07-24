//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a sentence in C Cat Language: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character
    
    char output[100] = "";
    char word[10];
    int index = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == 'm' && input[i+1] == 'e' && input[i+2] == 'o') {
            strcat(output, "I");
            index += 1;
            i += 2;
        } else if (input[i] == 'm' && input[i+1] == 'a' && input[i+2] == 'w') {
            strcat(output, "am");
            index += 2;
            i += 2;
        } else {
            int j = 0;
            while (input[i] != ' ') {
                word[j] = input[i];
                j++;
                i++;
            }
            word[j] = '\0';
            
            switch (word[0]) {
                case 'p':
                    strcat(output, "Please");
                    index += 6;
                    break;
                case 't':
                    strcat(output, "Thank");
                    index += 5;
                    break;
                case 'u':
                    strcat(output, "You");
                    index += 3;
                    break;
                case 'h':
                    strcat(output, "Hello");
                    index += 5;
                    break;
                default:
                    strcat(output, word);
                    index += j;
                    break;
            }
            strcat(output, " ");
            index++;
        }
    }
    printf("Translated sentence: %s\n", output);
    printf("Number of characters saved: %d\n", ((int)strlen(input)) - index);
    return 0;
}