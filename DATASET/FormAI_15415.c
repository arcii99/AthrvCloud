//FormAI DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h> 

int main() {
    
    int* nums;
    int numCount;
    
    printf("Hello! Let's play a game. I'll prompt you for the number of integers you want to enter, then you'll enter them one by one.\n");
    printf("Ready? Here we go!\n\n");
    
    printf("How many integers would you like to enter?\n");
    scanf("%d", &numCount);
    
    nums = (int*) malloc(numCount * sizeof(int));
    
    if (nums == NULL) {
        printf("Uh oh, it looks like there isn't enough memory to handle that many integers. Let's just try again later.");
        return 0;
    }
    
    printf("Great! Now we're going to enter %d numbers, one by one:\n", numCount);
    
    for(int i = 0; i < numCount; i++){
        printf("Number %d: ", i+1);
        scanf("%d", &nums[i]);
    }
    
    printf("\nAwesome! Here are the numbers you entered: \n");
    for(int i = 0; i < numCount; i++) {
        printf("%d ", nums[i]);
    }
    
    printf("\n\nThanks for playing!");
    
    free(nums);
    
    return 0;
}