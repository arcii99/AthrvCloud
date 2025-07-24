//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_instructions() {
    printf("Welcome to the Genius Typing Speed Test!\n");
    printf("Type the words as fast as you can and press enter after each word.\n");
    printf("When you are ready, press Enter to start the test.\n");
    getchar();
    printf("3..\n");
    sleep(1);
    printf("2..\n");
    sleep(1);
    printf("1..\n");
    sleep(1);
    printf("Go!\n");
}

int main() {
    char* words[] = {"genius", "programming", "algorithm", "informatics", "problem", "solution", "software", "engineering", "code", "compiler", "data", "structure", "computer", "science", "keyboard", "internet", "network", "function", "library", "variable"};
    srand(time(0));
    int score = 0;
    print_instructions();
    time_t start_time = time(0);
    while (score < 20) {
        int random_index = rand() % 20;
        char word[15];
        printf("%s: ", words[random_index]);
        scanf("%s", word);
        if (strcmp(word, words[random_index]) == 0) {
            score++;
            printf("Correct!\n");
        } else {
            printf("Incorrect!\n");
        }
        sleep(1);
    }
    time_t end_time = time(0);
    int total_time = (int)(end_time - start_time);
    printf("\nCongratulations! You typed 20 words in %d seconds.\n", total_time);
    printf("Your typing speed is %.2f words per minute.\n", (float)score * 60 / total_time);
    return 0;
}