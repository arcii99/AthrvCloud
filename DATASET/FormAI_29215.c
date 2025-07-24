//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 256

int main(int argc, char* argv[]) {
    // Check if the user provides a directory path
    if(argc==1) {
        printf("Please provide a directory path.\n");
        return EXIT_FAILURE;
    }
    
    char cmd[BUFF_SIZE];
    snprintf(cmd, BUFF_SIZE, "du -sh %s/*", argv[1]);
    
    // Open the directory, scan its contents and print the sizes of each item
    FILE* fp = popen(cmd, "r");
    if(fp==NULL) {
        printf("Error opening directory.\n");
        return EXIT_FAILURE;
    }
    
    char buffer[BUFF_SIZE];
    while(fgets(buffer, BUFF_SIZE, fp)!=NULL) {
        printf("%s", buffer);
    }
    
    // Close the directory
    pclose(fp);
    return EXIT_SUCCESS;
}