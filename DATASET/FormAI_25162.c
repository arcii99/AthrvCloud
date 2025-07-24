//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
#include<stdio.h>

int main(){
    printf("Hi there! Let's make a colorful graph today!\n\n");

    // First, let's get the input from user
    int num_values;
    printf("How many values do you want to input? ");
    scanf("%d", &num_values);

    // Now, let's create an array to store the values
    int values[num_values];
    printf("Enter the values (separated by spaces): ");
    for(int i = 0; i < num_values; i++){
        scanf("%d", &values[i]);
    }

    // Let's find the maximum value in the array
    int max = values[0];
    for(int j = 1; j < num_values; j++){
        if(values[j] > max){
            max = values[j];
        }
    }

    // Now, let's create the graph
    printf("\n\nHere's your graph:\n\n");
    for(int k = max; k >= 1; k--){
        for(int l = 0; l < num_values; l++){
            if(values[l] >= k){
                printf("#\t");
            }
            else{
                printf("\t");
            }
        }
        printf("\n");
    }
    for(int m = 0; m < num_values; m++){
        printf("%d\t", values[m]);
    }

    printf("\n\nHope you like your colorful graph! Have a great day!");
    return 0;
}