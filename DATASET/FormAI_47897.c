//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include<stdio.h>

void printNum(int num){   // recursive function to print numbers
    printf("%d ",num);
    if(num==1){           // base case
        return;
    }
    if(num%2==0){
        printNum(num/2);   // recursive call with even number
    } else{
        printNum(3*num+1); // recursive call with odd number
    }
}

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    while(n<=0){
        printf("Invalid input! Please enter a positive integer: ");
        scanf("%d",&n);
    }
    printf("Recursive sequence of %d: ",n);
    printNum(n);         // call to recursive function
    return 0;
}