//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char* conspiracy[] = {"NASA faked the moon landing",
                          "The government controls the weather",
                          "Chemtrails are poisoning us",
                          "Bigfoot is real and the government is hiding it",
                          "The Illuminati is controlling the world",
                          "9/11 was an inside job",
                          "The world is actually flat",
                          "The Bermuda Triangle is a portal to another dimension",
                          "The government created AIDS to control population growth",
                          "Aliens are among us and the government knows",
                          "The Loch Ness Monster is real and has been covered up by the government",
                          "The Titanic never actually sank",
                          "The Earth is hollow and there is another civilization inside"};

    srand(time(NULL));
    
    printf("Random Conspiracy Theory Generator:\n");
    printf("------------------------------------\n");
    
    for (int i = 0; i < 5; i++) {
        int index = rand() % 13;
        printf("%d. %s\n", i+1, conspiracy[index]);
    }

    return 0;
}