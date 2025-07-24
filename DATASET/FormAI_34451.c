//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* conspiracies[] = {
    "The government is controlling our minds through chemtrails.",
    "Aliens have infiltrated our government and are manipulating our leaders.",
    "The moon landing was faked by the government.",
    "Big Pharma is hiding the cure for cancer to make more money.",
    "The illuminati is secretly controlling the world behind the scenes.",
    "9/11 was an inside job and the government is hiding the truth.",
    "The Earth is flat and NASA is lying to us about the true shape of our planet.",
    "The Vatican is hiding ancient texts that prove the existence of extraterrestrial life.",
    "The true power in the world is held by a small group of global elites known as the New World Order.",
    "The recent rise of AI and robotics is part of a plan to replace humans with machines."
};

int main() {
    srand(time(NULL)); // seed random number generator
    
    // generate random conspiracy theory
    int index = rand() % 10;
    char* conspiracy = conspiracies[index];
    
    // add paranoid tone to output
    printf("I can't believe it, but I just uncovered a shocking truth:\n");
    printf("%s\n", conspiracy);
    printf("Don't trust anyone, they are all out to get us!\n");
    
    return 0;
}