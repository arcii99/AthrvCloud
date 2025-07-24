//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surprised
#include <stdio.h>
#include <ctype.h>

int main() {

    char input[100];
    printf("Please enter a string to be sanitized: ");
    fgets(input, sizeof(input), stdin);
  
    for(int i = 0; input[i] != '\0'; i++) {
        if(isalpha(input[i])) { // checks for alphabets
            input[i] = tolower(input[i]); // converts to lower case 
        }
        else if(isspace(input[i])) { 
            input[i] = ' '; // converts all white spaces into single spaces
        }
        else {
            input[i] = '@'; // any other character is replaced by '@'
        }
    }
    printf("Sanitized input : %s", input);
}