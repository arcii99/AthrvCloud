//FormAI DATASET v1.0 Category: File handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

int main(){
    // Open the file "art.txt" for reading
    FILE *fp;
    fp = fopen("art.txt", "r");

    if(fp == NULL){
        printf("Failed to open the file.\n");
        exit(0);
    }

    // The Art
    printf("   _____                 __  __                 \n");
    printf("  / ___/____ ___ _  __ _|  \\/  |___  ___ _  __ _\n");
    printf(" | |  / __/ __|\\ \\/ /| | |\\/| / __|/ _ \\ \\/ /| |\n");
    printf(" | |__\\__ \\__ \\ >  < | |_| |  | \\__ \\  __/>  < |_|\n");
    printf("  \\____/___/___/_/\\_\\ \\__,_|  |_|___/\\___/_/\\_(_)\n");
    printf("\n");

    // Read the contents of the file and display on the screen
    char line[100];
    printf("Here are the artists who created this masterpiece:\n");
    printf("-----------------------------------------------\n");
    while(fgets(line, 100, fp) != NULL){
        printf("%s", line);
    }
    printf("\n");

    // Close the file
    fclose(fp);

    return 0;
}