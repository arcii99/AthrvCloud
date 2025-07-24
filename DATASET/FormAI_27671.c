//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* conspiracy_theory() {
    int i, len;
    char* theory;
    char* keywords[] = {"aliens", "government", "Illuminati", "secret society", "Big Pharma", "chemtrails", "deep state", "New World Order", "the Matrix", "time travel"};
    char* verbs[] = {"conspiring with", "manipulating", "controlling", "brainwashing"};
    char* objects[] = {"humans", "animals", "the weather", "our minds", "the economy", "the media"};
    char* endings[] = {"to take over the world.", "to keep us in the dark.", "to rule us all.", "to achieve world domination.", "to create a dystopian future."};
    
    // randomizing seed based on time in seconds
    srand(time(NULL));
    
    // selecting keywords randomly
    int num_keywords = sizeof(keywords)/sizeof(char*); // calculating size of keywords array
    char* keyword1 = keywords[rand() % num_keywords];
    char* keyword2 = keywords[rand() % num_keywords];
    
    // selecting random verb and object
    int num_verbs = sizeof(verbs)/sizeof(char*);
    int num_objects = sizeof(objects)/sizeof(char*);
    char* verb = verbs[rand() % num_verbs];
    char* object = objects[rand() % num_objects];
    
    // selecting random ending
    int num_endings = sizeof(endings)/sizeof(char*);
    char* ending = endings[rand() % num_endings];
    
    // generating theory string
    len = snprintf(NULL, 0, "The %s are %s %s, using %s %s %s", keyword1, verb, keyword2, object, keyword2, ending);
    theory = malloc(len + 1);
    snprintf(theory, len+1, "The %s are %s %s, using %s %s %s", keyword1, verb, keyword2, object, keyword2, ending);
    
    return theory;
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    
    // generating first theory
    char* theory1 = conspiracy_theory();
    printf("Theory 1: %s\n\n", theory1);
    
    // generating second theory
    char* theory2 = conspiracy_theory();
    printf("Theory 2: %s\n\n", theory2);
    
    // freeing memory used by theories
    free(theory1);
    free(theory2);
    
    return 0;
}