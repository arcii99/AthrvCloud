//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: real-life
#include <stdio.h>

int main() {
    float totalRAM, usedRAM, freeRAM, usagePercentage;

    // Assuming total RAM is 8GB
    totalRAM = 8;
    
    // Simulating random RAM usage between 2GB and 6GB
    usedRAM = rand() % 5 + 2;

    freeRAM = totalRAM - usedRAM;
    
    usagePercentage = (usedRAM / totalRAM) * 100;

    printf("Total RAM: %.2fGB\n", totalRAM);
    printf("Used RAM: %.2fGB\n", usedRAM);
    printf("Free RAM: %.2fGB\n", freeRAM);
    printf("RAM usage: %.2f%%\n", usagePercentage);

    if (usagePercentage > 80) {
        printf("Warning: RAM usage is high. Consider closing programs.\n");
    }

    return 0;
}