//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Romeo and Juliet
#include<stdlib.h>
#include<stdio.h>

int main(){

    printf("My dear Juliet, I have a proposition for thee.\n");
    printf("I have written a C program that will schedule our appointments with precision and ease.\n");
    printf("With this program, we can avoid any misunderstandings in regards to our time together.\n");
    printf("What say you, my love, shall we give it a try?\n\n");

    printf("Please enter your desired appointment date in the MM/DD/YY format:\n");

    char date[9];
    scanf("%[^\n]s", date);

    printf("Please enter the desired appointment time in the HH:MM format:\n");

    char time[6];
    scanf("%[^\n]s", time);

    printf("\nAh, I see that you have chosen the %s on the clock of destiny.\n", time);
    printf("And on the date %s shall it be, when we partake in our scheduled gratifications.\n", date);
    printf("Is there anything else you would like to add, my dear?\n");

    char response[50];
    scanf("%[^\n]s", response);

    printf("Ah, I see. Well, let us seal our plans with a kiss.\n");
    printf("Until the appointed time, my love. Farewell.\n");

    return 0;
}