//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delay(int milliseconds) {
    for (int i=0; i<milliseconds*1000; i++) { }
}

void intro() {
    printf("You find yourself standing in a dark forest. You don't know how\n");
    delay(1000);
    printf("you got here or what you should do. Suddenly, a voice echoes through\n");
    delay(1000);
    printf("the trees...\n\n");
    delay(1000);
    printf("Voice: Welcome, traveler. You have stumbled upon the Forest of Truth.\n");
    delay(1000);
    printf("Voice: This is where people come to face their deepest fears and learn\n");
    delay(1000);
    printf("Voice: about themselves. Are you ready to begin your journey?\n\n");
    delay(1000);
    printf("You have no choice but to move forward.\n\n");
}

char* get_input() {
    char *line = malloc(100);
    fgets(line, 100, stdin);
    line[strlen(line)-1] = '\0';
    return line;
}

void chapter1() {
    printf("You walk down the path and see something glinting in the distance.\n");
    printf("As you move closer, you see that it's a sword stuck in a rock!\n");
    printf("Do you try to pull it out? (yes/no)\n");

    char *response = get_input();
    
    if (strcmp(response, "yes") == 0) {
        printf("You try to pull the sword out of the rock with all your might,\n");
        delay(1000);
        printf("but it won't budge.\n");
        printf("Suddenly, you hear a voice behind you...\n");
        delay(1000);
        printf("Voice: That sword is not meant for you. Leave it be.\n\n");
        
    } else if (strcmp(response, "no") == 0) {
        printf("You walk past the sword, ignoring it as you continue on your journey.\n\n");
    } else {
        printf("I'm sorry, I didn't understand that.\n\n");
        chapter1();
    }
}

int main() {
    intro();
    chapter1();
    return 0;
}