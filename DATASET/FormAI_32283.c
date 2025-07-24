//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include<stdio.h>

int main(){
    int n, i, j;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weight[n], value[n], ratio[n];
    float max_weight;
    printf("Enter the maximum weight that can be carried: ");
    scanf("%f", &max_weight);
    printf("Enter the weight and value of each item:\n");
    for(i=0; i<n; i++){
        scanf("%d %d", &weight[i], &value[i]);
        ratio[i] = value[i] / weight[i];
    }
    int temp, temp2, temp3;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(ratio[i] < ratio[j]){
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                temp2 = weight[i];
                weight[i] = weight[j];
                weight[j] = temp2;
                temp3 = value[i];
                value[i] = value[j];
                value[j] = temp3;
            }
        }
    }
    float current_weight = 0, total_value = 0;
    for(i=0; i<n; i++){
        if(current_weight + weight[i] <= max_weight){
            current_weight += weight[i];
            total_value += value[i];
        }
        else{
            float remaining_weight = max_weight - current_weight;
            total_value += remaining_weight * ratio[i];
            break;
        }
    }
    printf("The maximum value that can be carried is: %f", total_value);
    return 0;
}