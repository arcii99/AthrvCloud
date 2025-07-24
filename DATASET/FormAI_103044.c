//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: scientific
// A unique example of Greedy Algorithms in C
#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size) {
    int i, j, minIndex, temp;
    for (i = 0; i < size - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void maximizeProfit(int prices[], int budget, int numPrices) {
    selectionSort(prices, numPrices);
    int itemsBought = 0, totalCost = 0;
    for (int i = 0; i < numPrices && totalCost + prices[i] <= budget; i++) {
        itemsBought++;
        totalCost += prices[i];
    }
    printf("Items bought: %d\n", itemsBought);
    printf("Total cost: %d\n", totalCost);
}

int main() {
    int prices[] = {12, 14, 6, 8, 9};
    int numPrices = sizeof(prices)/sizeof(prices[0]); // calculates number of elements in the array
    int budget = 30;
    printf("Prices before sorting: ");
    printArray(prices, numPrices);
    printf("Budget: %d\n", budget);
    maximizeProfit(prices, budget, numPrices);
    return 0;
}