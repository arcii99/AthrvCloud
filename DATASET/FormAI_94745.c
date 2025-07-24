//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeds the random number generator

    // Define arrays for the conspiracy theories and their corresponding likelihoods
    char* theories[] = {
        "The moon landing was faked.",
        "Aliens have made contact with Earth.",
        "COVID-19 was created in a lab.",
        "The Illuminati controls the world.",
        "9/11 was an inside job.",
        "Chemtrails are a government conspiracy.",
        "The government is hiding evidence of extraterrestrial life.",
        "The world will end in 2021."
    };

    int likelihood[] = { 70, 50, 80, 90, 60, 40, 30, 20 }; // each likelihood must be between 0 and 100

    int total_likelihood = 0;
    for(int i = 0; i < sizeof(likelihood)/sizeof(likelihood[0]); i++) { // get the total likelihood 
        total_likelihood += likelihood[i];
    }

    int rand_num = rand() % total_likelihood; // generate random number from 0 to total likelihood
    int index = 0;

    for(int i = 0; i < sizeof(likelihood)/sizeof(likelihood[0]); i++) { // iterate through theories array
        int current_prob = likelihood[i];

        if(rand_num < current_prob) { // if the random number is less than the likelihood of the current theory
            index = i;
            break;
        }
        else {
            rand_num -= current_prob;
        }
    }

    printf("The conspiracy theory of the day: %s\n", theories[index]); // print the selected theory

    return 0;
}