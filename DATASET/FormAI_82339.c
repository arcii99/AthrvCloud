//FormAI DATASET v1.0 Category: Searching algorithm ; Style: surprised
#include<stdio.h>

int main(){

    int n, i, key, flag=0;

    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d",&key);

    printf("Searching for the element...\n");

    for(i=0;i<n;i++){
        if(arr[i]==key){
            printf("Found the element at position %d\n", i+1);
            printf("Oh my god! I can't believe it!\n");
            flag = 1;
            break;
        }
    }

    if(flag==0){
        printf("Element not found in the array :(\n");
        printf("Oh no, what shall we do?!\n");
    }

    return 0;
}