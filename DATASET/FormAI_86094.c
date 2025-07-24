//FormAI DATASET v1.0 Category: Online Examination System ; Style: calm
#include<stdio.h> 

int main() 
{ 
    int question_num = 10; // number of questions
    int correct_ans = 0; // initialize number of correct answers
   
    printf("Welcome to the C Online Examination System!\n"); 
    sleep(1); // delay for 1 second
    
    printf("Please answer %d questions.\n", question_num); 
    sleep(1); // delay for 1 second
    
    for(int i=1; i<=question_num; i++) 
    { 
        printf("Question %d: 5 + 7 = \n", i); 
        int ans; 
        scanf("%d", &ans); 
        
        if(ans == 12) // if the answer is correct
        { 
            printf("Correct! \n"); 
            correct_ans++; // increment number of correct answers
        } 
        else // if the answer is incorrect
        { 
            printf("Incorrect! \n"); 
        } 
    } 
   
    printf("You have completed the exam.\n"); 
    sleep(1); // delay for 1 second
    
    printf("Number of correct answers: %d\n", correct_ans); 
    
    if(correct_ans >= 7) // if the number of correct answers is more than or equal to 7
    { 
        printf("Congratulations, you have passed the exam!\n"); 
    } 
    else // if the number of correct answers is less than 7 
    { 
        printf("Sorry, you have failed the exam!\n"); 
    } 
    
    return 0; 
}