//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;
    char* answers[10] = {"Yes", "No", "Maybe", "It is uncertain", "The stars say yes", "Outlook not so good", "Signs point to yes", "Cannot predict now", "Better not tell you now", "Reply hazy try again"};
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller program!\n");
    printf("Ask a yes or no question and receive your answer:\n");
    while (1) {
        printf("> ");
        scanf("%d", &num);
        printf("%s\n", answers[rand() % 10]);
    }
    return 0;
}