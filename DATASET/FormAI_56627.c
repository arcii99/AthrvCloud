//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: shape shifting
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    int sum=0;
    int max=0;
    for(int i=0;i<n;i++) {
        if(sum+arr[i]<0) {
            sum=0;
        } else {
            sum+=arr[i];
        }
        if(sum>max) {
            max=sum;
        }
    }
    printf("The maximum sum of a subarray is %d\n", max);
    return 0;
}