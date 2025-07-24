//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    srand(time(0)); // seed the random number generator with the current time
    
    // define the array of possible fortunes
    char *fortunes[10] = {
        "Good things come to those who wait.",
        "You will find success in unexpected places.",
        "A new opportunity will come your way soon.",
        "Believe in yourself and your abilities.",
        "A hardworking attitude will lead to success.",
        "Good luck will follow you in your endeavors.",
        "Your positive attitude will bring you good things.",
        "Listen to advice from those you trust.",
        "A little effort goes a long way.",
        "Trust your instincts and take a chance."
    };
    
    int random_num = rand() % 10; // generate a random number between 0 and 9
    char *chosen_fortune = fortunes[random_num]; // get the randomly selected fortune
    
    printf("Your fortune today is:\n%s\n", chosen_fortune); // print the fortune to the user
    
    return 0; 
}