//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Welcome to the Automated Fortune Teller program!\n");
    printf("Please type a number between 1 and 10: ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Invalid number entered. Please try again.");
        return 0;
    }

    switch (n) {
        case 1:
            printf("Today is your lucky day! You will receive unexpected good news.\n");
            break;
        case 2:
            printf("It's important that you stay positive, as you have great things ahead.\n");
            break;
        case 3:
            printf("There may be some bumps in the road, but trust your instincts and you will overcome them.\n");
            break;
        case 4:
            printf("Be cautious with your spending habits, as financial trouble may be ahead.\n");
            break;
        case 5:
            printf("Your hard work will pay off soon, keep pushing.\n");
            break;
        case 6:
            printf("Be mindful of others' feelings, as your words may have a big impact.\n");
            break;
        case 7:
            printf("You have a major decision to make soon, but don't rush it - take your time to make the right choice.\n");
            break;
        case 8:
            printf("Your future holds great success, keep up the good work.\n");
            break;
        case 9:
            printf("It's a good time to try new things and step out of your comfort zone.\n");
            break;
        case 10:
            printf("Your loved ones need your attention right now, take some time to show them you care.\n");
            break;
    }
    return 0;
}