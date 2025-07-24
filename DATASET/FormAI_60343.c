//FormAI DATASET v1.0 Category: Smart home light control ; Style: recursive
#include <stdio.h>

// Function to recursively control lights
void lightControl(int numLights, int currentLight, int state) {
    // Base case
    if (currentLight > numLights) {
        return;
    }
    
    printf("Turning Light %d %s\n", currentLight, state ? "ON" : "OFF");
    
    // Recursive cases
    lightControl(numLights, currentLight + 1, state ? 0 : 1);
    lightControl(numLights, currentLight + 2, state ? 0 : 1);
}

int main() {
    int numLights = 10;
    
    lightControl(numLights, 1, 1);
    
    return 0;
}