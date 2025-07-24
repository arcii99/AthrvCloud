//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: calm
#include <stdio.h>
#include <string.h>

// Function to convert C Cat language to English
void cCatToEnglish(char cCat[]){
    int len = strlen(cCat);
    int i;

    // Loop through each character of the C Cat input string
    for (i = 0; i < len; i++){
        switch (cCat[i]){

            case 'M': 
                printf("Meow");
                break;

            case 'P':
                printf("Purr");
                break;

            case 'H':
                printf("Hiss");
                break;

            case 'C':
                printf("Cat");
                break;

            case 'W':
                printf("Woof");
                break;

            case 'R':
                printf("Rat");
                break;

            case 'B':
                printf("Bird");
                break;

            case 'T':
                printf("Tuna");
                break;

            case 'S':
                printf("Scratch");
                break;
            
            default:
                printf("%c", cCat[i]); // print other characters as is
                break;
        }
    }
}

int main(){

    char cCatInput[100];

    printf("Enter a sentence in C Cat language:\n");
    fgets(cCatInput, 100, stdin);

    printf("The English translation is: ");

    cCatToEnglish(cCatInput);

    return 0;
}