//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Automated Fortune Teller\n");
    printf("Please enter your name: ");
    char name[50];
    scanf("%s", name);

    printf("\n%s, your fate has been written in the stars.\n", name);

    srand(time(NULL));

    int fortune = rand() % 5;

    if (fortune == 0){
        printf("As fair Verona was cursed with strife,\n");
        printf("So too will your future be fraught with trouble and pain.\n");
     }
    else if (fortune == 1){
        printf("In fair Verona, love was doomed to fail,\n");
        printf("Your future too, will lead to heartbreak and wail.\n");
    }
    else if (fortune == 2){
        printf("In the city of Verona, the Capulets and Montagues fought,\n");
        printf("You too will have battles to be fought and battles to be won.\n");
    }
    else if (fortune == 3){
        printf("The stars have not yet decided your fate,\n");
        printf("So take control of your future and make it great.\n");
    }
    else{
        printf("In the end, all roads lead to death,\n");
        printf("But do not fret, for it is the journey that gives life its breath.\n");
    }

    printf("\nThank you for using the Automated Fortune Teller.\n");

    return 0;
}