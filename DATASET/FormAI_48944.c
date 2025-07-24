//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *conspiracy_theories[] = {
    "The government is hiding the cure for cancer",
    "The moon landing was faked",
    "Aliens are among us",
    "The Illuminati control everything",
    "9/11 was an inside job",
    "The Earth is flat",
    "Bigfoot is real and the government is covering it up",
    "Chemtrails are poisoning our air",
    "The Freemasons are controlling the world",
    "The Titanic sinking was not an accident",
    "The Bermuda Triangle is a portal to another dimension",
    "The Loch Ness Monster is a secret government experiment",
    "Area 51 is a secret alien base",
};

int main()
{
    srand(time(NULL)); // seed random number generator
    
    printf("Welcome to the Conspiracy Theory Generator!\n\n");
    
    while (1)
    {
        printf("Press ENTER to generate a new conspiracy theory or 'Q' to quit.\n");
        char input = getchar();
        
        if (input == 'q' || input == 'Q')
            break;
        
        int random_index = rand() % (sizeof(conspiracy_theories) / sizeof(char *));
        char *theory = conspiracy_theories[random_index];
        
        printf("\n%s\n\n", theory);
        
        // clear input buffer
        while (getchar() != '\n');
    }
    
    printf("Thank you for using the Conspiracy Theory Generator!\n");
    
    return 0;
}