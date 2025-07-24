//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: romantic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char randChar() {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    return chars[rand() % strlen(chars)];
}

bool randBool() {
    return rand() % 2 == 0;
}

int main() {
    srand(time(NULL));

    char* subjects[] = {"The government", "The Illuminati", "Aliens", "The Free Masons", "Bigfoot", "The Loch Ness Monster", "The Reptilians"};
    char* verbs[] = {"is controlling", "is manipulating", "created", "funded", "planned", "revived", "invented", "brainwashed"};
    char* objects[] = {"the media", "the weather", "the economy", "our minds", "the future", "the moon landing", "technology", "the education system"};

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    while (true) {
        printf("Generating conspiracy theory...\n");

        char* subject;
        char* verb;
        char* object;

        do {
            subject = subjects[rand() % (sizeof(subjects) / sizeof(char*))];
            verb = verbs[rand() % (sizeof(verbs) / sizeof(char*))];
            object = objects[rand() % (sizeof(objects) / sizeof(char*))];
        } while (strcmp(subject, "The Reptilians") == 0 && strcmp(verb, "created") != 0);

        printf("\n%s %s %s!\n", subject, verb, object);

        if (randBool()) {
            printf("\nBut that's not even the craziest part!\n");
            printf("Did you know that %c%c%c%c%c%c%c%c%c%c%c%c %s %c%c%c%c%c%c%c%c%c?\n\n", randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), subject, randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), randChar(), randChar());
        }

        printf("Press enter to generate another conspiracy or type 'exit' to quit...\n");

        char input[100];
        fgets(input, 100, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        printf("\n");
    }

    printf("Thanks for using the Random Conspiracy Theory Generator!\n");

    return 0;
}