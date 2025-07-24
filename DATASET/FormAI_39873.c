//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL));  // randomly seed the generator

    char* keywords[10] = {"Chemtrails", "Illuminati", "Freemasons", "Flat Earth", "Area 51", "Global Warming", "Big Pharma", "9/11", "Moon Landing", "New World Order"};
    char* actions[10] = {"are controlling", "are manipulating", "are secretly meeting to plan", "have created", "have hidden", "are covering up", "are testing", "are financing", "are brainwashing", "have infiltrated"};
    char* targets[10] = {"the government", "the media", "the population", "the food supply", "the weather", "the educational system", "the healthcare industry", "the internet", "the military", "the financial system"};

    int keyword_index = rand() % 10;   // randomly select a keyword
    int action_index = rand() % 10;    // randomly select an action
    int target_index = rand() % 10;    // randomly select a target

    printf("Did you know that the %s %s %s?\n", keywords[keyword_index], actions[action_index], targets[target_index]);
    
    return 0;
}