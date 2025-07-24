//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Magical Spam Detection Function
int detect(char* message) {
    int i = 0, count = 0, total_score = 0;
    char c;
    while ((c = message[i++]) != '\0') {
        if (c == 'c' || c == 'C') {
            count++;
        } else if (count > 0 && (c == 'r' || c == 'R')) {
            total_score += count * 2;
            count = 0;
        } else {
            count = 0;
        }
    }
    return total_score;
}

int main() {
    printf("Welcome to our Surreal C Spam Detection System!\n");
    printf("Please enter a message: ");

    char* message = (char*)malloc(sizeof(char) * 1000);
    gets(message);

    int score = detect(message);

    if (score > 0) {
        printf("Warning: This message is suspected spam!\n");
        printf("Spam Score: %d\n", score);
    } else {
        printf("This message appears to be safe.\n");
    }

    free(message);

    return 0;
}