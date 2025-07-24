//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void convertToMorseCode(char text[], char morseCode[][10]) {
    const char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
                                 ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
                                 "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
                                };
    int len = strlen(text);
    int curr;
    for(int i = 0; i < len; i++) {
        curr = text[i] - 'a';
        if(curr < 0 || curr > 25) 
            printf(" ");
        else
            printf("%s ", morse_codes[curr]);
    }
    printf("\n");
}

int main() {
    char input_text[MAX_SIZE];
    char morse_code[MAX_SIZE][10];
    int choice;
    printf("Enter the text to convert to Morse Code: ");
    fgets(input_text, MAX_SIZE, stdin);

    while(1) {
        printf("\n1. Convert to Morse Code\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                convertToMorseCode(input_text, morse_code);
                break;
            case 2:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, try again!\n");
                break;
        }
    }
    return 0;
}