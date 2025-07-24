//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 50
#define MAX_LEN 30

void print_title() {
    printf("---TYPING SPEED TEST---\n\n");
}

void print_instructions() {
    printf("Type the words as they appear on the screen.\nPress Enter after each word to continue.\nType 'exit' to quit.\n\n");
}

int get_random_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    char words[MAX_WORDS][MAX_LEN] = {"apple", "banana", "cherry", "orange", "grape", "lemon", "melon", "pear", "kiwi", "pineapple", "peach", "plum", "raspberry", "strawberry", "blueberry", "watermelon", "apricot", "pomegranate", "mango", "coconut", "avocado", "fig", "guava", "lime", "papaya", "persimmon", "blackberry", "cranberry", "currant", "gooseberry", "nectarine", "peanut", "pistachio", "cashew", "walnut", "almond", "hazelnut", "pecan", "macadamia", "chestnut", "acorn", "thimbleberry", "boysenberry", "loganberry", "elderberry", "mulberry", "huckleberry", "quince"};

    int num_words = sizeof(words) / sizeof(words[0]);

    srand(time(NULL));
    
    int num_correct = 0;
    int num_words_typed = 0;
    double time_elapsed = 0;

    print_title();
    print_instructions();
    
    while (1) {
        int random_index = get_random_num(0, num_words - 1);
        printf("%s ", words[random_index]);
        
        char input[MAX_LEN];
        fgets(input, MAX_LEN, stdin);
        
        if (strcmp(input, "exit\n") == 0) {
            break;
        } else if (strcmp(input, "\n") == 0) {
            num_words_typed++;
            if (strcmp(words[random_index], input) == 0) {
                num_correct++;
            }
        }
    }
    
    printf("\n---RESULTS---\n");
    printf("Number of words typed: %d\n", num_words_typed);
    printf("Number of correct words: %d\n", num_correct);
    time_elapsed = (double)clock() / CLOCKS_PER_SEC;
    printf("Time elapsed: %f seconds\n", time_elapsed);
    
    return 0;
}