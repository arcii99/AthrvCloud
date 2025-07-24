//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Generate random fortune number
    int fortune_number = rand() % 10 + 1;

    // Assign fortune based on number
    char* fortune;
    switch (fortune_number) {
        case 1:
            fortune = "You will find love in unexpected places.";
            break;
        case 2:
            fortune = "Your hard work will pay off in the near future.";
            break;
        case 3:
            fortune = "Travel is in your future.";
            break;
        case 4:
            fortune = "A great opportunity is on the horizon.";
            break;
        case 5:
            fortune = "You will meet someone who will change your life.";
            break;
        case 6:
            fortune = "Your finances will improve in the coming months.";
            break;
        case 7:
            fortune = "A new job or promotion is in store for you.";
            break;
        case 8:
            fortune = "A creative project or hobby will bring you joy.";
            break;
        case 9:
            fortune = "You will make a new friend who will become very important to you.";
            break;
        case 10:
            fortune = "Your future is bright and full of possibilities.";
            break;
        default:
            fortune = "Error: invalid fortune number.";
    }

    // Print fortune
    printf("Your fortune for today is: %s\n", fortune);

    return 0;
}