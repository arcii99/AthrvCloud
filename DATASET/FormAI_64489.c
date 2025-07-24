//FormAI DATASET v1.0 Category: Word Count Tool ; Style: lively
#include <stdio.h>

// function to count words in a given string
int countWords(char str[]) {
    int count = 0;
    for(int i = 0; str[i]!='\0'; i++) {
        if(str[i] == ' ' || str[i] == '\n'|| str[i] == '\t') {
            count++;
        }
    }
    return count+1; // add 1 to include the last word
}

int main() {
    // declare the input string
    char inputString[100];

    // get user input
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    // use the countWords function to count the number of words in the input string
    int wordCount = countWords(inputString);

    // print the result
    printf("The word count of the input string is: %d\n", wordCount);

    return 0;
}

// Example Input: "Hello, world! This is a test string."
// Example Output: The word count of the input string is: 7