//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h> 

// A happy recursive function
int happyRecursiveFunction(int n) 
{ 
    // Base Case
    if (n == 0) {
        printf("Yay! We made it to the end!\n");
        return 0; 
    }
    else {
        // Let's make this recursive function more happy by adding some sparkles :)
        printf("I am on cloud 9 with the value of %d ✨\n", n);
        
        // Recursive call
        happyRecursiveFunction(n-1); 
        
        // Let's celebrate each time the recursive function is done
        printf("Woohoo! I just finished with the value of %d 💃\n", n);
        
        return 0; 
    } 
} 

int main() 
{ 
    printf("Let's start our happy recursive function dance! 🎉\n");
    
    // Call the recursive function with the value of 5
    happyRecursiveFunction(5); 
    
    printf("We had so much fun with our happy recursive function! 🤗\n");
    
    return 0; 
}