//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Automated Fortune Teller! Let's see what the future holds for you...\n");
    srand(time(NULL));
    
    char name[20];
    printf("What is your name?\n");
    scanf("%s", name);
    
    int age;
    printf("How old are you?\n");
    scanf("%d", &age);
    
    char question[100];
    printf("Ask me a question about your future...\n");
    getchar(); // clear the input buffer
    fgets(question, 100, stdin);
    
    int fortune = rand() % 5; // generate random number between 0 and 4
    
    printf("\nHmm, let me think...\n");
    switch(fortune) {
        case 0:
            printf("%s, you will meet your future partner in the next year. Keep an open mind and heart!\n", name);
            break;
        case 1:
            printf("%s, you will receive unexpected news that will change your life for the better. Stay positive!\n", name);
            break;
        case 2:
            printf("%s, you will soon travel to a place you have always wanted to go. Enjoy the adventure!\n", name);
            break;
        case 3:
            printf("%s, you will find success in your career by taking risks and working hard. Keep pushing yourself!\n", name);
            break;
        case 4:
            printf("%s, you will experience a period of struggle, but remember that tough times never last. Hang in there!\n", name);
            break;
        default:
            printf("Oops, something went wrong. Please try again later...\n");
            return 1;
    }
    
    printf("Thank you for visiting the Automated Fortune Teller. Come back anytime!\n");
    return 0;
}