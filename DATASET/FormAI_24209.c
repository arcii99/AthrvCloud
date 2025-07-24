//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    int count = 0, prev_space = 0, curr_space;
    
    printf("Welcome to the Happy C Code Count Tool! \n");
    printf("Please enter the C code snippet to be counted: \n");
    
   fgets(input, sizeof(input), stdin);
    
    // loop through each character in input
    for (int i = 0; i < strlen(input); i++) {
        curr_space = (input[i] == ' ' || input[i] == '\n' || input[i] == '\t');
        // if we find a space and the previous character wasn't a space
        if (prev_space == 0 && curr_space == 1) {
            count++;
        }
        prev_space = curr_space;
    }
    
    // add one to count to account for the final word
    count++;
    
    printf("There are %d words in the C code snippet you entered! \n", count);
    
    return 0;
}