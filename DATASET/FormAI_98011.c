//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up the random number generator
    srand(time(NULL));
    
    // Define the fortune options
    char* fortunes[] = {
        "You will find love in unexpected places.",
        "Good fortune will come your way.",
        "You will be paid handsomely for your hard work.",
        "A new opportunity will present itself.",
        "Your dreams will become a reality.",
        "Someone important will enter your life.",
        "You will go on an amazing adventure.",
        "Your creative talents will be recognized.",
        "Happiness is just around the corner.",
        "Your hard work will pay off in the near future.",
        "Your health will improve.",
        "You will meet someone special soon.",
        "A long lost friend will reappear.",
        "Your financial situation will improve.",
        "You will receive a surprise gift.",
        "Inner peace is on its way to you.",
        "Your luck is about to change."
    };
    
    // Get the user's name and ask if they want a fortune told
    char name[100];
    printf("Hello! What is your name?\n");
    fgets(name, 100, stdin);
    printf("Hello, %s! Would you like me to tell your fortune? (y/n)\n", name);
    
    char fortuneAnswer[2];
    fgets(fortuneAnswer, 2, stdin);
    
    if (fortuneAnswer[0] == 'y') {
        // Choose a random fortune to display
        int randomFortuneIndex = rand() % 17;
        printf("Your fortune is: %s\n", fortunes[randomFortuneIndex]);
    } else {
        printf("Okay, maybe next time!\n");
    }
    
    return 0;
}