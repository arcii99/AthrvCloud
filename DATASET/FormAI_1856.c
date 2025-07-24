//FormAI DATASET v1.0 Category: Recursive ; Style: Sherlock Holmes
#include <stdio.h>

int findTheJewel(int roomNumber);

int main() {
    int jewel = findTheJewel(1);
    printf("The jewel was found in room %d.\n", jewel);
    return 0;
}

int findTheJewel(int roomNumber) {
    if (roomNumber == 3) return 3; // Base case: the jewel is in room 3
    printf("Examining room %d...\n", roomNumber);
    return findTheJewel(roomNumber + 1);
}