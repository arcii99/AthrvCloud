//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the fortune array with fortunes
char *fortunes[] = {"You will have a great day today.",
                    "Unexpected joy is coming your way.",
                    "Be mindful of your surroundings.",
                    "Your dreams will come true soon.",
                    "You will receive good news in the near future.",
                    "Take risks and reap rewards.",
                    "Your hard work will pay off.",
                    "A new opportunity is on the horizon.",
                    "Believe in yourself and others will believe in you.",
                    "You will find love in unexpected places."};

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 0 and 9
    int random_number = rand() % 10;

    // Print the selected fortune from the array
    printf("Your fortune for today is:\n\n%s\n", fortunes[random_number]);

    return 0;
}