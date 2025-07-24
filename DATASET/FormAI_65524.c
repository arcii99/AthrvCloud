//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare the array of possible fortunes
    char *fortunes[] = {
        "You will have a wonderful day!",
        "Good news is on the horizon!",
        "Better things are coming your way!",
        "You will meet someone special soon!",
        "Your hard work will pay off!",
        "A great opportunity is coming your way!"
    };
    
    // Get the current time and seed the random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    // Generate a random index to select a fortune from the array
    int index = rand() % 6;
    
    // Print the selected fortune
    printf("Your fortune for today is: %s\n", fortunes[index]);
    
    return 0;
}