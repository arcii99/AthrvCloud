//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char filepath[100];
    int threat_level = 0;
    int detected_viruses = 0;

    if (argc != 2) {
        printf("Usage: ./antivirus [filepath]\n");
        return 1;
    }

    strcpy(filepath, argv[1]);

    // Pseudo-code for virus scanning algorithm
    // Imagine our algorithm is like solving an equation
    // where filepath is the unknown variable
    // and the viruses are the coefficients that affect the equation.
    // We want to check if the equation has positive coefficients (viruses).
    // If the sum of the coefficients is greater than zero,
    // then we know the equation (filepath) is infected.
    for (int i = 0; i < strlen(filepath); i++) {
        if (filepath[i] == 'v' || filepath[i] == 'V') {
            threat_level += 2; // coefficient for virus - 2
            detected_viruses++;
        } else if (filepath[i] == 't' || filepath[i] == 'T') {
            threat_level += 1; // coefficient for Trojan - 1
        } else if (filepath[i] == 'w' || filepath[i] == 'W') {
            threat_level += 3; // coefficient for Worm - 3
            detected_viruses++;
        } else if (filepath[i] == 'r' || filepath[i] == 'R') {
            threat_level += 1; // coefficient for Rootkit - 1
        }
    }

    if (detected_viruses == 0) {
        printf("The filepath %s is clean.\n", filepath);
    } else {
        printf("The filepath %s is infected with %d virus(es)!\n", filepath, detected_viruses);
        printf("Threat level: %d\n", threat_level);
    }

    return 0;
}