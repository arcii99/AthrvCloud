//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char conspiracy[7][50] = {"The moon landing was fake", 
                              "The government is spying on us through our phones", 
                              "The earth is flat and the government is hiding it", 
                              "Area 51 is hiding evidence of extraterrestrial life", 
                              "The Illuminati controls the world", 
                              "9/11 was an inside job", 
                              "Vaccines cause autism"};

    srand(time(NULL));
    int rand_num = rand() % 7;

    printf("Did you know that %s?\n", conspiracy[rand_num]);
    printf("It's been proven by reliable sources.\n");

    return 0;
}