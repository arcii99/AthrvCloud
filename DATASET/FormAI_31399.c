//FormAI DATASET v1.0 Category: Sorting ; Style: intelligent
#include<stdio.h>

void bubble_sort(int array[], int n){
    int temp,i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

int main(){
    int array[]={3,5,2,6,1,8,0,9,4,7};
    int n=sizeof(array)/sizeof(array[0]);
    
    printf("Array before sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    
    bubble_sort(array,n);
    
    printf("\nArray after sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    
    return 0;
}