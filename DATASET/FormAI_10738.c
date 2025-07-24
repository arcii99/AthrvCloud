//FormAI DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to count the number of c in a string
int countC(char* str) {
    int count = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == 'c' || str[i] == 'C') {
            count++;
        }
    }
    return count;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    // removing the trailing newline character from the input
    if(str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }

    int count = countC(str);
    printf("The number of c's in the given string is: %d", count);

    return 0;
}