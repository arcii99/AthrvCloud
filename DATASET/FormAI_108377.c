//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int min, int max);

int main() {
    // Initialize the random number generator with a seed value
    srand(time(NULL));

    int fortunesCount = 7;

    char *fortunes[] = {
        "A beautiful, smart, and loving person will be coming into your life.",
        "A lifetime of happiness lies ahead of you.",
        "A pleasant surprise is in store for you.",
        "Adventure can be real happiness.",
        "All your hard work will soon pay off.",
        "Believe in yourself and others will too.",
        "You will succeed in whatever you set your mind to."
    };

    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("What is your name? ");

    char name[50];
    scanf("%s", name);

    printf("Hello, %s!\n", name);
    printf("Now, think of a question you want to ask the fortune teller and press enter to continue.\n");

    char question[100];
    getchar();
    fgets(question, 100, stdin);

    int randomIndex = generateRandomNumber(0, fortunesCount - 1);
    printf("\n%s\n", fortunes[randomIndex]);

    return 0;
}

// Returns a random integer between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}