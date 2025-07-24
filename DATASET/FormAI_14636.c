//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 3000
#define MAX_WORD_LENGTH 20

int score = 0;
int total_words = 0;
char words[MAX_WORDS][MAX_WORD_LENGTH];
char input[MAX_WORD_LENGTH];

void load_words()
{
    FILE* fp;
    fp = fopen("words.txt", "r");
    if(fp == NULL) {
        printf("Error: Unable to open words file.");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_WORD_LENGTH];
    int i = 0;
    while(fgets(buffer, MAX_WORD_LENGTH, fp)) {
        buffer[strcspn(buffer, "\n")] = 0;
        strcpy(words[i], buffer);
        i++;
    }
    total_words = i;

    fclose(fp);
}

void shuffle_words()
{
    srand(time(NULL));
    for(int i = 0; i < total_words; i++) {
        int random_index = rand() % total_words;
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, words[i]);
        strcpy(words[i], words[random_index]);
        strcpy(words[random_index], temp);
    }
}

void print_words()
{
    for(int i = 0; i < total_words; i++) {
        printf("%d. %s\n", i+1, words[i]);
    }
}

void start_test()
{
    printf("Type as many words as you can in 60 seconds:\n\n");

    time_t start_time, end_time;
    double time_elapsed = 0;
    time(&start_time);

    int i = 1;
    while(time_elapsed < 60) {
        printf("%d. ", i);
        scanf("%s", input);
        if(strcmp(input, words[i-1]) == 0) {
            score++;
        }
        i++;
        time(&end_time);
        time_elapsed = difftime(end_time, start_time);
    }
    printf("\nTime's up!\n");

    int accuracy = (score * 100) / (i - 1);
    printf("\nWords typed: %d", i-1);
    printf("\nScore: %d", score);
    printf("\nAccuracy: %d%%", accuracy);
}

int main()
{
    load_words();
    shuffle_words();
    print_words();
    start_test();
    return 0;
}