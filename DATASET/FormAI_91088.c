//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to generate random conspiracy theories
char* generate_conspiracy() {
    char* conspiracy;

    //list of conspiracy theories
    char* theories[] = {
        "The moon landing was faked by the government.",
        "The Illuminati control the world.",
        "The CIA created HIV/AIDS.",
        "9/11 was an inside job.",
        "Area 51 is hiding evidence of extraterrestrial life.",
        "The government is controlling the weather.",
        "The JFK assassination was a conspiracy involving multiple shooters.",
        "The Titanic didn't sink, it was its sister ship.",
        "The oil industry is suppressing clean energy sources.",
        "The Amish control the world behind the scenes.",
        "The government is hiding evidence of ancient civilizations.",
        "The world is controlled by lizard people.",
        "Big Pharma is hiding cures to diseases to make more money.",
        "The Earth is flat and NASA is lying.",
        "The Simpsons predicts the future.",
        "Mandela effect proves alternate realities exist.",
        "The government has a time travel program."
    };

    //seed the random number generator
    srand(time(NULL));

    //generate a random conspiracy theory
    int index = rand() % 17;
    conspiracy = theories[index];

    return conspiracy;
}

int main() {
    char* conspiracy = generate_conspiracy();

    //display the conspiracy theory
    printf("Sherlock Holmes investigates:\n");
    printf("My dear Watson, I have discovered something quite interesting.\n");
    printf("It appears that %s\n", conspiracy);

    return 0;
}