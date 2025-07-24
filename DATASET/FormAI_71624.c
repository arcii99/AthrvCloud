//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to get a random fortune
char* getFortune() {
    // array of possible fortunes
    char* fortunes[] = {
        "You will have a successful career.",
        "Your relationships will bring you happiness.",
        "You will experience great adventures in the future.",
        "Your hard work will pay off.",
        "Your creativity will lead to success.",
        "You will meet someone special soon.",
        "Your financial situation will improve.",
        "You will receive good news this week.",
        "Your health will continue to improve.",
        "You will travel to new and exciting places."
    };
    
    // get the number of fortunes in the array
    int numFortunes = sizeof(fortunes) / sizeof(fortunes[0]);
    
    // get a random number between 0 and numFortunes - 1
    srand(time(NULL));
    int randomIndex = rand() % numFortunes;
    
    // return the random fortune
    return fortunes[randomIndex];
}

int main() {
    // get a random fortune
    char* fortune = getFortune();
    
    // print the fortune
    printf("Your fortune for today is:\n%s\n", fortune);
    
    return 0;
}