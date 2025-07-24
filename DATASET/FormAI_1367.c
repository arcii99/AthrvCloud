//FormAI DATASET v1.0 Category: Compression algorithms ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

void compress(char str[]) {
    char crnt = str[0]; // set the current character to the first character in the string
    int count = 1; // initialize the count variable to 1

    // loop through the string
    for (int i = 1; str[i] != '\0'; i++) {
        if (crnt == str[i]) { // if the current character is the same as the next character
            count++; // increment the count variable
        } else { // otherwise, if the next character is different than the current character
            printf("%d%c", count, crnt); // print the count and the current character
            count = 1; // reset the count variable
            crnt = str[i]; // set the current character to the next character
        }
    }
    printf("%d%c\n", count, crnt); // print the last count and the last character
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str); // read input string from user

    printf("Original string: %s\n", str); // print the original string
    printf("Compressed string: ");
    compress(str); // compress the string

    return 0;
}