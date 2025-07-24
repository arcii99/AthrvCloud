//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *phrases[] = {"The moon landing was faked.",
                   "The government is hiding proof of extraterrestrial life.",
                   "The Illuminati control world events.",
                   "9/11 was an inside job.",
                   "Vaccines suppress human intelligence.",
                   "Chemtrails are mind control agents.",
                   "Flat Earth is a government cover-up.",
                   "Global warming is a hoax.",
                   "The government is using mind control through social media."};

char *actors[] = {"the government",
                  "the Illuminati",
                  "the Freemasons",
                  "the CIA",
                  "the FBI",
                  "the NSA",
                  "NASA",
                  "Big Pharma",
                  "the New World Order"};

char *evidence[] = {"classified documents",
                    "whistleblower testimonies",
                    "declassified files",
                    "an anonymous source",
                    "leaked information",
                    "a hidden camera recording"};

int main(void) {
    srand(time(NULL));
    
    printf("Random Conspiracy Theory Generator:\n\n");
    
    for (int i = 0; i < 10; i++) {
        int phrase_index = rand() % 9;
        int actor_index = rand() % 9;
        int evidence_index = rand() % 6;
        
        char conspiracy[100];
        
        strncpy(conspiracy, phrases[phrase_index], 100);
        strcat(conspiracy, " by ");
        strcat(conspiracy, actors[actor_index]);
        strcat(conspiracy, " using ");
        strcat(conspiracy, evidence[evidence_index]);
        
        printf("%d. %s\n\n", i+1, conspiracy);
    }
    
    return 0;
}