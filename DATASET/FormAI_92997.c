//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>

int main(){
    char c;

    printf("Enter a letter in Alien Language: ");
    scanf("%c", &c);

    switch(c){
        case 'E':
            printf("This translates to 'Hello' in English.");
            break;
        case 'A':
            printf("This translates to 'Goodbye' in English.");
            break;
        case 'F':
            printf("This translates to 'Thank you' in English.");
            break;
        case 'I':
            printf("This translates to 'Yes' in English.");
            break;
        case 'O':
            printf("This translates to 'No' in English.");
            break;
        default:
            printf("This letter is not recognized in this language.");
    }

    return 0;
}