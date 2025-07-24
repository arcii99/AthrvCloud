//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// This function will check the file contents for any suspicious strings.
int contains_suspicious_strings(char* contents) {
    return (strstr(contents, "malware") != NULL || strstr(contents, "virus") != NULL);
}

// This function will run our antivirus scan on a given file.
void run_antivirus_scan(char* filename) {
    // Open the file.
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return;
    }
    
    // Read the file contents.
    char contents[1000];
    fgets(contents, sizeof(contents), file);
    
    // Check the file contents for any suspicious strings.
    if (contains_suspicious_strings(contents)) {
        printf("Warning: file %s contains suspicious code!\n", filename);
    } else {
        printf("File %s is clean.\n", filename);
    }
    
    // Close the file.
    fclose(file);
}

int main() {
    // Run the antivirus scan on some example files.
    run_antivirus_scan("example1.txt");
    run_antivirus_scan("example2.txt");
    run_antivirus_scan("example3.txt");
    return 0;
}