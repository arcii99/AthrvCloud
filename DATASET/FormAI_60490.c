//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include<stdio.h>

void main(){
    int n, i, j, temp, sum = 0;
    int weights[] = {10, 20, 30, 40};
    int values[] = {60, 100, 120, 200};
    int knapsack_weight = 50;
    float ratio[4];
    int select[4] = {0, 0, 0, 0};

    n = sizeof(weights)/sizeof(weights[0]); // number of items

    // calculate ratio of value/weight for each item
    for(i = 0; i < n; i++){
        ratio[i] = (float)values[i]/(float)weights[i];
    }

    // sort the items based on their ratio in descending order using bubble sort
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(ratio[j] < ratio[j+1]){
                // swap the ratio
                temp = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j+1] = temp;

                // swap the weights
                temp = weights[j];
                weights[j] = weights[j+1];
                weights[j+1] = temp;

                // swap the values
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }

    // select items with highest ratio till the knapsack is full
    for(i = 0; i < n; i++){
        if(weights[i] <= knapsack_weight){
            select[i] = 1;
            knapsack_weight -= weights[i];
            sum += values[i];
        }
        else{
            select[i] = knapsack_weight/weights[i];
            knapsack_weight -= select[i]*weights[i];
            sum += select[i]*values[i];
        }
    }

    // display the selected items
    printf("Selected Items:\n");
    for(i = 0; i < n; i++){
        if(select[i] != 0){
            printf("Item %d: %d\n", i+1, select[i]);
        }
    }

    // display the total value of selected items
    printf("\nTotal Value of Selected Items: %d\n", sum);
}