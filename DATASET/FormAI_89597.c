//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    srand((unsigned int)time(NULL)); //seed random number generator with current time

    int fortuneNum = rand() % 10; //generate a random number between 0 and 9

    if(fortuneNum == 0) printf("Your future looks bright!\n");
    else if(fortuneNum == 1) printf("A new opportunity will present itself soon.\n");
    else if(fortuneNum == 2) printf("Good things are coming your way.\n");
    else if(fortuneNum == 3) printf("Take time to reflect on your past decisions.\n");
    else if(fortuneNum == 4) printf("Your hard work will pay off in the end.\n");
    else if(fortuneNum == 5) printf("A big change is on the horizon.\n");
    else if(fortuneNum == 6) printf("Your kindness will be appreciated by someone you least expect.\n");
    else if(fortuneNum == 7) printf("Your financial situation will improve.\n");
    else if(fortuneNum == 8) printf("Your creativity will lead you to success.\n");
    else if(fortuneNum == 9) printf("You will find love when you least expect it.\n");

    return 0;
}