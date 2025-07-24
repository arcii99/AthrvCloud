//FormAI DATASET v1.0 Category: Data mining ; Style: active
#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[10] = {3,5,1,10,6,7,9,2,8,4};
    
    int min = arr[0];
    int max = arr[0];
    
    float sum = 0;
    float average;
    
    for(int i=0;i<10;i++){
        if(arr[i]<min){
            min = arr[i];
        }
        if(arr[i]>max){
            max = arr[i];
        }
        
        sum += arr[i];
    }
    
    average = sum/10;
    
    printf("The minimum number in the array: %d\n",min);
    printf("The maximum number in the array: %d\n",max);
    printf("The sum of the numbers in the array: %.2f\n",sum);
    printf("The average of the numbers in the array: %.2f\n",average);
    
    return 0;
}