//FormAI DATASET v1.0 Category: Computer Biology ; Style: energetic
#include<stdio.h>

int main(){
    int dna_array[10]; // Declaring array of 10 integers to store DNA

    for(int i=0;i<10;i++){
        printf("Enter the %dth DNA: ",i+1);
        scanf("%d",&dna_array[i]); //Taking input as integers and storing it in the array
    }

    printf("\nDNA stored in array:\n");

    for(int i=0;i<10;i++){
        printf(" %d ",dna_array[i]); //Printing the DNA stored in array
    }

    int count=0; // A counter for storing the number of times a specific DNA occurs

    for(int i=0;i<10;i++){
        if(dna_array[i]==5){
            count++;
        }
    }

    if(count==0){
        printf("\n5th DNA does not exist in the array!\n");
    }
    else{
        printf("\n5th DNA occurs %d times in the array!\n",count);
    }

    return 0;
}