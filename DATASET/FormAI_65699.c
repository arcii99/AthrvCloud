//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Welcome to the Greedy Algorithms Show! Today, we will witness a hilarious example of a greedy algorithm in action!\n");
    printf("So let's imagine that you are a greedy bank robber and you have successfully managed to rob a bank. The problem is, the money you stole is not in a single currency. \n");
    printf("You have a total of $4521.25 and it consists of the following denominations:\n");

    printf("$20 bill: 12\n");
    printf("$10 bill: 11\n");
    printf("$5 bill: 15\n");
    printf("$1 bill: 6\n");
    printf("25 cents coin: 3\n");
    printf("10 cents coin: 4\n");
    printf("5 cents coin: 1\n");
    printf("1 cent coin: 6\n");

    float amount = 4521.25;
    int count20 = 12, count10 = 11, count5 = 15, count1 = 6, count025 = 3, count010 = 4, count005 = 1, count001 = 6;

    printf("Now, you need to divide this money into as few bills and coins as possible. Let's use our Greedy Algorithm For This Task!\n");
    printf("Our strategy is to use the highest denomination first, then the second highest, and so on.\n");

    int dollar;
    dollar = amount;
    amount -= dollar;

    printf("\nUsing the greedy algorithm, we start with the highest denomination, which is the $20 bill. ");
    int used = dollar / 20;
    if (used >= count20){
        dollar -= count20*20;
        printf("We can use all %d $20 bills\n", count20);
        count20 = 0;
    } else if (used > 0){
        dollar -= used*20;
        count20 -= used;
        printf("We can use %d $20 bills\n", used);
    }
    printf("\nNow we move on to the $10 bill. ");
    used = dollar / 10;
    if (used >= count10){
        dollar -= count10*10;
        printf("We can use all %d $10 bills\n", count10);
        count10 = 0;
    } else if (used > 0){
        dollar -= used*10;
        count10 -= used;
        printf("We can use %d $10 bills\n", used);
    }
    printf("\nNext, we check the $5 bills. ");
    used = dollar / 5;
    if (used >= count5){
        dollar -= count5*5;
        printf("We can use all %d $5 bills\n", count5);
        count5 = 0;
    } else if (used > 0){
        dollar -= used*5;
        count5 -= used;
        printf("We can use %d $5 bills\n", used);
    }
    printf("\nMoving on to the $1 bills. ");
    used = dollar;
    if (used >= count1){
        dollar -= count1;
        printf("We can use all %d $1 bills\n", count1);
        count1 = 0;
    } else if (used > 0){
        dollar -= used;
        count1 -= used;
        printf("We can use %d $1 bills\n", used);
    }

    printf("\nAnd finally, we handle the coins. ");
    used = amount / 0.25;
    if (used >= count025){
        amount -= count025*0.25;
        printf("We can use all %d 25-cents coin\n", count025);
        count025 = 0;
    } else if (used > 0){
        amount -= used*0.25;
        count025 -= used;
        printf("We can use %d 25-cents coin\n", used);
    }
    used = amount / 0.1;
    if (used >= count010){
        amount -= count010*0.1;
        printf("We can use all %d 10-cents coin\n", count010);
        count010 = 0;
    } else if (used > 0){
        amount -= used*0.1;
        count010 -= used;
        printf("We can use %d 10-cents coin\n", used);
    }
    used = amount / 0.05;
    if (used >= count005){
        amount -= count005*0.05;
        printf("We can use all %d 5-cents coin\n", count005);
        count005 = 0;
    } else if (used > 0){
        amount -= used*0.05;
        count005 -= used;
        printf("We can use %d 5-cents coin\n", used);
    }
    used = amount / 0.01;
    if (used >= count001){
        amount -= count001*0.01;
        printf("We can use all %d 1-cents coin\n", count001);
        count001 = 0;
    } else if (used > 0){
        amount -= used*0.01;
        count001 -= used;
        printf("We can use %d 1-cents coin\n", used);
    }

    printf("\nCongratulations! You have managed to divide your stolen money into as few bills and coins as possible using the greedy algorithm!\n");
    printf("I hope you enjoyed our show, and remember, always be greedy when it comes to money!\n");

    return 0;
}