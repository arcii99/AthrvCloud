//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    char* question;
    char* answer;
} fortune_t;

fortune_t fortune_list[] = {
    {"Will I get rich?", "It is certain"},
    {"Will I ever find love?", "Outlook good"},
    {"Am I going to have a good day?", "Reply hazy, try again"},
    {"Is there going to be an earthquake?", "Don't count on it"},
    {"Will I pass my exams?", "It is decidedly so"},
    {"Will I get a promotion?", "As I see it, yes"},
    {"Should I move abroad?", "Cannot predict now"},
    {"Will my business succeed?", "Without a doubt"},
    {"Am I going to be famous?", "Signs point to yes"},
    {"Will I ever be able to retire?", "Ask again later"}
};

int fortune_list_size = sizeof(fortune_list) / sizeof(fortune_t);

void print_fortune(fortune_t fortune) {
    printf("\n==========================\n\n");
    printf("Question: %s\n", fortune.question);
    printf("Answer: %s\n", fortune.answer);
    printf("\n==========================\n\n");
}

void ask_question(char* question) {
    printf("You asked: %s\n", question);
    sleep(2);

    printf("\nThinking...\n\n");
    sleep(2);

    srand(time(NULL));
    fortune_t fortune = fortune_list[rand() % fortune_list_size];
    print_fortune(fortune);
}

void print_instructions() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("To begin, enter a question.\n");
    printf("To exit, enter 'exit' or 'quit'.\n\n");
}

int main() {
    char input[256];

    print_instructions();

    while (1) {
        printf(">>> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if(strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        ask_question(input);
    }
    return 0;
}