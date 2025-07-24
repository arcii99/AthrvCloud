//FormAI DATASET v1.0 Category: Searching algorithm ; Style: excited
#include<stdio.h>
#include<stdlib.h>

/*This is a unique searching algorithm program written in C that I am so excited to share with you!*/

int search(int arr[], int n, int x){
    int i; 
    for(i=0; i<n; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    printf("Welcome to the unique searching algorithm program brought to you in C!!!\n");

    int arr[100], x, n, ans;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched for: ");
    scanf("%d", &x);

    ans = search(arr, n, x);

    if(ans == -1){
        printf("%d not found in the array.\n", x);
    }else{
        printf("%d found at index %d of the array.\n", x, ans);
    }

    printf("Thank you for using this unique searching algorithm program!\n");

    return 0;
}