//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char* activities[] = { "watching TV", "playing video games", "listening to music", 
                           "using the internet", "exercising", "eating junk food", "meditating" };
    char* targets[] = { "world leaders", "the government", "big corporations", 
                        "aliens", "the Illuminati", "extraterrestrial life forms", "time travelers" };
    char* outcomes[] = { "will fall into chaos and destruction", "will be overthrown by the people", 
                         "will be controlled by a secret society", "will be enslaved by extraterrestrial beings", 
                         "will be erased from existence through time manipulation", 
                         "will be forced to live in a dystopian world ruled by AI" };
    char* reasons[] = { "because of a secret technology that controls their minds", 
                        "because of a massive cover-up of historical events", 
                        "because of a deadly virus that was intentionally released", 
                        "because of an inter-dimensional portal that was opened", 
                        "because of a powerful entity that is manipulating reality" };
    
    srand(time(NULL)); // initialize random number generator
    
    printf("Welcome to the Random Conspiracy Theory Generator...\n\n");
    
    while (1) // loop until user exits
    {
        printf("What activity are you currently doing? ");
        int act = rand() % 7; // choose a random activity
        printf("%s\n", activities[act]);
        
        printf("Who do you believe is responsible for all the problems in the world? ");
        int targ = rand() % 7; // choose a random target
        printf("%s\n", targets[targ]);
        
        printf("What do you think will happen if they succeed? ");
        int outc = rand() % 6; // choose a random outcome
        printf("%s\n", outcomes[outc]);
        
        printf("Why do you think they are doing this? ");
        int reas = rand() % 5; // choose a random reason
        printf("%s\n\n", reasons[reas]);
        
        printf("Press 'q' to quit or any other key to generate another theory...\n");
        char c = getchar();
        if (c == 'q' || c == 'Q') break;
    }
    
    printf("\nThank you for using the Random Conspiracy Theory Generator! Goodbye.\n");
    
    return 0;
}