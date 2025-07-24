//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Sherlock Holmes
//Welcome to the C Movie Rating System!
//As a consulting detective, I, Sherlock Holmes, have devised an algorithm to rate movies based on their various attributes. 

#include<stdio.h>

int main()
{
    printf("Please enter the following attributes to rate the movie on a scale of 1-10.\n");
    printf("Plot: ");
    int plot;
    scanf("%d", &plot);
    printf("Acting: ");
    int acting;
    scanf("%d", &acting);
    printf("Cinematography: ");
    int cinematography;
    scanf("%d", &cinematography);
    printf("Soundtrack: ");
    int soundtrack;
    scanf("%d", &soundtrack);
    
    int sum = plot + acting + cinematography + soundtrack;
    float average = sum/4.00;

    printf("Based on my algorithm, the movie rating is: ");

    if(average<4)
    {
        printf("Terrible! Awful plot, terrible acting, poor cinematography and don't even get me started on the soundtrack. \n");
    }
    else if(average>=4 && average<7)
    {
        printf("Decent movie. Could have been better, but not catastrophic. \n");
    }
    else if(average>=7 && average<=9)
    {
        printf("Excellent work! The plot, acting, cinematography and soundtrack are all very well done. \n");
    }
    else
    {
        printf("Absolutely fantastic! An incredible movie with outstanding plot, superb acting, breathtaking cinematography and amazing soundtrack. \n");
    }
    return 0;
}