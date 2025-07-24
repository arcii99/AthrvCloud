//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char answer[50];
    printf("Welcome to the Automated Fortune Teller. Ask me a question and I will give you an answer:");
    fgets(answer, sizeof(answer), stdin);
    printf("Hmm, let me consult the universe...\n");

    int fortune = rand() % 6; //Generate a number between 0 and 5

    switch(fortune){
        case 0:
            printf("The stars are aligned in your favor! Expect good news within the next few days.\n");
            break;
        case 1:
            printf("Your hard work will pay off, but be patient. The universe has a plan for you.\n");
            break;
        case 2:
            printf("You may face some challenges in the near future, but with your positive attitude, you will overcome them!\n");
            break;
        case 3:
            printf("The universe sees a new opportunity on the horizon. Keep an open mind and be ready for change!\n");
            break;
        case 4:
            printf("Love is in the air! Keep your eyes open for a new romantic connection.\n");
            break;
        case 5:
            printf("Financial abundance is coming your way! Stay focused on your goals and success will follow.\n");
            break;
        default: //In case the random number generator fails
            printf("The universe is experiencing technical difficulties. Please try again later.\n");
    }

    printf("Thank you for consulting the Automated Fortune Teller. Have a great day!");
    return 0;
}