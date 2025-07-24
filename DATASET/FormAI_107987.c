//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice = rand() % 5;
    switch (choice) {
        case 0:
            printf("Did you know that the government is hiding the cure for cancer?");
            break;
        case 1:
            printf("NASA has been faking space missions for years. It’s all a big cover-up!");
            break;
        case 2:
            printf("The Illuminati has been controlling world events for centuries. Wake up, sheeple!");
            break;
        case 3:
            printf("Have you heard about the secret society based in Antarctica? They’re the ones pulling the strings!");
            break;
        case 4:
            printf("Aliens have been visiting Earth secretly for years. The government knows about it but they don’t want us to know.");
            break;
        default:
            printf("Something is not right here. Someone is manipulating your thoughts...");
    }
    return 0;
}