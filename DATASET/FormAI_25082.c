//FormAI DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("My Love Log\n");
    printf("---------------\n");

    char *log = "My love for you grows stronger every day, like the log of our moments together.\n"
                "With each passing minute, our bond becomes more steadfast, and our love more secure.\n"
                "As I look back on our time together, I am filled with happiness and joy,\n"
                "knowing that our journey together has no end.\n"
                "Though we may face challenges, we will do so together, as a team, holding hands and\n"
                "lifting each other up like the logs of a cozy cabin fire.\n"
                "I am never alone because you are always by my side, like the log that warms the flame.\n"
                "Together we can conquer anything, and our love will only grow stronger as we journey on.\n"
                "So take my hand, my love, let us walk hand in hand down the path of life,\n"
                "with our love as strong as the logs that make up the foundation of our home.\n";

    int length = strlen(log);
    char current;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int i;
    for (i = 0; i < length; i++) {
        current = tolower(log[i]);
        if (isalpha(current)) {
            if (current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else if (isdigit(current)) {
            digits++;
        } else if (isspace(current)) {
            spaces++;
        }
    }

    printf("\nStatistics\n");
    printf("---------------\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);

    return 0;
}