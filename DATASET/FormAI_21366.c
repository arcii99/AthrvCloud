//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Define an array of fortunes
    const char *fortunes[] = {
        "Fortune favors the brave.",
        "You will have a long and happy life.",
        "Good things come to those who wait.",
        "Your future is bright.",
        "You will find true love soon.",
        "A new adventure awaits you.",
        "Your hard work will pay off.",
        "Tomorrow is another day.",
        "Good things come in small packages.",
        "Life is like a box of chocolates.",
        "Your talents will be recognized.",
        "Don't be afraid to take risks.",
        "You will find success in everything you do."
    };
    
    // Generate a random index to choose a fortune
    int index = rand() % (sizeof(fortunes) / sizeof(char *));
    const char *fortune = fortunes[index];
    
    // Print the fortune
    printf("Your fortune for today is:\n\n%s\n", fortune);
    
    return 0;
}