//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include<stdio.h>
#include<stdlib.h>

int main(){
    int count = 0;
    int choice;
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please choose your candidate: \n");
    printf("1. John Doe\n");
    printf("2. Jane Smith\n");
    printf("3. Bob Johnson\n");
    printf("4. Emily Brown\n");
    printf("5. None of the above\n");

    do{
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        if(choice >= 1 && choice <= 5){
            count++;
            printf("Your vote has been successfully recorded!\n");
        }else{
            printf("Invalid choice!\n");
        }
    }while(count < 1);

    printf("\n\nThank you for your participation!\n");
    printf("The results will be announced soon.\n");

    return 0;
}