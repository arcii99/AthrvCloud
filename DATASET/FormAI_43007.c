//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

// Shapes for the shape shifting style
char rectShape[4][15] = {" /------\\ ","|        |"," \\------/ "};
char triaShape[3][15] = {"    /\\    ","   /  \\   ","  /____\\  "};
char circShape[5][15] = {"   /\\    ","  /  \\   "," |    |  ","  \\  /   ","   \\/    "};

// Function prototypes
void printShape(int, int);
void printMortgage(float, int, float);

int main(){
    float loanAmount, interestRate, monthlyPayment;
    int loanDuration, numPayments; 

    // Get user inputs
    printf("Enter the loan amount: ");
    scanf("%f", &loanAmount);
    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter the loan duration (in years): ");
    scanf("%d", &loanDuration);

    // Calculate number of payments
    numPayments = loanDuration * 12;

    // Calculate monthly payment
    monthlyPayment = (loanAmount * (interestRate / 1200)) / (1 - pow(1 + (interestRate / 1200), -numPayments));

    // Print mortgage details
    printShape(1, 20);
    printf("\n");
    printMortgage(loanAmount, loanDuration, interestRate);
    printf("\n");
    printShape(1, 20);
    printf("\n\n");
    printf("Your monthly payment will be: $%.2f\n", monthlyPayment);

    return 0;
}

// Function to print shapes
void printShape(int shape, int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            switch(shape){
                case 1: // Rectangle
                    if(i==0 || i==size-1 || j==0 || j==size-1){
                        printf("*");
                    }
                    else{
                        printf(" ");
                    }
                    break;

                case 2: // Triangle
                    if(i+j >= size-1 && i<size){
                        printf("*");
                    }
                    else{
                        printf(" ");
                    }
                    break;

                case 3: // Circle
                    if((i-2)*(i-2) + (j-2)*(j-2) <= 8){
                        printf("*");
                    }
                    else{
                        printf(" ");
                    }
                    break;
            }
        }
        printf("\n");
    }
}

// Function to print mortgage details
void printMortgage(float loanAmount, int loanDuration, float interestRate){
    printf("Mortgage Details:\n");
    printf("Loan amount: $%.2f\n", loanAmount);
    printf("Loan duration: %d years\n", loanDuration);
    printf("Interest rate: %.2f%%\n", interestRate);
}