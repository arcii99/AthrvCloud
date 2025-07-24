//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char ch, typing_char;
    int count = 0, correct_count = 0, error_count = 0;
    float accuracy = 0, typing_speed = 0;
    clock_t start_time, stop_time;
    double elapsed_time;

    printf("Welcome to Typing Speed Test!\n");
    printf("Type the following text as fast and accurately as possible:\n");
    printf("The quick brown fox jumps over the lazy dog.\n");

    start_time = clock();

    while((ch = getchar()) != '\n'){
        if(isalnum(ch)){
            count++;
            if(ch == getchar()){
                correct_count++;
            } else {
                error_count++;
            }
        }
    }

    stop_time = clock();

    elapsed_time = ((double) (stop_time - start_time)) / CLOCKS_PER_SEC;

    typing_speed = (count / 5) / (elapsed_time / 60);
    accuracy = ((float) correct_count / (correct_count + error_count)) * 100;

    printf("--------------------------------------------\n");
    printf("Typing Speed Test Results:\n");
    printf("Time elapsed: %.2lf seconds\n", elapsed_time);
    printf("Number of characters typed: %d\n", count);
    printf("Accuracy: %.2f%%\n", accuracy);
    printf("Typing Speed: %.2f words per minute\n", typing_speed);
    printf("--------------------------------------------\n");

    return 0;
}