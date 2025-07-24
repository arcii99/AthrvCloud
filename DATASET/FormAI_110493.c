//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *conspiracies[] = {
        "The moon landing was faked by the government",
        "Aliens have already made contact with us, but the government is hiding it",
        "The government is using chemtrails to control our minds",
        "The Illuminati controls the world's governments and economies",
        "The Earth is hollow and inhabited by advanced civilizations",
        "The government is covering up the existence of time travel technology",
        "The Loch Ness monster is real and the government is hiding its existence",
        "The government is hiding the cure for cancer in order to maintain control over the population"};
    
    srand(time(NULL)); // initialize random number generator with current time
    int rand_num = rand() % 8; // generate random number between 0 and 7
    
    printf("Random Conspiracy Theory Generator\n");
    printf("---------------------------------\n");
    printf("Did you know that...\n");
    printf("%s\n", conspiracies[rand_num]); // print randomly chosen conspiracy theory
    
    return 0;
}