//FormAI DATASET v1.0 Category: Data validation ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    int length, flag = 0;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin); // Read input string

    length = strlen(input);

    // Check if input contains only alphabets
    for(int i = 0; i < length; i++) {
        if(!isalpha(input[i])) {
            flag = 1;
            break;  // Exit loop if non-alphabetic character is found
        }
    }

    // Display output
    if(flag == 1) {
        printf("Invalid input! Input contains non-alphabetic characters.");
    } else {
        printf("Valid input! Input contains only alphabetic characters.");
    }

    return 0;
}