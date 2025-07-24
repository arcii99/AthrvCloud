//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: brave
#include <stdio.h>

int main() {
    char fileName[100];
    int i, len = 0;
    
    printf("Enter file name: ");
    scanf("%s", fileName);
    
    for(i=0; fileName[i] != '\0'; i++) {
        len++;
    }
    
    if(fileName[len-4] == '.' && fileName[len-3] == 'e' && fileName[len-2] == 'x' && fileName[len-1] == 'e') {
        printf("A virus has been detected in file %s.\nQuarantine the file for further inspection.\n", fileName);
    } else {
        printf("File %s is clean.\n", fileName);
    }
    
    return 0;
}