//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntro() {  // prints program intro
    printf("Welcome to the Magical System Administration program!\n");
    printf("This program will help you solve all your system troubles in the most magical way!\n\n");
}

void castSpell() {  // casts a random spell
    srand(time(NULL));  // seed random number generator with current time
    int spellNum = rand() % 5;  // choose a random number from 0-4
    switch(spellNum) {  // print spell based on random number
        case 0:
            printf("Hocus pocus, the program doth focus!\n");
            break;
        case 1:
            printf("Abracadabra, no more buffer overflow!\n");
            break;
        case 2:
            printf("Wingardium Leviosa, your program's fixed, sir!\n");
            break;
        case 3:
            printf("Flibbertigibbet, your data's now fit!\n");
            break;
        case 4:
            printf("Bippity boppity boo, your system's good as new!\n");
            break;
    }
}

int main() {
    printIntro();  // starts program with intro
    castSpell();  // casts a spell to fix system issue
    return 0;  // ends program
}