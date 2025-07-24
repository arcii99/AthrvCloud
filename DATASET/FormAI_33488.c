//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int spam = 0;
    int words = 0;
    double spam_ratio;

    printf("Enter your message: ");
    fgets(message, 1000, stdin);

    char* ptr = strtok(message, " ");

    while(ptr != NULL) {
        words++;

        if(strcmp("buy", ptr) == 0 || strcmp("offer", ptr) == 0 || strcmp("win", ptr) == 0) {
            spam++;
        }

        ptr = strtok(NULL, " ");
    }

    spam_ratio = (double)spam / words * 100;

    if(spam_ratio < 20) {
        printf("Email is not spam.\n");
    } else {
        printf("Email is spam.\n");
    }

    return 0;
}