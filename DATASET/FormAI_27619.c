//FormAI DATASET v1.0 Category: Data recovery tool ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long int location; 
    char *data; 
} RecoveryNode;

void recoverData(RecoveryNode *recoveryArray, int arraySize) {
    int i, j, k; 
    int middleIndex = arraySize/2; 
    int level = 0; 
    char message[100]; 
    
    if (arraySize <= 1) {
        printf("%s\n", recoveryArray[0].data); 
        return; 
    }
    
    while (middleIndex > 0) {
        sprintf(message, "\n%sLevel %d\n", (level == 0)? "" : "\t", level); 
        printf("%s", message); 
        for (i = 0; i < middleIndex; i++) {
            printf("%s", (recoveryArray[i].data)? recoveryArray[i].data : "NULL"); 
            printf("\t"); 
        }
        printf("\n"); 
        
        for (i = 0, j = middleIndex, k = 0; k < arraySize - 1; k++) {
            if ((j >= arraySize) || ((i < middleIndex) && 
                (recoveryArray[i].location < recoveryArray[j].location))) {
                recoveryArray[k] = recoveryArray[i]; 
                i++; 
            } else {
                recoveryArray[k] = recoveryArray[j]; 
                j++; 
            }            
        }
        middleIndex /= 2;
        level++; 
    }
    printf("\n"); 
    recoverData(recoveryArray, arraySize/2); 
}

int main() {
    RecoveryNode recoveryArray[10]; 
    int i; 
    
    recoveryArray[0].location = 13; 
    recoveryArray[0].data = "Hello "; 
    recoveryArray[1].location = 32; 
    recoveryArray[1].data = "world"; 
    recoveryArray[2].location = 7; 
    recoveryArray[2].data = "please"; 
    recoveryArray[3].location = 20; 
    recoveryArray[3].data = "help "; 
    recoveryArray[4].location = 2; 
    recoveryArray[4].data = "me"; 
    recoveryArray[5].location = 64; 
    recoveryArray[6].location = 45; 
    recoveryArray[7].location = 14; 
    recoveryArray[8].location = 85; 
    recoveryArray[9].location = 91; 
    
    printf("Original Array:\n"); 
    for (i = 0; i < 10; i++) {
        printf("%s: ", recoveryArray[i].data); 
        printf("%ld\n", recoveryArray[i].location); 
    }

    recoverData(recoveryArray, 10); 
    return 0; 
}