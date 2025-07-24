//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_ROOM_SIZE 6
#define MIN_ROOM_SIZE 3
#define MAX_ROOMS 5

int map[WIDTH][HEIGHT];

struct Room {
    int x, y;
    int width, height;
};

int is_overlapping(struct Room r1, struct Room r2) {
    if (r1.x + r1.width + 1 < r2.x) {
        return 0;
    }
    if (r2.x + r2.width + 1 < r1.x) {
        return 0;
    }
    if (r1.y + r1.height + 1 < r2.y) {
        return 0;
    }
    if (r2.y + r2.height + 1 < r1.y) {
        return 0;
    }
    return 1;
}

void add_room(struct Room room) {
    for (int x = room.x; x < room.x + room.width; x++) {
        for (int y = room.y; y < room.y + room.height; y++) {
            map[x][y] = 1;
        }
    }
}

int is_valid(struct Room room) {
    if (room.x < 1 || room.x + room.width > WIDTH - 1) {
        return 0;
    }
    if (room.y < 1 || room.y + room.height > HEIGHT - 1) {
        return 0;
    }
    for (int x = room.x - 1; x < room.x + room.width + 1; x++) {
        for (int y = room.y - 1; y < room.y + room.height + 1; y++) {
            if (map[x][y] == 1) {
                return 0;
            }
        }
    }
    return 1;
}

void generate_room(struct Room *room) {
    int width = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
    int height = rand() % (MAX_ROOM_SIZE - MIN_ROOM_SIZE) + MIN_ROOM_SIZE;
    int x = rand() % (WIDTH - width - 1) + 1;
    int y = rand() % (HEIGHT - height - 1) + 1;
    *room = (struct Room){x, y, width, height};
}

int recursive_backtrack() {
    int start_x = rand() % (WIDTH - 2) + 1;
    int start_y = rand() % (HEIGHT - 2) + 1;
    int visited_count = 1;
    int visited[WIDTH][HEIGHT] = {{0}};
    int stack[WIDTH * HEIGHT][2];
    int stack_size = 0;
    int current_x = start_x;
    int current_y = start_y;
    visited[current_x][current_y] = 1;
    stack[0][0] = current_x;
    stack[0][1] = current_y;

    while (stack_size > 0) {
        int neighbour_count = 0;
        int neighbours[4][2];

        if (current_x > 1 && !visited[current_x - 2][current_y]) {
            neighbours[neighbour_count][0] = current_x - 2;
            neighbours[neighbour_count][1] = current_y;
            neighbour_count++;
        }
        if (current_x < WIDTH - 2 && !visited[current_x + 2][current_y]) {
            neighbours[neighbour_count][0] = current_x + 2;
            neighbours[neighbour_count][1] = current_y;
            neighbour_count++;
        }
        if (current_y > 1 && !visited[current_x][current_y - 2]) {
            neighbours[neighbour_count][0] = current_x;
            neighbours[neighbour_count][1] = current_y - 2;
            neighbour_count++;
        }
        if (current_y < HEIGHT - 2 && !visited[current_x][current_y + 2]) {
            neighbours[neighbour_count][0] = current_x;
            neighbours[neighbour_count][1] = current_y + 2;
            neighbour_count++;
        }

        if (neighbour_count > 0) {
            int neighbour_index = rand() % neighbour_count;
            int neighbour_x = neighbours[neighbour_index][0];
            int neighbour_y = neighbours[neighbour_index][1];
            visited[neighbour_x][neighbour_y] = 1;
            stack_size++;
            stack[stack_size][0] = neighbour_x;
            stack[stack_size][1] = neighbour_y;
            int mid_x = (current_x + neighbour_x) / 2;
            int mid_y = (current_y + neighbour_y) / 2;
            map[mid_x][mid_y] = 1;
            visited_count++;
        } else {
            stack_size--;
        }
        current_x = stack[stack_size][0];
        current_y = stack[stack_size][1];
    }
    return visited_count;
}

int main() {
    // Generate map
    int rooms_placed = 0;
    while (rooms_placed < MAX_ROOMS) {
        struct Room room;
        generate_room(&room);
        if (is_valid(room)) {
            add_room(room);
            rooms_placed++;
        }
    }

    // Generate maze
    int visited_count = recursive_backtrack();

    // Print map
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (map[x][y] == 1) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("%d cells visited\n", visited_count);

    return 0;
}