//FormAI DATASET v1.0 Category: Sorting ; Style: cheerful
#include<stdio.h>

// Sorting function
void sort(int arr[], int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                // Swapping
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(){
    int arr[5]={4,38,12,6,77};
    int n=5,i;

    sort(arr,n);
    
    printf("Sorted array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    
    return 0;
}