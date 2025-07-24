//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdbool.h>

#define MAX_FILE_NAME 50

bool isVirus(char* fileName) {
    // logic to check if file contains virus
    return false;
}

int main() {
    char fileName[MAX_FILE_NAME];
    
    printf("Enter file name to scan: ");
    scanf("%s", fileName);
    
    if(isVirus(fileName)) {
        printf("Virus detected in %s\n", fileName);
    } else {
        printf("No virus detected in %s\n", fileName);
    }
    
    return 0;
}