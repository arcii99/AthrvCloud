//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH];
    char generated_str[MAX_LENGTH];
    int i = 0, j = 0;
    int correct_chars = 0, total_chars = 0;
    clock_t start, end;
    double time_taken;

    srand(time(0));
    for(i = 0; i < MAX_LENGTH; i++) {
        str[i] = 'a' + rand() % 26;
    }

    printf("Type this: \n%s\n", str);

    start = clock();
    fgets(generated_str, MAX_LENGTH, stdin);
    end = clock();

    for(i = 0; i < MAX_LENGTH; i++) {
        if(generated_str[i] == '\n') {
            break;
        } else if(str[i] != generated_str[i]) {
            printf("Incorrect! Try again.\n");
            break;
        } else {
            correct_chars++;
            total_chars++;
        }
    }

    while(generated_str[i]) {
        if(generated_str[i] == '\n') {
            break;
        } else {
            total_chars++;
        }
        i++;
    }

    if(correct_chars == MAX_LENGTH) {
        printf("Congratulations! You typed all the characters correctly!\n");
    } else {
        printf("You typed %d out of %d characters correctly!\n", correct_chars, total_chars);
    }

    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to type: %f seconds\n", time_taken);

    return 0;
}