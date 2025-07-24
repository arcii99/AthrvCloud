//FormAI DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include<stdio.h>

int main(){
    int arr[10] = {1, 5, 7, 12, 16, 19, 25, 31, 37, 42};
    int search, start, mid, end;
    start = 0;
    end = 9;

    printf("Enter the element to be searched: ");
    scanf("%d", &search);

    while(start <= end){
        mid = (start + end) / 2;

        if(arr[mid] == search){
            printf("Element found at index %d\n", mid);
            return 0;
        }
        else if(arr[mid] < search){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    printf("Element not found");
    return 0;
}