//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int random_num = rand() % 10;
    char* theories[] = {"The moon landing was faked by the government to appear superior in the space race.",
                        "Area 51 is an underground facility used by the government to conduct experiments on extraterrestrial life forms.",
                        "The Illuminati secretly control world events and governments.",
                        "The earth is flat and NASA is involved in a global conspiracy to convince people otherwise.",
                        "The CIA assassinated JFK because he knew too much about their secret operations.",
                        "The real Paul McCartney died in a car accident in the 60s and was replaced by a look-alike imposter.",
                        "Chemtrails are actually chemicals being sprayed into the atmosphere by the government for mind control purposes.",
                        "The Vatican is hiding evidence of aliens and their involvement in human history.",
                        "911 was an inside job orchestrated by the US government for political gain.",
                        "Famous celebrities such as Elvis and Tupac are still alive and living in secret."};
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("Here is your randomly generated conspiracy theory:\n\n");
    printf("%s\n", theories[random_num]);
    printf("\nDo you believe it? (y/n): ");
    char response;
    scanf("%c", &response);
    if (response == 'y') {
        printf("\nWell you're officially a conspiracist!\n");
    } else if (response == 'n') {
        printf("\nSuit yourself, but have an open mind!\n");
    } else {
        printf("\nInvalid response, please try again.\n");
    }
    return 0;
}