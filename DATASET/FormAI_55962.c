//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, n;

    // Prompt the user for the number of fortunes
    printf("How many fortunes would you like me to tell?\n");
    scanf("%d", &n);

    srand(time(NULL));

    // Define fortunes list
    const char* fortunes[10] = {
        "Today it's up to you to create the peacefulness you long for.",
        "A friend asks only for your time not your money.",
        "To overcome fear, we must realize that fear is not real.",
        "Believe in yourself and others will follow.",
        "The secret of getting ahead is getting started.",
        "You learn from your mistakes... You will learn a lot today.",
        "The smallest act of kindness is worth more than the grandest intention.",
        "The best way to predict the future is to create it.",
        "If you think you can, you can.",
        "Your future is whatever you make of it."
    };

    // Display fortunes
    for (i=0;i<n;i++){
        int randomIndex = rand()%10;
        printf("Fortune Number %d: %s\n", i+1, fortunes[randomIndex]);
    }

    printf("Thanks for using the Automated Fortune Teller!\n");

    return 0;
}