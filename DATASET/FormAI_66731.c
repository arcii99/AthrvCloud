//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: retro
#include <stdio.h>
#include <string.h>

// Main function
int main() {
    // Define variables
    char filename[20];
    char virus[5][20] = {"Trojan", "Worm", "Spyware", "Adware", "Malware"};
    int found = 0, i, j;
    
    // Ask for filename
    printf("Enter the filename to scan: ");
    scanf("%s", filename);
    
    // Open file
    FILE *file;
    file = fopen(filename,"r");
    
    // Check if file exists
    if(file == NULL) {
        printf("\nFile not found.\n");
        return 0;
    }
    
    // Read file content
    char line[100];
    while(fgets(line, 100, file) != NULL) {
        for(i = 0; i < 5; i++) {
            if(strstr(line, virus[i])) {
                printf("\nVirus found: %s\n", virus[i]);
                found = 1;
            }
        }
    }
    
    // Close file
    fclose(file);
    
    // If virus not found
    if(found == 0) {
        printf("\nNo viruses found in file.\n");
    }
    
    return 0;
}