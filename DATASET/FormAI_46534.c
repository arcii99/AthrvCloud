//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cyberpunk
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
    int num, i, *arr; 

    printf("Enter the number of terms you want in Fibonacci series: "); 
    scanf("%d", &num); 

    arr = (int*)malloc(num * sizeof(int)); 
  
    *(arr + 0) = 0; 
    *(arr + 1) = 1; 

    for (i = 2; i < num; i++) 
        *(arr + i) = *(arr + (i - 1)) + *(arr + (i - 2)); 

    printf("The Fibonacci Series is: ");

    for (i = 0; i < num; i++) {
        if(i%3==0){
            printf("\n-----------------");
        }
        if((i+1)%3==0){
            printf("\n|%8d|", *(arr + i)); 
        }
        else if((i+2)%3==0){
            printf("|%8d|", *(arr + i)); 
        }
        else{
            printf("|%8d", *(arr + i)); 
        }
    }
    printf("\n-----------------");

    return 0; 
}