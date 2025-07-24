//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool contains_spam(char* text) {
    const char* spam[] = {"cyber", "netrunners", "hackers", "cyberpsychos", "corpos"};
    const int spam_count = sizeof(spam) / sizeof(spam[0]);
    for (int i = 0; i < spam_count; ++i) {
        if (strstr(text, spam[i]) != NULL) {
            return true;
        }
    }
    return false;
}

int main() {
    printf("------------\n");
    printf("- CYBERSEC -\n");
    printf("------------\n");

    printf("\nEnter message:\n");
    char input[1000];
    fgets(input, 1000, stdin);

    if (contains_spam(input)) {
        printf("\nSPAM DETECTED\n");
    } else {
        printf("\nSPAM NOT DETECTED\n");
    }
    return 0;
}