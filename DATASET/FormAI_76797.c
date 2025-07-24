//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));  // so that we can use rand() function to get the random words
    
    char words[10][10] = { 
        {"apple" }, {"banana"}, {"cherry"}, {"date"}, {"eggplant"},
        {"fig"}, {"grape"}, {"honeydew"}, {"kiwi"}, {"lemon"}
    };  // words for typing speed test
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the words that appear on the screen and press Enter.\n");
    printf("You will be given 10 random words to type in total.\n\n");
    
    int correctCount = 0;
    for (int i = 0; i < 10; i++) {
        int randomIndex = rand() % 10;  // get random word index from the array
        
        printf("Word %d:\t%s\n", i+1, words[randomIndex]);
        
        char input[10];
        scanf("%s", input);  // get user input
        
        if (strcmp(input, words[randomIndex]) == 0) {  // compare input with the random word
            printf("Correct!\n");
            correctCount++;
        } else {
            printf("Incorrect!\n");
        }
    }
    
    printf("\nYou typed %d words correctly out of 10.\n", correctCount);
    
    return 0;
}