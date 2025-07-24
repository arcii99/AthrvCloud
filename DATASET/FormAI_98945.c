//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void shuffle(char *array, size_t n){
    if (n > 1){
        size_t i;
        for (i = 0; i < n - 1; i++){
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          char temp = array[j];
          array[j] = array[i];
          array[i] = temp;
        }
    }
}

int main() {
    char input[100];
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}[];':\"\\|,.<>/?";
    shuffle(characters, strlen(characters));
    int i;
    printf("Welcome to the Typing Speed Test Program\n\nYou will be given 60 seconds to type as many random characters as you can\n\nPress Enter to start!");
    fgets(input, 99, stdin);
    printf("\n%s\n\n", characters);
    time_t start = time(NULL);
    int score = 0;
    while (time(NULL) < (start + 60)){
        printf("Type the above characters: ");
        fgets(input, 99, stdin);
        if (strcmp(input, characters) == 0){
            score++;
            printf("Correct! Score: %d\n", score);
            shuffle(characters, strlen(characters));
        } else {
            printf("Incorrect\n");
        }
    }
    printf("\nTime is up!\n\nYou scored %d\n", score);
    return 0;
}