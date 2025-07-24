//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototype function
char* getFortune();

int main()
{
    srand(time(NULL)); // Seed for random number generator
    
    printf("Welcome to the automated fortune teller!\n\n");
    
    char* fortune = getFortune(); // Get user's fortune
    
    printf("\n\nYour fortune is: %s\n", fortune); // Print user's fortune
    
    return 0;
}

// Recursive function to get a fortune
char* getFortune()
{
    // Array of possible fortunes
    char* fortunes[] = {"You will have a great day today.", 
                        "You are destined for greatness.",
                        "You will find love when you least expect it.",
                        "Your hard work will pay off soon.",
                        "You will embark on an unexpected journey.",
                        "Good things come to those who wait.",
                        "You will overcome your obstacles with ease.",
                        "You will gain  new perspective today.",
                        "Your creativity will be your greatest asset.",
                        "You will have a pleasant surprise in the near future."};
    
    int random_num = rand() % 10; // Generate random number between 0-9
    
    char* fortune = fortunes[random_num]; // Get the fortune at the random index
    
    int len = strlen(fortune); // Get length of fortune
    
    if(len <= 20) // If fortune is short enough, return it
    {
        return fortune;
    }
    else // If fortune is too long, try again recursively
    {
        return getFortune();
    }
}