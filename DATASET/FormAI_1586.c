//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include <stdio.h>

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Our array
    int n = sizeof(arr)/sizeof(arr[0]); // Finding size of our array
    int target = 11; // The number we want to search for
    int index = -1; // Initializing index to -1, in case target is not found
    
    // Cheerful greetings for the user!
    printf("Hello there! I hope you're having a wonderful day.\n");
    printf("Let's find the index of %d in our array.\n", target);
    
    // Our searching algorithm!
    for(int i = 0; i < n; i++) {
        if(arr[i] == target) {
            index = i; // If target is found, set index to i
            break; // We found it, break out of the loop
        }
    }
    
    // Outputting results
    if(index == -1) {
        printf("Unfortunately, we could not find %d in our array.\n", target);
    } else {
        printf("%d is found at index %d in our array!\n", target, index);
    }
    
    // Happy goodbye to the user!
    printf("Thank you for letting me help you today. Have a fantastic day ahead!\n");
    
    return 0; // End of program
}