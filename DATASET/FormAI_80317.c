//FormAI DATASET v1.0 Category: Searching algorithm ; Style: immersive
#include <stdio.h>

int main() {
    int treasure_room, current_room = 0;
    printf("Enter the room number of the treasure: ");
    scanf("%d", &treasure_room);
    int cave_map[] = {1, 2, 3, 4, 5, -1, 7, 8, -1, 10};
    // This cave has 10 rooms, with some rooms having no exit (-1).

    while (current_room != treasure_room) {
        printf("You are in room %d. ", current_room);
        if (current_room == -1) {
            printf("You are lost!\n");
            return 1;
        }
        current_room = cave_map[current_room];
    }

    printf("Congratulations! You found the treasure in room %d\n", current_room);
    return 0;
}