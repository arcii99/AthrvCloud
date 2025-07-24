//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* subject[] = {"The Illuminati", "The Government", "The Freemasons", "The Reptilians", "The New World Order"};
    char* action[] = {"control", "manipulate", "influence", "dominate", "enslave"};
    char* object[] = {"the media", "the economy", "the education system", "the weather", "pop culture"};

    srand(time(NULL));

    printf("Welcome to the Conspiracy Theory Generator!\n");
    printf("Here's a new theory for you:\n");

    int rand_subj = rand() % 5;
    int rand_act = rand() % 5;
    int rand_obj = rand() % 5;

    printf("%s is secretly trying to %s %s.\n", subject[rand_subj], action[rand_act], object[rand_obj]);

    printf("\nHowever, that's just one theory. Let's generate some more:\n\n");

    for (int i = 0; i < 5; i++) {
        rand_subj = rand() % 5;
        rand_act = rand() % 5;
        rand_obj = rand() % 5;

        printf("%s is secretly trying to %s %s.\n", subject[rand_subj], action[rand_act], object[rand_obj]);
    }

    printf("\nAs you can see, the truth is out there! Keep your eyes open and stay vigilant...\n");

    return 0;
}