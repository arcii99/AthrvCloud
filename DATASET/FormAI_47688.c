//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    // Define the array of fortunes
    char* fortunes[] = {
        "A smile is your passport into the hearts of others.",
        "A wise man will make more opportunities than he finds.",
        "You already know the answer to the questions lingering inside your head.",
        "Every exit is an entry somewhere else.",
        "Excellence is not an act but a habit.",
        "Make everyday your masterpiece.",
        "In order to change the world, you have to get your hands dirty.",
        "The only way to do great work is to love what you do.",
        "Change can hurt, but it leads a path to something better.",
        "You miss 100 percent of the shots you don’t take.",
        "Patience is a key to joy.",
        "Your efforts will pay off soon.",
        "Your potential is limitless."
    };

    // Calculate number of fortunes in the array
    int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);

    // Seed the random number generator with current time
    srand(time(NULL));
    
    // Generate a random index number
    int fortune_index = rand() % num_fortunes;

    // Print the fortune
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Your fortune for today is:\n%s\n", fortunes[fortune_index]);
    
    return 0;
}