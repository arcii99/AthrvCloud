//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: surprised
#include<stdio.h>

int main(){

    printf("Welcome to the C Cat Language Translator!\n");

    printf("Please enter a phrase in C Cat language:\n");

    char input[100];
    fgets(input, 100, stdin);

    printf("Wow, that's some impressive meowing! Let's translate it to English:\n");

    // loop through each character in the input string
    for(int i = 0; i < strlen(input); i++) {

        // check if the character is a valid C Cat symbol
        switch(input[i]) {
            case 'm':
                printf("I ");
                break;
            case 'e':
                printf("am ");
                break;
            case 'o':
                printf("a ");
                break;
            case 'w':
                printf("computer! ");
                break;
            case ' ':
                printf(" ");
                break;
            default:
                printf("Hmm, I don't recognize this meow!\n");
                break;
        }
    }

    printf("\nThank you for translating with the C Cat Language Translator!\n");

    return 0;
}