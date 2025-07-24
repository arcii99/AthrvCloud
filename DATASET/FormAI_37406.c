//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>

// function to sort the array in descending order

void sort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[j] > arr[i]) {
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

// function to calculate the maximum number of toys that can be bought

int maxToys(int prices[], int n, int k) {
    int count = 0;
    sort(prices, n);
    for(int i=0; i<n; i++) {
        if(prices[i] <= k) {
            k -= prices[i];
            count++;
        }
        else {
            break;
        }
    }
    return count;
}

int main() {
    int n, k;
    printf("Enter the number of toys and the amount you have: ");
    scanf("%d %d", &n, &k);
    int prices[n];
    printf("Enter the prices of the toys:\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &prices[i]);
    }
    int max = maxToys(prices, n, k);
    printf("Maximum number of toys that can be bought: %d\n", max);
    return 0;
}