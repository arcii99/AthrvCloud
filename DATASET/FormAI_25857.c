//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t; 
    srand((unsigned) time(&t)); //initialize random number generator with time
    
    char* fortune_array[10] = {"You will find love in unexpected places.",
                                "Your hard work will pay off in the end.",
                                "A new opportunity is coming your way.",
                                "Your creativity will blossom in the near future.",
                                "Be patient and good things will happen.",
                                "Your kindness will be rewarded.",
                                "Believe in yourself and you will succeed.",
                                "The stars are aligned in your favor.",
                                "Good news is on the way.",
                                "Take a leap of faith and you will not regret it."};
    int random_index = rand()%10; //generate random number from 0 to 9
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("***************************************************************************\n");
    printf("Connect the dots to unlock your fortune!\n\n");
    
    for(int i = 0; i<5; i++) //print random pattern of dots
    {
        for(int j = 0; j<20; j++)
        {
            if(rand()%2 == 0)
                printf(".");
            else
                printf("*");
        }
        printf("\n");
    }
    
    printf("\nYour fortune: %s\n", fortune_array[random_index]); //print fortune
    
    return 0;
}