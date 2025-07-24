//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *subjects[] = {"The government", "Corporations", "Aliens", "The Illuminati", "The lizard people", "The deep state", "The Freemasons", "The New World Order"};
char *verbs[] = {"are controlling", "are manipulating", "are conspiring with", "are colluding with", "are brainwashing", "are hiding information from", "are experimenting on", "are infiltrating"};
char *objects[] = {"the media", "the economy", "the justice system", "the weather", "our minds", "the healthcare system", "the education system", "the entertainment industry"};
char *adjectives[] = {"sinister", "evil", "nefarious", "cunning", "malicious", "deceitful", "secretive", "diabolical"};

int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    printf("The following are random conspiracy theories:\n\n");
    
    for (int i = 0; i < 10; i++) // Generate 10 conspiracy theories
    {
        printf("%d. ", i+1);
        printf("%s ", subjects[rand() % 8]); // Pick a random subject
        printf("%s ", verbs[rand() % 8]); // Pick a random verb
        printf("%s ", objects[rand() % 8]); // Pick a random object
        printf("with a %s agenda.\n", adjectives[rand() % 8]); // Pick a random adjective to finish the sentence
    }
    
    return 0;
}