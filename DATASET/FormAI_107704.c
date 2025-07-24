//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

int main() {
    char text[100];
    char morse[27][6] = {{".-"}, {"-..."}, {"-.-."}, {"-.."}, {"."}, {"..-."}, {"--."}, 
                        {"...."}, {".."}, {".---"}, {"-.-"}, {".-.."}, {"--"}, {"-."}, 
                        {"---"}, {".--."}, {"--.-"}, {".-."}, {"..."}, {"-"}, {"..-"}, 
                        {"...-"}, {".--"}, {"-..-"}, {"-.--"}, {"--.."}};

    printf("Enter text to convert to Morse code: ");
    fgets(text, 100, stdin);

    printf("\nYour converted text to Morse code is:\n\n");

    for(int i = 0; i < strlen(text); i++) {
        if(text[i] == ' ') {
            printf("  \t");
        } else if(text[i] == '\n') {
            printf("\n");
        } else {
            int index = (int)text[i] - 65;
            if(index < 0 || index > 25) {
                printf("Invalid character '%c'\n", text[i]);
                return 1;
            } else {
                printf("%s\t", morse[index]);
            }
        }
    }

    printf("\n");
    return 0;
}