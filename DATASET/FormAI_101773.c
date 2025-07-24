//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int r = rand()%10;
    char* conspiracy;

    switch(r) {
        case 1:
            conspiracy = "The moon landing was faked by the US government!";
            break;
        case 2:
            conspiracy = "Chemtrails are being used to control the population!";
            break;
        case 3:
            conspiracy = "The Illuminati is controlling the world behind the scenes!";
            break;
        case 4:
            conspiracy = "9/11 was an inside job by the US government!";
            break;
        case 5:
            conspiracy = "The Earth is flat and the government is hiding it from us!";
            break;
        case 6:
            conspiracy = "The government is hiding the cure for cancer!";
            break;
        case 7:
            conspiracy = "The CIA assassinated JFK!";
            break;
        case 8:
            conspiracy = "The Denver Airport is a secret base for the New World Order!";
            break;
        case 9:
            conspiracy = "The reptilian elite are secretly controlling the world!";
            break;
        default:
            conspiracy = "COVID-19 was created by the Chinese government as a bioweapon!";
            break;
    }

    printf("Random Conspiracy Theory Generator: %s\n", conspiracy);

    return 0;
}