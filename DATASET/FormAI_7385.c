//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include<stdio.h>

int main(){
    int i,j,n,temp,shock=1;
    
    //Getting number of elements in array
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    
    int arr[n];
    
    //Getting array elements
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    //Sorting elements using Insertion Sort
    for(i=1;i<n;i++){
        temp = arr[i];
        j = i - 1;
        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
        
        //Displaying each sorting step with a shock emoji
        printf("\n\nStep %d: ",shock++);
        for(j=0;j<n;j++){
            printf("%d ",arr[j]);
        }
        printf("😱😱");
    }
    
    //Displaying the sorted array
    printf("\n\nFinal Sorted Array: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("😅😅");
    return 0;
}