//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *fortunes[] = {
        "You will find success in unexpected places.",
        "A thrilling adventure awaits you in the near future.",
        "Great things are coming your way!",
        "Your hard work will pay off.",
        "Be patient and good news is on the way."
    };
    
    // Retrieve the time information
    time_t t;    
    time(&t);    

    // Use time information to seed the random number generator
    srand((unsigned int)t); 

    // Generate a random number between 0 and 4
    int index = rand() % 5;

    printf("Welcome to the automated fortune teller!\n");
    printf("Your fortune for today is:\n\n%s\n", fortunes[index]);

    return 0;
}