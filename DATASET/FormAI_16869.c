//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mathematical
#include <stdio.h>

int main() {
    int coins[] = {1, 5, 10, 25, 50};
    int n = sizeof(coins)/sizeof(coins[0]);
    int target = 74;
    int index = n-1, count = 0;
   
    while(target) {
        if(coins[index] <= target) {
            target -= coins[index];
            count++;
        } else {
            index--;
        }
    }
   
    printf("Minimum coins required to make %d cents: %d\n", target, count);
    return 0;
}