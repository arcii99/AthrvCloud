//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* keywords[] = {"Illuminati", "New World Order", "Secret Society", "Deep State", "False Flag", "Chemtrails", "Area 51", "Big Pharma", "9/11", "Flat Earth", "Reptilian", "Alien Abduction"};

int main() {
    srand(time(NULL));
    char conspiracy[1000] = "";
    
    // generate a random number of keywords between 3 and 8
    int num_keywords = (rand() % 6) + 3;
    
    // randomly select keywords and combine them into a conspiracy theory
    for (int i = 0; i < num_keywords; i++) {
        int index = rand() % 12;
        strcat(conspiracy, keywords[index]);
        strcat(conspiracy, " ");
    }
    
    printf("%s\n", conspiracy);
    
    return 0;
}