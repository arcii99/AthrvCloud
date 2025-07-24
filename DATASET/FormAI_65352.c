//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int i, j, k, n = 10, temp;
    char c[100];
    
    srand(time(0)); // Random seed based on current time
    
    char words[][20] = {"hello", "world", "typing", "speed", "test", "program", "coding", "challenge", "fun", "learning"};
    
    printf("Welcome to the Typing Speed Test program! You will be given 10 random words that you need to type as quickly and accurately as possible.\n");
    printf("Press any key to start the typing test.\n");
    
    getchar();
    
    // Shuffle the words array
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        strcpy(c, words[i]);
        strcpy(words[i], words[j]);
        strcpy(words[j], c);
    }
    
    clock_t start = clock(); // Start timer
    
    for (i = 0; i < n; i++) {
        printf("%s\n", words[i]);
        fflush(stdout); // Make sure the word is printed immediately
        
        scanf("%s", c);
        
        if (strcmp(c, words[i]) != 0) {
            // Incorrect word
            printf("Incorrect. Try again.\n\n");
            i--; // Repeat current word
        }
        else {
            printf("Correct!\n\n");
        }
    }
    
    // Calculate typing speed and time taken
    double time_taken = (double)(clock() - start) / CLOCKS_PER_SEC;
    int characters_typed = 0;
    for (i = 0; i < n; i++) {
        characters_typed += strlen(words[i]);
    }
    int typing_speed = (int)((characters_typed / time_taken) * 60);
    
    printf("Congratulations! You have completed the Typing Speed Test.\n");
    printf("You typed %d characters in %.2f seconds.\n", characters_typed, time_taken);
    printf("Your typing speed is %d characters per minute.\n", typing_speed);
    
    return 0;
}