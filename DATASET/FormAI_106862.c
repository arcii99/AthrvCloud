//FormAI DATASET v1.0 Category: Digital Diary ; Style: funny
#include<stdio.h>

int main()
{
    int date, month, year;
    char entry[1000];

    printf("Welcome to Digital Diary\n");
    printf("Please enter today's date (DD MM YY format): ");
    scanf("%d %d %d", &date, &month, &year);

    printf("\nGreat! Now, go ahead and write about your day:\n(You have 1000 characters limit, so make it count!) ");
    scanf(" %[^\n]s", entry);

    printf("\n\n***************  Entry Recorded: %d/%d/%d ***************\n\n", date, month, year);
    printf("Today, I woke up late, which unfortunately made me miss my first class. But hey, it was worth it, because I had a great time playing video games with my best friend all night! We ate pizza and stayed up super late. It was an awesome way to de-stress and forget about the usual university drama. But then I realised, I had to submit my assignments by tomorrow! So, I pulled an all-nighter to complete them. I hope I did them right, otherwise I'm definitely screwed. Anyways, I'll just communicate with my inner self and change my thoughts to positive. My mom always taught me to 'Think happy, be happy!' and I believe in it too. So, that was my day!\n");

    return 0;
}