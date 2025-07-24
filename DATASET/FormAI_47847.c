//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Initializing random number generator
    srand(time(NULL));
    
    printf("Welcome to the Automated Fortune Teller!\n\n");
    
    // Declaring and initializing variables
    char name[20];
    int age;
    int lucky_num;
    int sum = 0;
    
    // Getting user input
    printf("What is your name?\n");
    scanf("%s", name);
    
    printf("What is your age?\n");
    scanf("%d", &age);
    
    printf("What is your lucky number?\n");
    scanf("%d", &lucky_num);
    
    // Generating random numbers and calculating sum
    int rand_nums[6];
    for(int i=0;i<6;i++){
        rand_nums[i] = rand() % 50 + 1;
        sum += rand_nums[i];
    }
    
    // Printing the fortune
    printf("\n\nDear %s, here is your fortune for today:\n", name);
    printf("Your lucky numbers are:");
    for(int i=0;i<6;i++){
        printf(" %d", rand_nums[i]);
    }
    
    if(lucky_num == sum){
        printf("\nYour lucky number and the sum of the random numbers match! Today is your lucky day!");
    }
    else{
        printf("\nThe sum of the random numbers is %d, which is not your lucky number. Better luck next time!", sum);
    }
    
    return 0;
}