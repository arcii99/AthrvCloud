//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: post-apocalyptic
#include<stdio.h> 
#include<stdlib.h> 

int main(){ 
    int n, i, j, temp; 
    printf("Enter the number of items in the bag: "); 
    scanf("%d",&n); 
    int weight[n], value[n]; 
    for(i=0;i<n;i++){ 
        printf("\nEnter the weight and value of item %d: ",i+1); 
        scanf("%d%d",&weight[i],&value[i]); 
    } 
    float ratio[n], total_value=0, knapsack=50; 
    for(i=0;i<n;i++) 
        ratio[i]=(float)value[i]/weight[i]; 
    for(i=0;i<n;i++){ 
        for(j=i+1;j<n;j++){ 
            if(ratio[i]<ratio[j]){ 
                temp=ratio[j]; 
                ratio[j]=ratio[i]; 
                ratio[i]=temp; 
                temp=weight[j]; 
                weight[j]=weight[i]; 
                weight[i]=temp; 
                temp=value[j]; 
                value[j]=value[i]; 
                value[i]=temp; 
            } 
        } 
    } 
    for(i=0;i<n;i++){ 
        if(weight[i]<=knapsack){ 
            knapsack-=weight[i]; 
            total_value+=value[i]; 
        } 
        else{ 
            total_value+=value[i]*(knapsack/weight[i]); 
            break; 
        } 
    } 
    printf("\nThe maximum value that can be obtained is %.2f\n",total_value); 

    return 0; 
}