//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateFortune() {
    int r = rand() % 10;
    switch(r) {
        case 0:
            printf("Your future is bright.\n");
            break;
        case 1:
            printf("You will come into a large sum of money.\n");
            break;
        case 2:
            printf("Avoid taking risks in the near future.\n");
            break;
        case 3:
            printf("You will meet someone special soon.\n");
            break;
        case 4:
            printf("Your hard work will pay off.\n");
            break;
        case 5:
            printf("Watch out for the color red.\n");
            break;
        case 6:
            printf("Do not trust strangers in the coming days.\n");
            break;
        case 7:
            printf("You will receive unexpected news.\n");
            break;
        case 8:
            printf("Your health will improve.\n");
            break;
        case 9:
            printf("Your creativity will be at an all-time high.\n");
            break;
        default:
            printf("Your fortune is unclear at this time.\n");
    }
}

int main() {
    srand(time(NULL));
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please ask your question.\n");
    
    char question[100];
    fgets(question, sizeof(question), stdin);
    
    printf("Thinking...\n");
    printf("Your fortune says:\n");
    generateFortune();
    
    return 0;
}