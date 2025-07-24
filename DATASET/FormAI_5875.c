//FormAI DATASET v1.0 Category: System event logger ; Style: surrealist
#include <stdio.h>

#define DEBUG 1 													// Setting Debug Mode ON (1) or OFF(0)

void log_event(const char* event, const char* description)
{
    if(DEBUG)														// If Debug Mode is ON
    {
        printf("Event: %s\n", event);
        printf("Description: %s\n", description);
    }
}

int main()
{
    char event[100];												// Declare a character array to store the event
    char description[1000];											// Declare a character array to store the description
	
    // Let's create some surreal events and descriptions
    strcpy(event, "Cats can fly!");									
    strcpy(description, "I saw a group of cats soaring through the skies, leaving behind a trail of glitter and rainbows.");
    log_event(event, description);									// Call the log_event function with the surreal event and description.

    strcpy(event, "Frogs are taking over the world!");
    strcpy(description, "I woke up to find frogs ruling the world, wearing suits and driving fancy cars.");
    log_event(event, description);

    strcpy(event, "Trees have become sentient!");
    strcpy(description, "I heard the trees whispering to each other, discussing the fate of our world.");
    log_event(event, description);

    strcpy(event, "Aliens have landed!");
    strcpy(description, "I met friendly aliens who taught me the secrets of the universe and gave me free pizza.");
    log_event(event, description);

    return 0;
}