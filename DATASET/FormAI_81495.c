//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: high level of detail
#include <stdio.h>
#include <string.h>

char* alienTranslate(char c) {
    switch(c) {
        case '1':
            return "S";
        case '2':
            return "T";
        case '3':
            return "U";
        case '4':
            return "V";
        case '5':
            return "W";
        case '6':
            return "X";
        case '7':
            return "Y";
        case '8':
            return "Z";
        default:
            return "~";
    }
}

int main() {
    char input[1000];
    printf("Enter alien language message: ");
    scanf("%[^\n]", input);
    
    printf("Your translated message is: ");
    for(int i = 0; i < strlen(input); i++) {
        printf("%s", alienTranslate(input[i]));
    }
    
    printf("\n");
    
    return 0;
}