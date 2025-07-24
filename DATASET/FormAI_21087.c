//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_num, i;
    char* conspiracy_theory[] = {
        "The moon landing was faked by the government",
        "Area 51 is hiding evidence of extraterrestrial life",
        "The Illuminati secretly rules the world",
        "COVID-19 was created in a lab as a bioweapon",
        "9/11 was an inside job orchestrated by the US government",
        "The Earth is flat and the government is hiding the truth",
        "The Bermuda Triangle is a portal to another dimension",
        "Chemtrails are being used to control the population",
        "The apocalypse is near and the government is preparing for it",
        "Bill Gates is using vaccines to implant microchips in people"
    };
    
    srand(time(NULL));
    printf("Random Conspiracy Theory Generator:\n");
    for (i = 1; i <= 5; i++) {
        random_num = rand() % 10;
        printf("%d. %s\n", i, conspiracy_theory[random_num]);
    }

    return 0;
}