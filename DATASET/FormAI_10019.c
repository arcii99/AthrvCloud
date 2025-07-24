//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main(){

    // Define variables to store input and output
    char input[100];
    char output[100] = "";

    // Prompt user for input
    printf("Enter the alien language: ");
    fgets(input, sizeof(input), stdin);

    // Determine length of input
    int length = strlen(input);

    // Loop through each character in input and convert it
    for(int i=0; i<length-1; i++){

        char letter = input[i];

        switch(letter){
            case 'A': strcat(output, "X");
                      break;
            case 'B': strcat(output, "Y");
                      break;
            case 'C': strcat(output, "Z");
                      break;
            case 'X': strcat(output, "A");
                      break;
            case 'Y': strcat(output, "B");
                      break;
            case 'Z': strcat(output, "C");
                      break;
            default: strcat(output, "");
        }
    }

    // Print the translated output
    printf("Translated text: %s \n", output);

    return 0;
}