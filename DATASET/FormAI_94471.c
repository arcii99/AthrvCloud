//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    const char words[10][10] = {"apple", "banana", "cherry", "grape", "kiwi", "lemon", "mango", "orange", "peach", "strawberry"};
    char input[10];
    int correct_words = 0;
    clock_t start, end;
    double cpu_time_used;
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the word displayed on the screen as fast as you can.\n");
    printf("Type 'exit' to exit the program.\n");
    
    while(1) {
        srand(time(NULL));
        int index = rand() % 10;
        printf("\n%s\n", words[index]);
        
        start = clock();
        scanf("%s", input);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        if(strcmp(input, "exit") == 0) {
            printf("\nThank you for playing the Typing Speed Test.\n");
            break;
        }
        if(strcmp(input, words[index]) == 0) {
            correct_words++;
            printf("Correct! Your time: %lf seconds.\n", cpu_time_used);
        } else {
            printf("Incorrect. The correct word is: %s\n", words[index]);
        }
    }
    
    printf("\nYou typed %d words correctly.\n", correct_words);
    
    return 0;
}