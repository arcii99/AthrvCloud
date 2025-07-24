//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: Claude Shannon
#include <stdio.h>

int main() {
    char fileName[50];
    printf("Enter file name: ");
    scanf("%s", fileName);
    
    FILE *filePointer;
    filePointer = fopen(fileName, "r");
    
    if(filePointer == NULL) {
        printf("Error: File not found\n");
        return 0;
    }
    
    char signature[10] = "viruscode";
    char buffer[50];
    int infected = 0;
    
    while(fgets(buffer, 50, filePointer)) {
        if(strstr(buffer, signature)) {
            infected = 1;
            break;
        }
    }
    
    if(infected) {
        printf("Infected file\n");
    } else {
        printf("Clean file\n");
    }
    
    fclose(filePointer);
    return 0;
}