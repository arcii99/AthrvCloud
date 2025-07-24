//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FORTUNE_COUNT 10

int main()
{
    // Seed for random number generator
    srand((unsigned)time(NULL)); 
    
    char *fortunes[FORTUNE_COUNT] = {
        "You will receive good news soon.",
        "You will face challenges, but overcome them.",
        "Luck will be on your side today.",
        "A new opportunity will present itself to you.",
        "You will find inspiration in an unexpected place.",
        "Be kind to yourself today.",
        "Your hard work will pay off in the near future.",
        "Trust your instincts, they will not lead you astray.",
        "Take time to appreciate the little things in life.",
        "Good things come to those who wait."
    };
    
    // Displaying the fortune
    int index = rand() % FORTUNE_COUNT;
    printf("Your fortune for the day is:\n");
    printf("%s\n", fortunes[index]);
    
    return 0;
}