//FormAI DATASET v1.0 Category: System boot optimizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Get the time taken by the system to boot
double getBootupTime() { 
    double bootupTime = 5.6; // Substitute with actual bootup time here
    printf("System took %f seconds to boot up.\n", bootupTime);
    return bootupTime;
}

// Display the current boot order
void displayBootOrder(char bootOrder[]) {
    printf("Current boot order: %s\n", bootOrder);
}

// Optimize the boot order to improve performance
void optimizeBootOrder(char bootOrder[]) {
    printf("Optimizing boot order...\n");
    // Substitute with actual optimization code here
    sprintf(bootOrder, "CDROM,USB,HDD,LAN");
    printf("New boot order: %s\n", bootOrder);
}

// Check if the system is low on memory
bool isSystemLowOnMemory() {
    bool isLowOnMemory = false; // Substitute with actual low memory check here
    if(isLowOnMemory) {
        printf("Low on memory. Performance may be affected.\n");
    }
    return isLowOnMemory;
}

int main() {
    char bootOrder[30] = "HDD,LAN,CDROM,USB";
    
    double bootupTime = getBootupTime();
    displayBootOrder(bootOrder);
    
    if(bootupTime > 10.0) {
        optimizeBootOrder(bootOrder);
    }
    
    if(isSystemLowOnMemory()) {
        optimizeBootOrder(bootOrder);
    }
    
    printf("System boot optimization complete.\n");
    
    return 0;
}