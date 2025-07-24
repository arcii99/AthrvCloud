//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune_teller() {
    int answer;
    srand(time(NULL));
    answer = rand() % 10 + 1;

    switch (answer) {
        case 1:
            printf("Your future looks bright!\n");
            break;
        case 2:
            printf("You should be cautious in your financial decisions.\n");
            break;
        case 3:
            printf("Your love life will soon blossom.\n");
            break;
        case 4:
            printf("You will face challenges in the near future, but you will overcome them.\n");
            break;
        case 5:
            printf("Your hard work will pay off, keep pushing forward.\n");
            break;
        case 6:
            printf("It would be wise to take a break and focus on self-care.\n");
            break;
        case 7:
            printf("Good news is on the horizon!\n");
            break;
        case 8:
            printf("You will receive unexpected help from someone close to you.\n");
            break;
        case 9:
            printf("Your creativity and intelligence will take you far in life.\n");
            break;
        case 10:
            printf("The decisions you make now will greatly impact your future.\n");
            break;
        default:
            printf("Error: invalid answer.\n");
    }
}

int main() {
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Generating your fortune...\n\n");
    fortune_teller();
    return 0;
}