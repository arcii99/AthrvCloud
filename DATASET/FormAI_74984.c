//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Create and initialize the fortune array
    char *fortunes[] = {
        "You will be pleasantly surprised today.",
        "The future looks bright for you!",
        "A wonderful opportunity is coming your way.",
        "Your hard work will pay off.",
        "Your kind heart will bring you good karma.",
        "You will soon meet someone special.",
        "An unexpected journey awaits you.",
        "Your creativity will lead you to success."
    };
    int numFortunes = sizeof(fortunes) / sizeof(char *);
    
    // Generate a random number between 0 and numFortunes-1
    int randomIndex = rand() % numFortunes;
    
    // Output the fortune to the user
    printf("Your fortune for today is:\n\n%s\n", fortunes[randomIndex]);
    
    return 0;
}