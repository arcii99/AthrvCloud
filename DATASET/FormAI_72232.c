//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char questions[10][50] = {"What is my future?", "Will I be successful?", "Should I take this job?", "Will I find love?", "Will I be wealthy?", "What will happen to me next year?", "Should I go on this trip?", "Do I need to change my career?", "What should I do with my life?", "Will I be happy?"};
    char answers[10][100] = {"The future looks bright for you.", "Success is within your reach if you keep working hard.", "Take the job, it will lead to great things.", "Love is unexpected, keep an open mind and heart.", "Wealth is not just measured in monetary terms, focus on the things that bring you happiness.", "Next year will be full of exciting opportunities.", "Traveling is a great way to broaden your perspective on life, go for it!", "Change can be scary, but it’s necessary for growth and development. Consider your options carefully.", "The universe has a path for everyone, it's up to you to find your purpose.", "Happiness is a journey, not a destination."};
    char user_question[50];
    int index;
    char user_choice;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Ask me any question about your future and I will provide you with an answer.\n");

    while (1) {
        printf("\nWhat is your question? ");
        fgets(user_question, 50, stdin);

        printf("\nThinking...\n");

        srand(time(NULL));
        index = rand() % 10;

        printf("The answer to your question \"%s\" is: \"%s\"\n", user_question, answers[index]);

        printf("\nDo you have another question? (y/n): ");
        scanf(" %c", &user_choice);

        if (user_choice == 'n') {
            break;
        }

        // clear the input buffer after reading the user's choice
        while ((getchar()) != '\n');
    }

    printf("\nThank you for using the Automated Fortune Teller! Goodbye.");
    return 0;
}