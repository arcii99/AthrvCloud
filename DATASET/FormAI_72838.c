//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL)); // Seed random number generator
    
    char sentence[100] = "The quick brown fox jumps over the lazy dog"; // Sample sentence to test typing speed
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("Please type the following sentence as fast as you can:\n%s\n\n", sentence);
    
    // Shuffle sentence words
    char words[12][10] = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "\0"};
    int i, j;
    char temp[10];
    for(i = 0; i < 10; i++) {
        j = rand() % 9;
        strcpy(temp, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], temp);
    }
    
    // Display shuffled sentence words
    printf("Shuffled words:\n");
    for(i = 0; i < 9; i++) {
        printf("%s ", words[i]);
    }
    
    // Get user input and calculate typing speed
    printf("\n\nType the shuffled sentence and press Enter:\n");
    char input[100];
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character
    int errors = 0;
    float time_elapsed;
    clock_t start = clock();
    for(i = 0; i < 9; i++) {
        if(strcmp(words[i], strtok(input, " ")) != 0) {
            errors++;
        }
    }
    clock_t end = clock();
    time_elapsed = (float)(end - start) / CLOCKS_PER_SEC;
    
    // Display results
    printf("\nResults:\n");
    printf("Time elapsed: %.2f seconds\n", time_elapsed);
    printf("Errors: %d\n", errors);
    printf("Typing speed: %.2f words per minute\n", (60 / time_elapsed) * (9 - errors));
    
    return 0;
}