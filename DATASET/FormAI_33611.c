//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int i, j, count = 0;
    
    printf("Welcome to the C Alien Language Translator!\n");
    printf("Please input the message you'd like to translate: ");
    scanf("%[^\n]s", input);
    
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') { // ignore spaces
            continue;
        }
        else if (input[i] >= 'a' && input[i] <= 'z') {
            printf("%c", input[i] - 32); // convert lowercase to uppercase
            count++;
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            printf("%c", input[i]); // print uppercase as is
            count++;
        }
        else if (input[i] >= '0' && input[i] <= '9') {
            printf("%d", input[i] - '0'); // convert digit to integer
            count++;
        }
        else {
            printf("%c", input[i]); // print ASCII symbol as is
            count++;
        }
    }
    
    printf("\n");
    printf("Translating...\n");
    printf("Translated message: ");
    for (j = 0; j < count; j++) {
        printf("*"); // print asterisk for each translated character
    }
    
    printf("\n");
    printf("Thank you for using the C Alien Language Translator!\n");
    
    return 0;
}