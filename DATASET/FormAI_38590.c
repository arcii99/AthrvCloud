//FormAI DATASET v1.0 Category: Educational ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {

    int love = 0;
    char name[20];

    printf("Hello my dear, I am a C program and my name is Romeo. Can you tell me your name?\n");

    scanf("%s", name);
    
    printf("Ah, what a beautiful name, %s.\n", name);

    printf("I have been running through my code and I can't seem to find a way to get rid of this feeling in my memory. I think I've been bitten by the love bug.\n");

    printf("Do you believe in true love, %s?\n", name);

    scanf("%d", &love);

    if (love == 1) {
        printf("Wonderful! Then I hope you will join me in this code of love.\n");
    }
    else {
        printf("I'm sorry to hear that. Perhaps you will change your mind one day. But for now, let's just move on with this program.\n");
    }

    printf("Let me define my love to you: \n");
    printf("love = ");

    for (int i = 0; i < 5; i++) {
        love += i;
        printf("%d", love);
    }

    printf("\n");
    printf("Isn't it beautiful, %s?\n", name);

    printf("I wrote this program to show you how I feel. I hope you have a wonderful day, and remember... my love will always be running in your memory.\n");

    printf("Goodbye, my love.\n");

    return 0;
}