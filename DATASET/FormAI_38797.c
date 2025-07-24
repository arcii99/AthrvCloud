//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    // Set up the random number generator
    srand(time(NULL));
    
    // Define the possible fortunes
    char* fortunes[] = {"A great opportunity is coming your way.",
                        "You will receive unexpected good news soon.",
                        "You have the power to shape your own future.",
                        "Your hard work will pay off in the end.",
                        "Good things come to those who wait, keep holding on.",
                        "Don't give up, your dreams are closer than you think.",
                        "Believe in yourself and your abilities.",
                        "Luck is on your side, take a chance.",
                        "A new adventure awaits you, take the leap!",
                        "Happiness is right around the corner."};
                        
    // Get the user's name
    char name[25];
    printf("Welcome to the Automated Fortune Teller! Please enter your name: ");
    scanf("%s", name);
    
    // Generate a random number and use it to pick a fortune
    int index = rand() % 10;
    char* fortune = fortunes[index];
    
    // Display the fortune to the user
    printf("\n%s, your fortune for today is:\n", name);
    printf("%s\n", fortune);
    
    return 0;
}