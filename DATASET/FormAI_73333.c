//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

char* random_bool() {
    char* str;
    if (rand() % 2 == 0) {
        str = "TRUE";
    } else {
        str = "FALSE";
    }
    return str;
}

char* random_location() {
    char* locations[10] = {"Area 51","Bermuda Triangle","Hollow Earth","Mount Shasta","Denver Airport","Antarctica","Pyramids of Giza","Stonehenge","Roswell, New Mexico","The Moon"};
    int num = rand() % 10;
    return locations[num];
}

char* random_reason() {
    char* reasons[10] = {"mind control","world domination","creating a new world order","finding ancient technology","contacting aliens","harvesting human organs","altering genetics","power and wealth","conspiracy against humanity","sacrificing children to ancient gods"};
    int num = rand() % 10;
    return reasons[num];
}

char* random_conspiracy() {
    char* places[5] = {"in the government","in the media","in the pharmaceutical industry","in the entertainment industry","in the religious institutions"};
    char* conspiracy = (char*) malloc(100 * sizeof(char));
    sprintf(conspiracy, "There is a conspiracy %s to achieve %s at %s. It is %s that high-ranking officials are involved in this plot.", places[rand() % 5], random_reason(), random_location(), random_bool());
    return conspiracy;
}

int main() {
    srand(time(NULL));

    printf("Here are some random conspiracy theories:\n\n");

    for (int i = 1; i <= 10; i++) {
        char* conspiracy = random_conspiracy();
        printf("%d. %s\n\n", i, conspiracy);
        free(conspiracy);
    }

    return 0;
}