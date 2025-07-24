//FormAI DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[1000];
    int count = 0, i = 0;
    
    printf("Welcome to the C Word Count Tool! \n\n");
    printf("Please enter the text you want to count: ");
    fgets(input, sizeof(input), stdin);          // Read user input

    while(input[i] != '\0') {
        // Ignore starting white spaces
        while(isspace(input[i])) {
            i++;
        }
        
        // Count the characters in the word
        if(input[i] != '\0') {
            count++;
            i++;
        }

        // Ignore trailing white spaces
        while(input[i] != '\0' && !isspace(input[i])) {
            i++;
        }
    }

    printf("\nNumber of words in the input text: %d\n", count);

    return 0;
}