//FormAI DATASET v1.0 Category: Math exercise ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("Welcome to the Grateful Mathematics Exercise Program!\n\n");
    printf("This program is designed to help you improve your math skills while also cultivating gratitude.\n\n");
    printf("For each math problem, you will be prompted with a random addition question. You will then be asked to express gratitude for something related to the answer.\n\n");
    
    srand(time(0)); //Set random seed
    
    int num1, num2, ans;
    char response[50];
    int count = 0;
    while(count < 10){ //Loop through 10 math questions
        num1 = rand() % 11; //Generate random numbers between 0 and 10
        num2 = rand() % 11;
        ans = num1 + num2;
        
        printf("What is %d + %d?\n", num1, num2);
        scanf("%d", &response);
        
        if(response == ans){
            printf("Congratulations, that is correct! Now it's time to express gratitude.\n");
            printf("What are you grateful for that is related to the number %d?\n", ans);
            getchar(); //Clear input buffer
            fgets(response, sizeof(response), stdin); //Get user response
            printf("That's wonderful, keep up the gratitude!\n\n");
            count++;
        }
        else{
            printf("Sorry, that is incorrect. Please try again.\n\n");
        }
    }
    
    printf("Congratulations, you have completed the Grateful Mathematics Exercise Program!\n");
    
    return 0;
}