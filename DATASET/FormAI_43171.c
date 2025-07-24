//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //seeds random number generator with current time
    int fortune = rand() % 10; //generates a random number between 0 and 9
    printf("Welcome to the Automated Fortune Teller!\n");

    switch(fortune) {
        case 0:
            printf("Today is the perfect day to pursue your dreams. Don't hold back!\n");
            break;
        case 1:
            printf("Your hard work is paying off. Soon, success will be yours.\n");
            break;
        case 2:
            printf("You will soon meet someone who will change your life for the better.\n");
            break;
        case 3:
            printf("Your future looks bright. Keep pushing forward!\n");
            break;
        case 4:
            printf("Be cautious with your finances. Unexpected expenses may arise.\n");
            break;
        case 5:
            printf("Change is coming. Embrace it with an open mind.\n");
            break;
        case 6:
            printf("You will encounter a challenge soon, but you have the strength to overcome it.\n");
            break;
        case 7:
            printf("Take some time to focus on self-care. Your mental health is important.\n");
            break;
        case 8:
            printf("A new opportunity will present itself to you soon. Don't be afraid to take it.\n");
            break;
        case 9:
            printf("Your hard work may not pay off immediately, but don't give up. Success is still within reach.\n");
            break;
        default:
            printf("Something went wrong. Please try again later.\n");
            break;
    }
    return 0;
}