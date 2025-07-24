//FormAI DATASET v1.0 Category: Math exercise ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));  // initializing the random seed
    
    int num1 = rand() % 11;  // generating a random number between 0 and 10
    int num2 = rand() % 11;
    int correct_answer = num1 + num2;  // calculating the correct answer
    
    printf("In the post-apocalyptic world, you scavenge for supplies... \n\n");
    printf("You come across a broken down supermarket and find %d cans of beans and %d bottles of water. \n", num1, num2);
    printf("How many total supplies do you have?\n");
    
    int user_answer;  // creating a variable to store user's answer
    scanf("%d", &user_answer);  // reading user's input
    
    if(user_answer == correct_answer){
        printf("\nCongratulations! You have enough supplies to survive for another day.\n");
    } else {
        printf("\nSorry, your answer is incorrect. Looks like you'll have to continue scavenging for supplies.\n");
    }
    
    return 0;
}