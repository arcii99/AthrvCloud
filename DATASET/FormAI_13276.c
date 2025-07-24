//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {
    char word[100];   //declare array to hold user input
    int i, j, length;
    int isPal = 1;    //initialize isPal to true

    printf("Enter a word: ");
    scanf("%s", word);
    length = strlen(word);

    for (i = 0, j = length - 1; i < length/2; i++, j--) {
        if (word[i] != word[j]) {
            isPal = 0;  //set isPal to false if characters don't match
            break;
        }
    }

    if (isPal) {  //if isPal is still true, print message indicating palindrome
        printf("%s is a palindrome!\n", word);
    } else {
        printf("%s is not a palindrome!\n", word);
    }

    return 0;
}