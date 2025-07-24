//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: creative
#include<stdio.h>

int main()
{
    int num1=0,num2=1,next,i;
    int total=10; //change the value of total to print more or fewer terms
    printf("The Fibonacci sequence for %d terms is : \n", total);
    for(i=0;i<total;i++){
        if(i<=1) //to print the first two terms as it is
            next=i;
        else{
            next=num1+num2;
            num1=num2; // interchange num1 and num2 
            num2=next;
        }
        for(int j=0;j<next;j++){
            printf("*"); //print number of '*' equal to the current Fibonacci number
        }
        printf("\n"); //move to the next line
    }
    return 0;
}