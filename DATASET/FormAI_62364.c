//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generate_fortune() {
    char *fortunes[] = {
        "A new adventure awaits you.",
        "A smooth long journey!",
        "All the troubles you have will pass away very quickly.",
        "An important decision will have to be made.",
        "Careful planning will result in success.",
        "Good things come to those who wait.",
        "Opportunities are headed your way.",
        "The future is not far from you."
    };
    int num_fortunes = sizeof(fortunes) / sizeof(char *);

    int index = rand() % num_fortunes;
    printf("%s\n", fortunes[index]);
}

void ask_question() {
    char question[256];

    printf("What is your question?\n");
    fgets(question, sizeof(question), stdin);

    // Strip newline character from input
    if (strlen(question) > 0 && question[strlen(question) - 1] == '\n') {
        question[strlen(question) - 1] = '\0';
    }

    if (strlen(question) == 0) {
        printf("You must ask a question.\n");
        ask_question();
    }

    printf("Thinking...\n");
    generate_fortune();

    char response[10];

    printf("Would you like to ask another question? (yes or no)\n");
    fgets(response, sizeof(response), stdin);

    // Strip newline character from input
    if (strlen(response) > 0 && response[strlen(response) - 1] == '\n') {
        response[strlen(response) - 1] = '\0';
    }

    if (strcmp(response, "yes") == 0) {
        ask_question();
    } else if (strcmp(response, "no") == 0) {
        printf("Goodbye!\n");
    } else {
        printf("Please respond with \"yes\" or \"no\".\n");
        ask_question();
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n");
    ask_question();

    return 0;
}