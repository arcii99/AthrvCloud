//FormAI DATASET v1.0 Category: String manipulation ; Style: detailed
#include<stdio.h>
#include<string.h>

void reverse(char *string);

int main() {
    char string[100];
    printf("Enter a string: ");
    fgets(string, 100, stdin);
    // Removing the newline character from the input buffer
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
    printf("Original String: %s\n", string);
    reverse(string);
    printf("Reversed String: %s\n", string);
    return 0;
}

void reverse(char *string) {
    int length = strlen(string), i;
    char temp;
    for(i=0; i<length/2; i++) {
        temp = string[i];
        string[i] = string[length-1-i];
        string[length-1-i] = temp;
    }
}