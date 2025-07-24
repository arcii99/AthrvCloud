//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t;
    srand((unsigned) time(&t));
    int randNum = rand() % 9;
    char* fortunes[10] = {
        "You will have a pleasant surprise today.",
        "Your hard work will pay off soon.",
        "You will meet someone very special soon.",
        "The future holds great things for you.",
        "You will make a new friend today.",
        "A new opportunity will arise soon.",
        "Your kindness will be rewarded.",
        "Success is in your future.",
        "You will overcome a difficult obstacle soon.",
        "Good luck is coming your way."
    };
    printf("Welcome to the Automated Fortuneteller program!\n");
    printf("Think of a question or situation you need insight on and press ENTER to receive your fortune.\n");
    getchar();
    printf("%s\n", fortunes[randNum]);
    return 0;
}