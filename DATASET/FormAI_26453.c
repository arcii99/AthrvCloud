//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ultraprecise
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 10
#define MIN_LEN 4
#define MAX_LEN 10
#define TEST_DURATION 60 // test duration in seconds
#define BUFFER_SIZE 200

int main() {
    char buffer[BUFFER_SIZE];
    const char* words[MAX_WORDS] = {"apple", "banana", "cherry", "dragonfruit", "elderberry",
                                    "fig", "grape", "honeydew", "kiwi", "lemon"}; // list of words to type
    int word_count = sizeof(words) / sizeof(words[0]); // number of words in the list
    int i, j, len, count, correct_count = 0, total_count = 0;
    time_t start_time, current_time;
    double elapsed_time;
    
    srand(time(NULL));
    
    printf("Welcome to the Typing Speed Test Program!\n\n");
    printf("Instructions:\n");
    printf("Type as many words from the list below as you can in %d seconds.\n", TEST_DURATION);
    printf("Each word must be at least %d and at most %d letters long.\n", MIN_LEN, MAX_LEN);
    printf("The test will begin as soon as you press Enter.\n\n");
    
    printf("Words: ");
    for (i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");
    
    printf("Press Enter to start the test...");
    fgets(buffer, BUFFER_SIZE, stdin); // wait for user to press Enter
    
    time(&start_time);
    do {
        // pick a random word
        j = rand() % word_count; 
        len = MIN_LEN + rand() % (MAX_LEN - MIN_LEN + 1);
        for (i = 0; i < len; i++) {
            printf("%c", words[j][i]);
        }
        printf(" ");
        
        // wait for user input
        count = 0;
        do {
            buffer[count] = getchar();
            if (buffer[count] != '\n') {
                printf("%c", buffer[count]);
            }
            count++;
        } while (buffer[count-1] != ' ' && buffer[count-1] != '\n' && count < BUFFER_SIZE-1);
        buffer[count-1] = '\0';
        
        // check if input matches the generated word
        if (strcmp(buffer, words[j]) == 0) {
            printf("CORRECT!\n");
            correct_count++;
        }
        else {
            printf("WRONG!\n");
        }
        total_count++;
        
        time(&current_time);
        elapsed_time = difftime(current_time, start_time);
        
    } while (elapsed_time < TEST_DURATION);
    
    printf("\n\nTest finished!\n");
    printf("Total words typed: %d\n", total_count);
    printf("Correct words typed: %d\n", correct_count);
    printf("Accuracy: %.1f%%\n", (double) correct_count / total_count * 100);
    printf("Typing speed: %.1f words per minute\n", (double) total_count / elapsed_time * 60);
    
    return 0;
}