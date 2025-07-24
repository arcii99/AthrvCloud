//FormAI DATASET v1.0 Category: Funny ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the happy C virus program! Let's spread some joy!\n\n");
    printf("Please enter a sentence: ");
    char sentence[100];
    fgets(sentence, 100, stdin);

    printf("\nYour joyful sentence is: %s", sentence);
    printf("Let's now change all the vowels in your sentence to smiley faces! :)\n\n");

    for (int i = 0; sentence[i] != '\0'; i++) {
        switch (sentence[i]) {
            case 'a':
                sentence[i] = ':)';
                break;
            case 'e':
                sentence[i] = ':D';
                break;
            case 'i':
                sentence[i] = ':P';
                break;
            case 'o':
                sentence[i] = ';)';
                break;
            case 'u':
                sentence[i] = ':o';
                break;
            default: break;
        }
    }

    printf("Your new happy sentence is: %s", sentence);
    printf("Thank you for using the happy C virus program! Have a joyful day! :)\n");

    return 0;
}