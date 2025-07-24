//FormAI DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 1000 //Maximum string length

int main() {
    char input_str[MAX_STR]; //Input string
    int count = 0; //Word count
    int i;

    printf("Enter a string: ");
    fflush(stdout); //Clear output buffer
    fgets(input_str, MAX_STR, stdin); //Read input string from user

    for (i = 0; input_str[i] != '\0'; i++) {
        if (isspace(input_str[i]) && !isspace(input_str[i-1])) { //If current char is space and previous char is not space
            count++; //Word count increases
        }
    }

    if (input_str[strlen(input_str) - 1] != '\n') { //If string length is greater than MAX_STR
        int c;
        while ((c = getchar()) != '\n' && c != EOF); //Flush stdin buffer
    }

    if (!isspace(input_str[strlen(input_str) - 1])) { //If last char is not space
        count++; //Last word is also counted
    }

    printf("\nWord count is: %d\n", count); //Print the word count

    return 0;
}