//FormAI DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str) {
    int length = strlen(str);
    char *start = str;
    char *end = str + length - 1;
    
    while(start <= end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char input[100];
    char output[100];
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline
    
    // copy string to output
    strcpy(output, input);
    
    // reverse output string
    reverse(output);
    
    // concatenate input and output strings
    strcat(input, output);
    
    printf("Result: %s\n", input);
    
    return 0;
}