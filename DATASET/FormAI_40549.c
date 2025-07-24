//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up random number generator
    time_t t;
    srand((unsigned) time(&t));

    // Define fortune array
    char* fortunes[] = {
        "You will have a wonderful day!",
        "You will receive a surprise soon!",
        "Good things will come to you in unexpected ways!",
        "Your hard work will pay off!",
        "A new opportunity will arise!",
        "Your loved ones will bring you joy!",
        "Great things will come your way!",
        "Your determination will lead you to success!",
        "You will meet someone who will change your life!",
        "Today is your lucky day!",
        "Your creativity will lead you to new heights!",
        "Your kindness will be rewarded!",
        "You will make a new friend soon!",
        "Your intuition will guide you to the right decision!",
        "You will overcome any challenges that come your way!",
        "You are destined for greatness!"
    };

    // Get user's name
    char name[50];
    printf("Hello! What is your name? ");
    scanf("%s", name);
    printf("\n");

    // Generate fortune
    int index = rand() % 16;
    printf("%s, your fortune for today is:\n\n", name);
    printf("%s\n", fortunes[index]);

    return 0;
}