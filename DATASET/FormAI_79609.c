//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomString(char* buffer, int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        buffer[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    buffer[length] = '\0';
}

int main() {
    int wordCount = 0;
    char inputBuffer[256];

    printf("Welcome to the Typing Speed Test!\n");
    printf("Your goal is to type as many correct words as possible within 30 seconds.\n");
    printf("Ready? Press any key to start the test...\n");
    getchar();

    clock_t start = clock();
    while ((double)(clock() - start) / CLOCKS_PER_SEC < 30) {
        char word[10];
        randomString(word, 5 + rand() % 5);

        printf("\r%s", word);
        fflush(stdout);

        scanf("%s", inputBuffer);

        if (strcmp(word, inputBuffer) == 0) {
            wordCount++;
        }
    }

    printf("\n\nTest complete! You typed %d words in 30 seconds.\n", wordCount);

    return 0;
}