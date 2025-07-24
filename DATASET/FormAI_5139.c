//FormAI DATASET v1.0 Category: Smart home light control ; Style: expert-level
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void turnOnLights(int lights[], int size);
void turnOffLights(int lights[], int size);
void setLightLevel(int lights[], int size, int level);
bool isValidLightLevel(int level);

int main() {
    // Array of 4 lights
    int lights[] = {0, 0, 0, 0};
    int choice;

    do {
        printf("\n===== Smart Home Light Control =====\n");
        printf("1. Turn on all lights\n");
        printf("2. Turn off all lights\n");
        printf("3. Set light level\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                turnOnLights(lights, 4);
                break;
            case 2:
                turnOffLights(lights, 4);
                break;
            case 3:
                // Prompt user for light level
                int level;
                printf("Enter light level (0-100): ");
                scanf("%d", &level);

                // Validate light level
                if (!isValidLightLevel(level)) {
                    printf("Invalid light level.\n");
                    break;
                }

                // Set light level for all lights
                setLightLevel(lights, 4, level);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Functions
void turnOnLights(int lights[], int size) {
    for (int i = 0; i < size; i++) {
        lights[i] = 100;
    }
    printf("All lights turned on.\n");
}

void turnOffLights(int lights[], int size) {
    for (int i = 0; i < size; i++) {
        lights[i] = 0;
    }
    printf("All lights turned off.\n");
}

void setLightLevel(int lights[], int size, int level) {
    for (int i = 0; i < size; i++) {
        lights[i] = level;
    }
    printf("All lights set to level %d.\n", level);
}

bool isValidLightLevel(int level) {
    return (level >= 0 && level <= 100);
}