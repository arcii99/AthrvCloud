//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: cheerful
#include <stdio.h>

int main() {

    printf("Welcome to our cheerful Antivirus scanner program!\n");
    printf("Please enter the name of the file you wish to scan: \n");

    char filename[100];
    scanf("%s", filename);

    printf("Scanning file %s...\n", filename);

    // Here goes the virus scanner
    // Assume it returns a 1 if file is infected, 0 otherwise

    int infected = 0; // Assume the file is not infected by default

    if (infected) {
        printf("Virus detected in file %s. Quarantine initiated.\n", filename);
    } else {
        printf("File %s is clean. No viruses detected.\n", filename);
    }

    return 0;
}