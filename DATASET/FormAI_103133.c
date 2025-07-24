//FormAI DATASET v1.0 Category: Text processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    int length = strlen(input);
    
    char new_string[length];
    
    for(int i = 0; i < length; i++) {
        if(input[i] != ' ') {
            new_string[i] = input[i] + 2;
        } else {
            new_string[i] = ' ';
        }
    }
    
    printf("Your encoded string is: %s\n", new_string);
    
    return 0;
}