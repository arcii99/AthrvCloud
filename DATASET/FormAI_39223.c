//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10  // Define maximum size of the circuit

int main(void){
    int elements[MAX_SIZE];  // Array to store the circuit elements
    int num;  // Variable to store the number of elements in the circuit
    
    // Prompt the user to enter the number of elements in the circuit
    printf("Enter the number of elements in the circuit(Maximum number of elements is %d): ", MAX_SIZE);
    scanf("%d", &num);
    
    // Check if the number of elements is within the maximum limit
    if(num <= MAX_SIZE){
        printf("Enter the values of the circuit elements:\n");
        
        // Loop to read the input values of the circuit elements
        for(int i = 0; i < num; i++){
            scanf("%d", &elements[i]);
        }
        
        printf("The circuit elements you have entered are:\n");
        
        // Loop to display the input values of the circuit elements
        for(int i = 0; i < num; i++){
            printf("%d ", elements[i]);
        }
    }
    else{
        printf("The number of elements cannot be more than %d.", MAX_SIZE);
    }
    
    return 0;
}