//FormAI DATASET v1.0 Category: Log analysis ; Style: authentic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() 
{ 
    FILE *fp; 
    char fileName[50], line[200]; 
    int count = 0; 

    printf("Enter the file name: "); 
    scanf("%s", fileName); 

    fp = fopen(fileName, "r"); 
    if (fp == NULL) 
    { 
        printf("Error opening the file.\n"); 
        exit(1); 
    } 

    while(fgets(line, 200, fp)) 
    { 
        if(strstr(line, "ERROR")) 
        { 
            count++; 
            printf("%s", line); // Print the error line 
        } 
    } 

    printf("Total number of errors: %d\n", count); 

    fclose(fp); 
    return 0; 
}