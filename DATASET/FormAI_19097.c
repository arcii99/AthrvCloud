//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>

int main() {
    int num_of_tests;
    scanf("%d", &num_of_tests);
    
    for (int i = 0; i < num_of_tests; i++) {
        int n;
        scanf("%d", &n);
        int array[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &array[j]);
        }
        int money;
        scanf("%d", &money);
        
        // Implementing the Greedy Algorithm to find the maximum number of items that can be bought
        int total_items_bought = 0;
        for (int k = 0; k < n; k++) {
            if (array[k] <= money) {
                total_items_bought++;
                money -= array[k];
            } else {
                break;
            }
        }
        printf("On test case %d, You can buy %d items with total cost %d units of money\n", i+1, total_items_bought, money);
    }
    return 0;
}