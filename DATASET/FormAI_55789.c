//FormAI DATASET v1.0 Category: Searching algorithm ; Style: safe
#include<stdio.h>

// Function prototype
int binarySearch(int[], int, int);

int main(){
    int num, i, key, position;
    int list[20];
    printf("Enter the size of the array: ");
    scanf("%d", &num);
    printf("Enter %d integers in ascending order : \n", num);
    for (i=0; i<num; i++){
        scanf("%d", &list[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &key);

    // Binary search function call
    position = binarySearch(list, num, key);

    if (position != -1){
        printf("%d found at position %d.\n", key, (position + 1));
    }
    else{
        printf("%d not found.\n", key);
    }
    return 0;
}

// Binary Search Function
int binarySearch(int a[], int n, int key){
    int start=0, end=n-1, mid;
    while(start<=end){
        mid=(start+end)/2;
        if(key==a[mid]){
            return mid;
        }
        else if(key<a[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}