//FormAI DATASET v1.0 Category: Sorting ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

int main() {
    int array[10] = {5, 3, 9, 6, 2, 1, 8, 4, 7, 0};
    int i, j, temp;
    
    printf("Before sorting: ");
    for(i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }
    
    for(i = 0; i < 10; i++) {
        for(j = i+1; j < 10; j++) {
            if(array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    
    printf("\nAfter sorting: ");
    for(i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    printf("\nThe world had been destroyed by a catastrophic event. Humanity was on its knees and the few survivors left had to fend for themselves in a savage and brutal world. Resources were scarce and survival was the only thing on their minds. Sorting was essential to make sure everyone got their fair share of the limited resources.\n");
    return 0;
}