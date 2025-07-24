//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

int checksum(int arr[], int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    return sum % 256;
}

int main(){
    printf("Welcome! Let's calculate the checksum of your data.\n");
    printf("Please enter the number of integers in your data: ");
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));

    printf("Enter your data:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int check = checksum(arr, n);
    printf("The checksum for your data is: %d\n", check);

    free(arr);
    printf("Thank you for using our checksum calculator. Have a great day!\n");

    return 0;
}