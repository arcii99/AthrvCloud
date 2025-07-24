//FormAI DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
  
extern int errno; 
  
int main () 
{ 
    FILE *fp; 
  
    fp = fopen("nonexistent_file.txt", "r"); 
    if (fp == NULL) 
    { 
        printf("Error opening file: %s\n", strerror(errno)); 
        return errno; 
    } 
  
    fclose(fp); 
    return 0; 
}