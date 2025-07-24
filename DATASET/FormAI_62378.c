//FormAI DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>

int main() {
    printf("Welcome to the Sorting Program! \n");
    printf("I am so excited to help you sort your data! \n");
    
    /* User input */
    int n;
    printf("Enter the number of elements you would like to sort: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Great! Now please enter the %d elements you would like to sort: \n", n);
    
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    /* Sorting algorithm */
    printf("Alright! Let's get to sorting...\n");
    
    for (int i = 0; i < n; i++) {
        int temp = arr[i];
        int j = i;
        
        while (j > 0 && arr[j-1] > temp) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
    
    /* Displaying sorted array */
    printf("Hooray! Your data is now sorted:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}