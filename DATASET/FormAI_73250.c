//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    int num = rand() % 100 + 1; // Generate a random number between 1 and 100
    
    printf("Welcome to the C Random Conspiracy Theory Generator!");
    printf("\n\nConspiracy theory #%d:\n", num);
    
    switch(num) {
        case 1:
            printf("The government is secretly controlled by lizard people who shape-shift into human form.\n");
            break;
        case 2:
            printf("The moon landing was faked and filmed in a Hollywood studio.\n");
            break;
        case 3:
            printf("Chemtrails are being used by the government to control the population and make them docile.\n");
            break;
        case 4:
            printf("Aliens have already made contact with Earth and the government is covering it up.\n");
            break;
        case 5:
            printf("The Illuminati controls all major governments and corporations in the world.\n");
            break;
        case 6:
            printf("The Big Bang never happened and the universe is actually a simulation.\n");
            break;
        case 7:
            printf("The Titanic didn't sink due to an iceberg, but was intentionally sunk as part of an insurance scam.\n");
            break;
        case 8:
            printf("The moon is actually a hollowed out space station controlled by an advanced alien race.\n");
            break;
        case 9:
            printf("The CIA is behind the rise of drug cartels in order to fund illegal operations.\n");
            break;
        case 10:
            printf("The government is using mind control techniques through subliminal messaging in media and advertising.\n");
            break;
        case 11:
            printf("The earth is flat and all evidence of a round earth is part of a massive conspiracy.\n");
            break;
        case 12:
            printf("The government is intentionally promoting unhealthy diets and lifestyles in order to keep the population sick and reliant on pharmaceuticals.\n");
            break;
        case 13:
            printf("All major disasters, such as 9/11 and the Boston Marathon bombing, are actually false flag operations orchestrated by the government.\n");
            break;
        case 14:
            printf("The existence of the Loch Ness monster and other mythical creatures is being covered up by the government.\n");
            break;
        case 15:
            printf("Time travel has already been invented and is being used by the government to manipulate historical events.\n");
            break;
        default:
            printf("Oops, something went wrong! Please try again.\n");
    }
    
    return 0;
}