//FormAI DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>

// Declare the variables
int love = 0, hate = 0, deaths = 0, marriages = 0;

// Functions to modify the variables
void declare_love() {
    love++;
    printf("Romeo: My love for you grows stronger...\n");
}

void declare_hate() {
    hate++;
    printf("Tybalt: You Montagues are all the same!\n");
}

void cause_death() {
    deaths++;
    printf("Mercutio: A plague on both your houses!\n");
}

void declare_marriage() {
    marriages++;
    printf("Friar Lawrence: These violent delights have violent ends.\n");
}

int main() {
    // Romeo declares his love, but Tybalt declares his hate
    declare_love();
    declare_hate();
    
    // A fight breaks out, and Mercutio is killed
    cause_death();
    
    // Romeo seeks revenge and kills Tybalt
    cause_death();
    
    // Romeo and Juliet fall in love and get married
    declare_love();
    declare_marriage();
    
    // The tragedy unfolds as both Romeo and Juliet end up dead
    cause_death();
    cause_death();
    
    // Print the final status of the variables
    printf("Love: %d\n", love);
    printf("Hate: %d\n", hate);
    printf("Deaths: %d\n", deaths);
    printf("Marriages: %d\n", marriages);
    
    return 0;
}