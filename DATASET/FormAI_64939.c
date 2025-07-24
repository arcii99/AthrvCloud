//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 100

/* Function declarations */
void printHeader();
void calculateRAMUsage();

/* Main function */
int main() {

    /* Prints header information */
    printHeader();

    /* Calculation of RAM usage */
    calculateRAMUsage();

    return 0;
}

/* Prints program header */
void printHeader() {

    printf("========================================================================\n");
    printf("|                      C RAM Usage Monitor Program                     |\n");
    printf("========================================================================\n\n");
}

/* Calculates RAM usage */
void calculateRAMUsage() {

    char buff[MAXLINE];
    long int total_mem, free_mem, used_mem;

    /* Opens the file /proc/meminfo */
    FILE* filePointer = fopen("/proc/meminfo", "r");
    if (filePointer == NULL) {
        printf("Unable to open the file /proc/meminfo \n");
        exit(0);
    }

    /* Reading the required information from /proc/meminfo file */
    while(fgets(buff, MAXLINE, filePointer)){

        if(strncmp(buff, "MemTotal", 8) == 0) {
            sscanf(buff, "%*s %ld", &total_mem);
        }
        else if(strncmp(buff, "MemFree", 7) == 0) {
            sscanf(buff, "%*s  %ld", &free_mem);
        }
    }
    
    /* Closing the filePointer */
    fclose(filePointer);

    /* Computation of used memory */
    used_mem = total_mem - free_mem;

    /* Printing the RAM usage */
    printf("Total Memory: %ld kB\n", total_mem);
    printf("Free Memory : %ld kB\n", free_mem);
    printf("Used Memory : %ld kB\n", used_mem);
}