//FormAI DATASET v1.0 Category: Error handling ; Style: lively
#include<stdio.h>

int main() {
    int creditScore;
    printf("What is your credit score? ");
    scanf("%d", &creditScore);

    if(creditScore > 800) {
        printf("Congratulations! You have excellent credit score\n");
    } else if (creditScore > 600 && creditScore <= 800) {
        printf("Your credit score is good, but there is room for improvement\n");
    } else if (creditScore > 400 && creditScore <= 600) {
        printf("Your credit score is fair, but it needs significant improvement\n");
    } else if (creditScore <= 400) {
        printf("Your credit score is poor, and you will need to take steps to increase it\n");
    } else {
        printf("Invalid credit score entered, please try again\n");
        return 1; // return error code
    }

    printf("Thank you for using our credit score checker, have a nice day!\n");
    return 0; // return success code
}