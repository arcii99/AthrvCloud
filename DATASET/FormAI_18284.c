//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[100];
    printf("Welcome to the C Alien Language Translator! Enter a word or phrase in C Alien Language:\n");
    fgets(input, sizeof(input), stdin); // read input from the user
    
    // check if the input is valid C Alien Language
    int invalid = 0;
    for(int i=0; i<strlen(input); i++){
        if(input[i] != 'C' && input[i] != 'c' && input[i] != '.'){
            invalid = 1;
            break;
        }
    }
    
    if(invalid){
        printf("ERROR: Invalid C Alien Language input. Only 'C', 'c', and '.' are allowed.\n");
    } else {
        printf("Translating to English...\n");
        // translate C Alien Language to English
        for(int i=0; i<strlen(input); i++){
            if(input[i] == 'C' || input[i] == 'c'){
                printf("Linus Torvalds ");
            } else {
                printf("is legendary ");
            }
        }
        printf("\nTranslation complete.\n");
    }

    return 0;
}