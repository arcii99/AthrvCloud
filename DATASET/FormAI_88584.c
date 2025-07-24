//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {
    char alien_language[50]; // declare a variable to store the alien language input
    int length, i, j;

    printf("Enter the alien language: ");
    scanf("%s", alien_language); // read input from the user

    length = strlen(alien_language);

    // Convert the alien language to English
    for(i = 0; i < length; i++) {
        if(alien_language[i] == '0') {
            printf("a"); // replace 0 with 'a'
        } 
        else if(alien_language[i] == '1') {
            printf("b"); // replace 1 with 'b'
        }
        else if(alien_language[i] == '2') {
            printf("c"); // replace 2 with 'c'
        }
        else if(alien_language[i] == '3') {
            printf("d"); // replace 3 with 'd'
        }
        else if(alien_language[i] == '4') {
            printf("e"); // replace 4 with 'e'
        }
        else if(alien_language[i] == '5') {
            printf("f"); // replace 5 with 'f'
        }
        else if(alien_language[i] == '6') {
            printf("g"); // replace 6 with 'g'
        }
        else if(alien_language[i] == '7') {
            printf("h"); // replace 7 with 'h'
        }
        else if(alien_language[i] == '8') {
            printf("i"); // replace 8 with 'i'
        }
        else if(alien_language[i] == '9') {
            printf("j"); // replace 9 with 'j'
        }
        else {
            printf("Error: Invalid input!"); // output an error message for invalid input
            break; // terminate the loop
        }
    }

    return 0;
}