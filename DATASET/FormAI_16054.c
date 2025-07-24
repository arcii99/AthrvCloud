//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: immersive
#include<stdio.h>
#include<string.h>

int main() {
    printf("Hello there! Let's check if a word or phrase is a palindrome.\n");

    char input[1000];
    printf("Please enter a word or phrase: \n");
    fgets(input, 1000, stdin);

    int i, length = strlen(input);
    int isPal = 1;

    for(i=0; i<length/2; i++) { //loop through half of the input
        if(input[i] != input[length-i-2]) { //compare the i-th and (len-i-2)-th character of the input
            isPal = 0; //if the characters are different, the input is not a palindrome
            break; //exit the loop
        }
    }

    if(isPal) {
        printf("Congratulations! \"%s\" is a palindrome.\n", input);
    } else {
        printf("Sorry, \"%s\" is not a palindrome.\n", input);
    }

    return 0;
}