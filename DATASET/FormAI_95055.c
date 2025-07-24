//FormAI DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[100];
    int i, length;
    
    printf("Enter a phrase: ");
    scanf("%[^\n]", input); // read in entire line of input
    
    length = strlen(input);
    
    for(i = 0; i < length; i++) {
        if(isupper(input[i])) { // if uppercase letter
            input[i] = tolower(input[i]); // convert to lowercase
        } else if(islower(input[i])) { // if lowercase letter
            input[i] = toupper(input[i]); // convert to uppercase
        }
    }

    printf("\nShape-shifted phrase: %s\n", input);
    
    return 0;
}