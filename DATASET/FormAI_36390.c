//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include <stdio.h>
#include <string.h>

int scan_file(char * filename) {
    FILE * file;
    char virus_signature[10] = "virus123";
    char buffer[100];
    int match_found = 0;
    
    file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        return -1;
    }
    
    // Read file into buffer
    fread(buffer, sizeof(buffer), 1, file);
    
    // Check for virus signature
    if (strstr(buffer, virus_signature) != NULL) {
        printf("Virus detected in file: %s\n", filename);
        match_found++;
    }
    
    fclose(file);
    return match_found;
}

int main(int argc, char * argv[]) {
    int i, num_files, total_matches = 0;
    
    if (argc <= 1) {
        printf("Usage: ./antivirus file1 file2 ... fileN\n");
        return 0;
    }
    
    num_files = argc - 1;
    
    for (i = 1; i <= num_files; i++) {
        total_matches += scan_file(argv[i]);
    }
    
    if (total_matches > 0) {
        printf("Total matches found: %d\n", total_matches);
    } else {
        printf("No viruses found.\n");
    }
    
    return 0;
}