//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int num){
    if(num <= 1){
        return num;
    }
    return Fibonacci(num - 1) + Fibonacci(num - 2);
}

int main(){
    int num_terms;
    printf("Enter the number of terms you want to visualize in the Fibonacci sequence: ");
    scanf("%d", &num_terms);

    printf("Generating Fibonacci sequence visualization...");

    //calculate the maximum number in the sequence for scaling purposes
    int max_num = Fibonacci(num_terms);

    //iterate through each term in the sequence and print out the visualization
    for(int i = 0; i < num_terms; i++){
        //calculate the number in the sequence at this position
        int num = Fibonacci(i);
        //calculate the percentage of the maximum number this number represents
        double percentage = (double)num / max_num * 100;

        //print out a bar graph representation of the number
        printf("\n%d: ", num);
        for(int j = 0; j < percentage; j++){
            printf("#");
        }
    }

    printf("\n");
    
    return 0;
}