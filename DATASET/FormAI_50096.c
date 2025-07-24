//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char input[50], prompt[50];
    clock_t start, end;
    double time_taken;
    int count = 0, i;
    
    strcpy(prompt, "Type the following sentence as fast as you can: \"The quick brown fox jumps over the lazy dog\"");
    
    printf("%s\n", prompt);
    start = clock();
    fgets(input, 50, stdin);
    end = clock();
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == prompt[i]) {
            count++;
        }
    }
    
    printf("You typed: %s\n", input);
    printf("Accuracy: %d out of 43 letters\n", count);
    printf("Time taken: %f seconds\n", time_taken);
    
    return 0;
}