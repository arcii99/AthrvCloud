//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to our Typing Speed Test!\n");
    printf("You will have to type a few sentences and we will measure how many words per minute you can type.\n");

    FILE *fp = fopen("sentences.txt", "r");
    if (fp == NULL) {
        printf("Error opening the sentences file.\n");
        return 1;
    }

    char sentences[10][50];
    int i = 0;
    while (fgets(sentences[i], 50, fp) != NULL) {
        i++;
    }
    fclose(fp);

    srand(time(NULL));
    int rand_num = rand() % i;
    printf("Type the following sentence: %s", sentences[rand_num]);
    
    clock_t start_time, end_time;
    double total_time;

    start_time = clock();
    char typed_sentence[50];
    fgets(typed_sentence, 50, stdin);
    end_time = clock();

    total_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    int words = 1;
    for (int j = 0; j < 50; j++) {
        if (typed_sentence[j] == ' ') {
            words++;
        }
    }

    double wpm = (double) words / total_time * 60;
    printf("You typed %d words in %.2f seconds. Your typing speed is %.2f words per minute!\n", words, total_time, wpm);

    return 0;
}