//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    char name[20];
    int luckyNum, birthYear, secretNum, sum;
    time_t t;
    
    //Initial prompt
    printf("Welcome to the Automated Fortune Teller! Please enter your name:");
    scanf("%s", name);
    
    //Generate random lucky number
    srand((unsigned) time(&t));
    luckyNum = rand() % 1000 + 1;
    
    //Ask for birth year and calculate lucky number
    printf("Hello %s! Please enter your birth year (YYYY format):", name);
    scanf("%d", &birthYear);
    sum = 0;
    while(birthYear > 0){
        sum += birthYear % 10;
        birthYear /= 10;
    }
    luckyNum += sum;
  
    //Generate random secret number
    secretNum = rand() % 10 + 1;
  
    //Give fortune based on lucky number and secret number
    printf("%s, your lucky number is %d!\n", name, luckyNum);
    printf("Shhh... your secret number is %d!\n", secretNum);
    printf("Your fortune for today is: ");
    if(luckyNum <= 200 && secretNum <= 5){
        printf("You will have a lucky day today! Things will fall into place perfectly.\n");
    } else if(luckyNum > 200 && secretNum <= 5){
        printf("Be careful of accidents today. It may be best to stay inside.\n");
    } else if(luckyNum <= 200 && secretNum > 5){
        printf("You may encounter some challenges today, but don't worry, you will overcome them.\n");
    } else{
        printf("Today is a good day to take risks! Be bold and try new things.\n");
    }
  
    return 0;
}