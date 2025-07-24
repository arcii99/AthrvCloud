//FormAI DATASET v1.0 Category: Sorting ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the world of Sorting!\n");
    printf("Please enter the number of elements to be sorted: ");
    int n;
    scanf("%d",&n);

    if(n<=0){
        printf("Invalid Input. Exiting... Bye!\n");
        exit(0);
    }

    int arr[n];
    printf("Please enter %d elements to be sorted:\n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Great! Let me sort the elements for you... \n");
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }

    printf("Tadaa! The sorted array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nThank you for using my Sorting Program. Have a nice day!\n");
    return 0;
}