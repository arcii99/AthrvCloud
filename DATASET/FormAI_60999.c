//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: minimalist
#include <stdio.h>

int main() {
    int n = 0, m = 0;
    printf("Enter the number of items and the capacity of the backpack:\n");
    scanf("%d %d", &n, &m);

    int w[n], v[n], i;
    printf("Enter the weight and value of each item:\n");
    for(i=0; i<n; i++) 
        scanf("%d %d", &w[i], &v[i]);

    float max_value = 0;
    for(i=0; i<n; i++) {
        if(m == 0) 
            break;
        
        int max_index = -1, j;
        for(j=0; j<n; j++) {
            if((w[j] > 0) && ((max_index == -1) || ((float)v[j]/w[j] > (float)v[max_index]/w[max_index]))) 
                max_index = j;
        }

        float amount = (float)m < w[max_index] ? (float)m : (float)w[max_index];
        max_value += amount * ((float)v[max_index]/w[max_index]);
        w[max_index] -= amount;
        m -= (int)amount;
    }

    printf("Maximum value that can be placed in the backpack: %0.2f\n", max_value);

    return 0;
}