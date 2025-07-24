//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void BucketSort(int arr[], int n) {
    int i, j;
    int count[n];
    memset(count, 0, sizeof(count));
    for(i = 0; i < n; i++)
        (count[arr[i]])++;
    for(i = 0, j = 0; i < n; i++) {
        while(count[i] > 0) {
            arr[j++] = i;
            count[i]--; 
        }
    }
}

void display(int arr[], int size) {
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    printf("\nWelcome to the Retro Bucket Sort program!\n\n");
    printf("First, let's create an array of integers...\n");
    printf("How many integers would you like to input? ");
    int n;
    scanf("%d", &n);
    printf("\nGreat! Please input %d integers...\n", n);
    int arr[n], i;
    for(i = 0; i < n; i++) {
        printf("Enter integer %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nArray before sorting:\n");
    display(arr, n);
    printf("\nSorting array using Bucket Sort...\n");
    BucketSort(arr, n);
    printf("Array after sorting:\n");
    display(arr, n);
    printf("\nThank you for using our Retro Bucket Sort program! We hope you enjoyed it.\n");
    return 0;
}