//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define fortunes to choose from
    char *fortunes[] = {
        "You will find love in unexpected places.",
        "A great opportunity is coming your way.",
        "You will soon receive a promotion or raise.",
        "Good health will be yours for a long time.",
        "Someone close to you will become a great success.",
        "Your hard work will pay off in the near future.",
        "New friendships will enrich your life.",
        "Adventure awaits you in the coming weeks."
    };

    // Generate a random fortune
    int index = rand() % 8;
    char *fortune = fortunes[index];

    // Print the fortune
    printf("Your fortune for today: %s\n", fortune);

    return 0;
}