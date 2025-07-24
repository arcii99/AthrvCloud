//FormAI DATASET v1.0 Category: Funny ; Style: peaceful
#include <stdio.h>

int main() {
    
    int peacefulVariable = 0;
    
    while(1) { // loop forever
        
        peacefulVariable++;
        
        if(peacefulVariable % 5 == 0 && peacefulVariable % 3 == 0) { // if divisible by both 5 and 3
            printf("Peaceful Beach\n");
        }
        else if(peacefulVariable % 5 == 0) { // if only divisible by 5
            printf("Peaceful\n");
        }
        else if(peacefulVariable % 3 == 0) { // if only divisible by 3
            printf("Beach\n");
        }
        else { // if not divisible by either
            printf("%d\n", peacefulVariable);
        }
        
        if(peacefulVariable == 50) { // stop at 50
            break;
        }
        
    }
    
    return 0;
}