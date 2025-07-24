//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: satisfied
#include <stdio.h>
#include <string.h>

// Virus signatures
const char *viruses[] = {
    "Trojan.Heddly.A",
    "W32.SillyFDC",
    "Win32.Parite",
    "Worm.Viking.C",
    "Backdoor.Ruledor.B",
    // add more signatures here
    NULL
};

int check_virus(const char *filename) {
    FILE *fp;
    int i, c, match = 0;
    char buf[1024];
    
    // Open the file for reading
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    
    // Read the file in 1KB chunks
    while ((c = fread(buf, 1, sizeof(buf), fp)) > 0) {
        // Check for virus signatures in the file buffer
        for (i = 0; viruses[i] != NULL; i++) {
            if (strstr(buf, viruses[i]) != NULL) {
                printf("Virus detected: %s\n", viruses[i]);
                match = 1;
                break;
            }
        }
        if (match) break;
    }
    
    // Clean up
    fclose(fp);
    return match;
}

int main(int argc, char *argv[]) {
    int i;
    
    // Check each file for viruses
    for (i = 1; i < argc; i++) {
        if (check_virus(argv[i])) {
            // Quarantine the file
            printf("Quarantine: %s\n", argv[i]);
            rename(argv[i], "quarantine/");
        } else {
            printf("No viruses found in %s\n", argv[i]);
        }
    }
    
    return 0;
}