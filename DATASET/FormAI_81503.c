//FormAI DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function for home automation
void smart_home(int room_number) {
    // Base case
    if (room_number <= 0) {
        printf("All lights are turned off.\n");
        return;
    }

    // Recursive case
    else {
        printf("Lights in room %d are turned on.\n", room_number);
        smart_home(room_number - 1);
    }
}

int main() {
    int rooms;
    printf("Enter the number of rooms in your house: ");
    scanf("%d", &rooms);

    // Check for valid input
    if (rooms <= 0) {
        printf("Invalid input.\n");
        exit(0);
    }

    // Call the recursive function for home automation
    smart_home(rooms);

    return 0;
}