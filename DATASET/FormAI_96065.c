//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* subjects[] = {"The government", "The Illuminati", "The lizard people", "The Freemasons", "The aliens"};
char* actions[] = {"is controlling", "has infiltrated", "is manipulating", "has created", "is hiding"};
char* objects[] = {"the media", "the education system", "the weather", "the stock market", "the internet"};

char* generate_conspiracy(){
    //seed random number generator
    srand(time(NULL));
    //generate random indices for each subject, action, and object
    int sub_index = rand() % 5;
    int act_index = rand() % 5;
    int obj_index = rand() % 5;
    //create a char array to hold the conspiracy theory sentence
    char* conspiracy = (char*) malloc(100 * sizeof(char));
    sprintf(conspiracy, "%s %s %s", subjects[sub_index], actions[act_index], objects[obj_index]);
    //return the conspiracy theory sentence
    return conspiracy;
}

int main(){
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    //generate 10 conspiracy theories and print to console
    for(int i=0; i<10; i++){
        char* theory = generate_conspiracy();
        printf("%d. %s.\n", i+1, theory);
        free(theory); //free the dynamically allocated memory for the conspiracy theory sentence
    }
    return 0;
}