//FormAI DATASET v1.0 Category: Digital signal processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len = 10;
    int sig1[] = {2, 6, 3, -4, 1, 0, 9, -5, 7, 8};
    int sig2[len];
    int i, j;
    
    printf("Original Signal: ");
    for(i=0; i<len; i++){
        printf("%d ", sig1[i]);
    }
    
    // flip signal
    printf("\n\nFlipped Signal: ");
    for(i=len-1; i>=0; i--){
        printf("%d ", sig1[i]);
    }
    
    // shift signal
    printf("\n\nShifted Signal: ");
    for(i=0; i<len; i++){
        sig2[(i+3)%len] = sig1[i];
    }
    for(i=0; i<len; i++){
        printf("%d ", sig2[i]);
    }
    
    // amplify signal
    printf("\n\nAmplified Signal: ");
    for(i=0; i<len; i++){
        sig2[i] = sig1[i] * 3;
    }
    for(i=0; i<len; i++){
        printf("%d ", sig2[i]);
    }
    
    // filter signal
    printf("\n\nFiltered Signal: ");
    for(i=1; i<len-1; i++){
        sig2[i] = (sig1[i-1] + sig1[i] + sig1[i+1]) / 3;
    }
    sig2[0] = (2*sig1[0] + sig1[1]) / 3;
    sig2[len-1] = (sig1[len-2] + 2*sig1[len-1]) / 3;
    for(i=0; i<len; i++){
        printf("%d ", sig2[i]);
    }
    
    // differentiate signal
    printf("\n\nDifferentiated Signal: ");
    for(i=1; i<len-1; i++){
        sig2[i] = (sig1[i+1] - sig1[i-1]) / 2;
    }
    sig2[0] = sig1[1];
    sig2[len-1] = -sig1[len-2];
    for(i=0; i<len; i++){
        printf("%d ", sig2[i]);
    }
    
    // integrate signal
    printf("\n\nIntegrated Signal: ");
    for(i=1; i<len-1; i++){
        sig2[i] = (sig1[i-1] + sig1[i] + sig1[i+1]) / 3;
    }
    sig2[0] = sig1[0];
    sig2[len-1] = sig1[len-1];
    for(i=1; i<len; i++){
        sig2[i] = sig2[i-1] + sig2[i];
    }
    for(i=0; i<len; i++){
        printf("%d ", sig2[i]);
    }
    
    return 0;
}