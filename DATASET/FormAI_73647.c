//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    char answers[10][50] = {
        "The future is bright for you.",
        "A major change is coming soon.",
        "You will receive good news in the near future.",
        "Opportunities are coming your way.",
        "You will face challenges, but come out stronger.",
        "Be open to new experiences and opportunities.",
        "A romantic relationship is on the horizon.",
        "Take risks and trust your instincts.",
        "Avoid making impulsive decisions.",
        "Success will come with hard work and determination."
    };

    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller Program!\n\n");

    while (1) {
        printf("Please enter your question (type 'exit' to end the program): ");
        char question[100];
        fgets(question, sizeof(question), stdin);

        if (strcmp(question, "exit\n") == 0) {
            break;
        }

        printf("Consulting the crystal ball...\n");

        int index = rand() % 10;
        printf("Your answer: %s\n", answers[index]);
    }

    printf("Thank you for using the Automated Fortune Teller Program!\n");

    return 0;
}