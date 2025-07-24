//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str1[100];
    int i = 0, j = 0;

    printf("Welcome to the Surrealist User Input Sanitizer!\n");
    printf("Please enter your string:\n");

    fgets(str1, sizeof(str1), stdin); // Get user input

    printf("Processing input...\n");

    // Start inverting each character in the input string
    for(i = 0; str1[i] != '\0'; i++){
        // Replace spaces with "OUT OF BOUNDS"
        if(str1[i] == ' '){
            printf("OUT OF BOUNDS");
        }
        // Invert lowercase letters
        else if(islower(str1[i])){
            putchar(toupper(str1[i]));
        }
        // Invert uppercase letters
        else if(isupper(str1[i])){
            putchar(tolower(str1[i]));
        }
        // Replace numbers with Surrealist random quotes
        else if(isdigit(str1[i])){
            int num = (int)str1[i] - '0';
            switch(num){
                case 0:
                    printf("The only way to stay sane is to go a little crazy.\n");
                    break;
                case 1:
                    printf("I am not strange. I am just not normal.\n");
                    break;
                case 2:
                    printf("Surrealism is...: Thought expressed in the absence of any control exercised by reason, and outside all moral and aesthetic considerations.\n");
                    break;
                case 3:
                    printf("One cannot, in any kind of honesty, imitate the 'surrealists,' because their own originality has been incapable of imitation.\n");
                    break;
                case 4:
                    printf("There is nothing harder to learn than painting and nothing which most people take less trouble about learning. An art school is a place where about three people work with feverish energy and everybody else idles to a degree that I should have conceived unattainable by human nature.\n");
                    break;
                case 5:
                    printf("I should like to live in a world, which is more surrealistically orientated than this one which insists so much on a single order.\n");
                    break;
                case 6:
                    printf("Art is not what you see, but what you make others see.\n");
                    break;
                case 7:
                    printf("It is how you see these things, rather than the things themselves.\n");
                    break;
                case 8:
                    printf("The only thing that we know is that we know nothing - and that is the highest flight of human wisdom.\n");
                    break;
                case 9:
                    printf("Beauty will be convulsive or will not be at all.\n");
                    break;
                default:
                    printf("Error! Invalid input!\n");
                    exit(0);
            }
        }
        // Replace special characters with smileys
        else if(str1[i] == '.' || str1[i] == ',' || str1[i] == '!' || str1[i] == '?'){
            printf(":)");
        }
        // Leave all other characters untouched
        else{
            putchar(str1[i]);
        }
    }

    printf("\nInput processed! Have a surreal day!\n");

    return 0;
}