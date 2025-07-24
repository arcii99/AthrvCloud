//FormAI DATASET v1.0 Category: Text processing ; Style: protected
#include <stdio.h>
#include <string.h>

int main(){

    char input[1000], output[1000];
    int i, j=0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // reads input string

    // loop through every character of the input string
    for(i=0; i<strlen(input); i++){

        // check if the current character is a digit, and skip it if it is
        if(input[i] >= '0' && input[i] <= '9'){
            continue;
        }
        
        // check if the current character is uppercase, and convert it to lowercase
        if(input[i] >= 'A' && input[i] <= 'Z'){
            output[j] = input[i] + 32;
        } else {
            output[j] = input[i];
        }
        j++;
    }

    output[j] = '\0'; // add null character at the end of the output string

    printf("Processed string: %s", output);

    return 0;
}