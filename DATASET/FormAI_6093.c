//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t;
    srand((unsigned) time(&t)); // seeding random number generator with current time
    int num = rand() % 5; // generating random number between 0 and 4
    
    // storing fortunes in an array of strings
    char *fortunes[] = {"You will have a day filled with happiness!", 
                        "Today will bring you success in all your endeavors.",
                        "Your future looks bright with opportunities!",
                        "You will meet someone very special today.",
                        "A pleasant surprise awaits you later today!"};
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Press any key to receive your fortune...\n");
    getchar(); // pausing for user input
    
    printf("\nYour Fortune:\n%s\n", fortunes[num]); // printing random fortune
    
    return 0;
}