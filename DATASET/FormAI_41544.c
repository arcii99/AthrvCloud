//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 50

void generate_text(char text[]) {
    int i;
    for(i = 0; i < MAX_LEN; i++) {
        text[i] = rand() % 26 + 'a';
    }
    text[i] = '\0';
}

int main() {
    char user_input[MAX_LEN];
    char generated_text[MAX_LEN];
    unsigned long long start_time, end_time, typing_time;
    int i, errors = 0;
    
    srand(time(0));
    
    generate_text(generated_text);
    printf("Type the following text as fast and accurately as possible:\n%s\n", generated_text);
    
    start_time = time(0);
    fgets(user_input, sizeof(user_input), stdin);
    end_time = time(0);
    
    typing_time = end_time - start_time;
    
    for(i = 0; i < MAX_LEN; i++) {
        if(generated_text[i] != user_input[i]) {
            errors++;
        }
    }
    
    printf("Your typing speed test results:\n");
    printf("Time elapsed: %llu seconds\n", typing_time);
    printf("Errors: %d\n", errors);
    printf("Accuracy: %.2f%%\n", (float)(MAX_LEN-errors)/MAX_LEN*100);
    
    return 0;
}