//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char* subjects[] = {"The Knights Templar", "King Arthur", "The Black Plague", "The Holy Grail", "The Crusades", "The Freemasons", "The Illuminati", "The Spanish Inquisition", "The Vikings"};
    char* verbs[] = {"created", "possessed", "caused", "secretly controlled", "invented", "manipulated", "plotted", "discovered", "enslaved"};
    char* objects[] = {"magic", "aliens", "religion", "treasures", "weapons", "technology", "knowledge", "time travel", "unicorns"};

    printf("Welcome to the Medieval Conspiracy Theory Generator!\n");
    printf("Are you ready to learn the truth about the past? Type 'y' for yes or 'n' for no.\n");
    char response = getchar();

    if (response == 'y'){
        printf("\nSo you want to know the truth? Let's start...\n\n");
        for (int i = 0; i < 10; i++){
            int subj_index = rand() % 9;
            int verb_index = rand() % 9;
            int obj_index = rand() % 9;
            printf("%d. %s %s %s.\n", i+1, subjects[subj_index], verbs[verb_index], objects[obj_index]);
        }
        printf("\nThat's it! Now you know the secrets of the past. Don't forget to spread the word!\n");
    }
    else if (response == 'n'){
        printf("\nSuit yourself. But remember, ignorance is bliss...\n");
    }
    else{
        printf("\nI'm sorry, I didn't understand your response. Please try again.\n");
    }

    return 0;
}