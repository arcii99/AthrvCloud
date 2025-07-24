//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char suspect1[] = "John";
    char suspect2[] = "Mary";
    char suspect3[] = "Bob";

    char clue1[] = "Footprints near the door.";
    char clue2[] = "Broken window in the back.";
    char clue3[] = "Toolbox left behind.";

    int suspicious = 0;

    printf("Detective Holmes arrives at the scene of the crime.\n");
    printf("He notices the following clues:\n");

    printf(">   %s\n", clue1);
    printf(">   %s\n", clue2);
    printf(">   %s\n", clue3);

    printf("Holmes starts his investigation by questioning the suspects.\n");

    if(strcmp(suspect1, "John") == 0)
    {
       suspicious++;
       printf("John seems nervous and defensive during the questioning.\n");
    }

    if(strcmp(suspect2, "Mary") == 0)
    {
       suspicious++;
       printf("Mary claims to have been out of town, but cannot provide proof.\n");
    }

    if(strcmp(suspect3, "Bob") == 0)
    {
       suspicious++;
       printf("Bob has a criminal record, matching the profile of the intruder.\n");
    }

    printf("Based on the clues and the suspects' behavior, Detective Holmes believes that the identity of the intruder is:\n");

    if(suspicious > 1)
    {
       printf("It's not clear who the intruder is, further investigation is needed.\n");
    }
    else if(strcmp(suspect1, "John") == 0 && strcmp(suspect2, "Mary") != 0 && strcmp(suspect3, "Bob") != 0)
    {
       printf("John is the most likely suspect.\n");
    }
    else if(strcmp(suspect1, "John") != 0 && strcmp(suspect2, "Mary") == 0 && strcmp(suspect3, "Bob") != 0)
    {
       printf("Mary is the most likely suspect.\n");
    }
    else if(strcmp(suspect1, "John") != 0 && strcmp(suspect2, "Mary") != 0 && strcmp(suspect3, "Bob") == 0)
    {
       printf("Bob is the most likely suspect.\n");
    }
    else
    {
       printf("It's not clear who the intruder is, further investigation is needed.\n");
    }

    return 0;
}