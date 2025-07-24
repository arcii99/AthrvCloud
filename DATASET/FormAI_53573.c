//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int fate;
    char name[20];
    printf("Greetings, traveler! I am the Great Fortune Teller. What is your name?\n");
    scanf("%s", name);
    printf("\nWelcome, %s. Have a seat and let me see what fate has in store for you.\n\n", name);

    srand(time(NULL)); //initialize random seed
    fate = rand() % 10 + 1; //generate a random number between 1 and 10

    switch(fate)
    {
        case 1:
            printf("Beware, %s. The future looks bleak for you. Your enemies are closing in and danger lurks at every turn. Beware the shadows.\n", name);
            break;
        case 2:
            printf("Good news, %s! Your future is looking bright. Wealth and success are on the horizon. Keep moving forward!\n", name);
            break;
        case 3:
            printf("I see a journey in your future, %s. Pack light and be wary of strangers along the way. Your path is treacherous.\n", name);
            break;
        case 4:
            printf("Your fortunes are about to take a turn for the worse, %s. Misfortune and sorrow are in the air. Be prepared for hard times.\n", name);
            break;
        case 5:
            printf("The future is uncertain for you, %s. Fate will be decided by your actions. Choose wisely.\n", name);
            break;
        case 6:
            printf("I sense great power within you, %s. The world trembles at your mere presence. Use your powers for good.\n", name);
            break;
        case 7:
            printf("Your destiny lies in the stars, %s. Keep a close eye on the heavens and follow the constellations to your fate.\n", name);
            break;
        case 8:
            printf("A great tragedy will soon befall you, %s. Brace yourself for the worst and lean on your friends and family for support.\n", name);
            break;
        case 9:
            printf("The future is full of uncertainty for you, %s. Embrace the unknown and relish in the adventure that lies ahead.\n", name);
            break;
        case 10:
            printf("I see an important decision in your future, %s. Take your time and consult with those closest to you. Your fate hangs in the balance.\n", name);
            break;
    }

    printf("\nThank you for visiting, %s. Remember, fate is not set in stone. Your actions can change the course of your destiny. Until next time!\n", name);

    return 0;
}