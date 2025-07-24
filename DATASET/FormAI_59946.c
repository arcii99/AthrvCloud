//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //initialize random number generator with current time
    
    char* conspiracy1[10] = {"The government is controlled by aliens", 
                            "The moon landing was faked",
                            "Major events are predicted by the Simpsons",
                            "All world leaders are actually reptilian creatures",
                            "The Illuminati controls the world's financial systems",
                            "The cure for cancer has been discovered but is being suppressed",
                            "Social media is using mind control to manipulate users",
                            "Global warming is a hoax created by government officials to control the population",
                            "The Earth is actually flat",
                            "The CIA is behind all major global conflicts"};
                            
    char* conspiracy2[10] = {"and they are planning to take over the world", 
                            "and it was actually filmed in a studio",
                            "and the show's creators are time travelers",
                            "and they are working to turn humanity into slaves",
                            "and they use subliminal messaging to control individuals",
                            "and the government is keeping it hidden to maintain profits in the pharmaceutical industry",
                            "to sway political beliefs in favor of certain candidates or parties",
                            "and the real cause of climate change is being hidden",
                            "and NASA has been lying to us about space travel",
                            "and they are working to protect their own interests and withhold information from the public"};
                            
    char* conspiracy3[10] = {"by manipulating the media", 
                            "to distract the public from other important issues",
                            "to warn us of future events",
                            "to maintain their power and control",
                            "to keep society in a state of fear and confusion",
                            "to maintain control over the population",
                            "through advanced technology not yet known to the public",
                            "to maintain their grip on political power",
                            "and they have been covering it up for centuries",
                            "to advance their own agendas and maintain global dominance"};
    
    int rand1 = rand() % 10;
    int rand2 = rand() % 10;
    int rand3 = rand() % 10;
    
    printf("Did you know that %s %s %s?\n", conspiracy1[rand1], conspiracy2[rand2], conspiracy3[rand3]);
    
    return 0;
}