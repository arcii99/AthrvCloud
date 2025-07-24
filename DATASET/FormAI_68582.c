//FormAI DATASET v1.0 Category: Word Count Tool ; Style: random
#include <stdio.h>
#include <string.h>

//Function for counting number of words
int countWords(char *string) {
    int words = 1;
    for(int i = 0; string[i] != '\0'; i++) {
        if (string[i] == ' ' && string[i+1] != ' ') {
            words++;
        }
    }
    return words;
}

//Main function
int main() {
    char input[100];
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);
    //Removing newline character
    input[strcspn(input, "\n")] = 0;
    printf("Your sentence has %d words.\n", countWords(input));
    return 0;
}