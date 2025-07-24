//FormAI DATASET v1.0 Category: Game ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char* name;
    int age;
    char gender;
    char* love_interest;

    printf("Hello there, I'm a romantic program! Let's create a profile for you.\n");

    //getting name
    printf("What's your name?\n");
    scanf("%s", name);

    //getting age
    printf("How old are you?\n");
    scanf("%d", &age);

    //getting gender
    printf("What's your gender? (M/F)\n");
    scanf(" %c", &gender);

    //getting love interest name
    printf("Who is your love interest?\n");
    scanf("%s", love_interest);

    printf("Welcome, %s!\n\n", name);
    printf("I'm glad you're ready to open your heart to me. \n");
    printf("It seems you're %d years old and you're %c.\n", age, gender);
    printf("Your love interest is %s, lucky them!.\n\n", love_interest);

    printf("Let me generate a romantic message for you...\n\n");
    printf("When I saw you, I knew I had found the one I would love forever.\n");
    printf("With you, every moment is full of love and happiness.\n");
    printf("I can't imagine my life without you, my dear %s.\n", love_interest);
    printf("Every memory with you is a treasure, and I never want to let go.\n");
    printf("So here I am, with all my heart and soul, to say:\n");
    printf("I love you, now and forever, my dearest %s.\n", love_interest);

    return 0;
}