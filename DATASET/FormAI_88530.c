//FormAI DATASET v1.0 Category: Scientific ; Style: content
#include<stdio.h>

int main(){
    int number, sum=0, i=1;
    printf("Welcome to the Sum of N Numbers Program.\n");
    printf("Please enter a positive integer greater than 0: ");
    scanf("%d", &number);

    if(number<=0){
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    printf("The sum of first %d natural numbers is: ", number);
    while(i<=number){
        sum += i;
        i++;
    }
    printf("%d\n", sum);
    return 0;
}