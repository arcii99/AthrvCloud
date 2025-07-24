//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int maxProfit = 0;
    int currProfit = 0;
    int buy = 0;
    int sell = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            currProfit = arr[j] - arr[i];
            if(currProfit > maxProfit) {
                maxProfit = currProfit;
                buy = arr[i];
                sell = arr[j];
            }
        }
    }

    printf("Maximum Profit: %d\n", maxProfit);
    printf("Buy: %d\n", buy);
    printf("Sell: %d\n", sell);

    return 0;
}