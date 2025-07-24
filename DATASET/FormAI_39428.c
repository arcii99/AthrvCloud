//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* theories[] = {"There is a secret society controlling the world's governments.",
                        "Aliens are among us and have been manipulating human history.",
                        "Artificial intelligence has already surpassed human intelligence and is controlling us.",
                        "All major events are planned and executed by a group of elites known as the Illuminati.",
                        "NASA is covering up the existence of a parallel universe accessible by black holes.",
                        "The Earth is actually flat and governments are hiding this fact from the public.",
                        "The moon landing was faked and filmed in a Hollywood studio.",
                        "The COVID-19 pandemic was created by pharmaceutical companies to profit from a vaccine."};
    
    srand(time(0)); // seed RNG with current time
    
    printf("Random conspiracy theory generator:\n\n");
    
    for (int i=0; i<5; i++) {
        int random_index = rand() % 8; // generate random index between 0 and 7
        printf("%d) %s\n", i+1, theories[random_index]); // print theory with number
    }
    
    return 0;
}