//FormAI DATASET v1.0 Category: Educational ; Style: invasive
#include <stdio.h>

// define our invasive function 
void invasive(int n) {
    // loop through and print "Invasion Is Coming!" n times
    for(int i=0; i<n; i++) {
        printf("Invasion Is Coming!\n");
    }
}

// define our main function 
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // call the invasive function with user input as argument
    invasive(num);
    
    printf("The invasion is complete.");
    return 0;
}