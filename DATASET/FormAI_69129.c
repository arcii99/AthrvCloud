//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

/* Function prototypes */
int scan_file(char* filename); 

/* Main program */
int main(int argc, char* argv[]) 
{ 
    /* Check if file name was entered */
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    /* Scan file for viruses */
    if(scan_file(argv[1])) {
        printf("Virus detected in file: %s\n", argv[1]);
    } else {
        printf("File %s is clean\n", argv[1]);
    }

    return 0; 
} 

/* Scan file for viruses */
int scan_file(char* filename) 
{ 
    /* List of known viruses */
    char virus_1[] = "Flame";
    char virus_2[] = "Stuxnet";
    char virus_3[] = "Mydoom";
    
    /* Open file for reading */
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file for reading: %s\n", filename);
        return 0;
    }

    /* Search for viruses */
    char line[256];
    int virus_found = 0;
    while(fgets(line, 256, fp) != NULL) {
        if(strstr(line, virus_1) != NULL || strstr(line, virus_2) != NULL || strstr(line, virus_3) != NULL) {
            virus_found = 1;
            break;
        }
    }

    /* Close file */
    fclose(fp);

    /* Return virus found or not */
    if(virus_found) {
        return 1;
    } else {
        return 0;
    }
}