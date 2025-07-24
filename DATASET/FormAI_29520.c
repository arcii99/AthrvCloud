//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char input[100];

    printf("Enter a sentence to analyze: ");
    fgets(input, 100, stdin);

    int happy_count = 0;
    int sad_count = 0;

    char *token = strtok(input, " ");

    while (token != NULL) {
        if (strcmp(token, "happy") == 0 || strcmp(token, "joyful") == 0 || strcmp(token, "excited") == 0) {
            happy_count++;
        } else if (strcmp(token, "sad") == 0 || strcmp(token, "depressed") == 0 || strcmp(token, "gloomy") == 0) {
            sad_count++;
        }
        token = strtok(NULL, " ");
    }

    if (happy_count > sad_count) {
        printf("This sentence is mostly happy!\n");
    } else if (sad_count > happy_count) {
        printf("This sentence is mostly sad :(\n");
    } else {
        printf("This sentence has a neutral sentiment.\n");
    }

    return 0;
}