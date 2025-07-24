//FormAI DATASET v1.0 Category: Digital signal processing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int sig1 = 0, sig2 = 0, output = 0;
    
    printf("Enter two digital signals (0 or 1): ");
    scanf("%d %d", &sig1, &sig2);
    
    printf("Processing signals asynchronously...\n");
    
    if(sig1 == 1){
        printf("Signal 1 detected! Processing...\n");
        sleep(1); // Simulate processing delay
        
        if(sig2 == 1){
            printf("Signal 2 detected while processing signal 1! Outputting 1...\n");
            output = 1;
        }else{
            printf("Signal 2 not detected while processing signal 1! Outputting 0...\n");
            output = 0;
        }
    }else{
        printf("Signal 1 not detected! Outputting 0...\n");
        output = 0;
    }
    
    printf("Final output: %d\n", output);
    
    return 0;
}