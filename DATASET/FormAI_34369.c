//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the automated fortune teller!\n");
    // Initialize random seed
    srand(time(0));
    // Generate random number between 0 and 4
    int random_num = rand() % 5;
    
    // Use random number to select a fortune
    if (random_num == 0) {
        printf("Your future looks bright!\n");
    } else if (random_num == 1) {
        printf("You will face a challenge soon, but you will overcome it.\n");
    } else if (random_num == 2) {
        printf("Luck is on your side. Use it wisely.\n");
    } else if (random_num == 3) {
        printf("Beware of those you trust. They may not have your best interests at heart.\n");
    } else {
        printf("Opportunities will come your way. Don't be afraid to take risks.\n");
    }
    return 0;
}