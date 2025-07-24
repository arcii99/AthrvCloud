//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUNGEON_SIZE 20
#define MAX_MONSTERS 5
#define MAX_TREASURES 2

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int health;
} Monster;

typedef struct {
    Point position;
    int value;
} Treasure;

char dungeon[DUNGEON_SIZE][DUNGEON_SIZE];
Monster monsters[MAX_MONSTERS];
Treasure treasures[MAX_TREASURES];
int num_monsters = 0;
int num_treasures = 0;

void generate_dungeon() {
    // Randomly generate the walls and floors of the dungeon
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            if (rand() % 100 < 40) {
                dungeon[i][j] = '#';
            } else {
                dungeon[i][j] = '.';
            }
        }
    }
}

void spawn_monsters() {
    // Spawn some monsters randomly in the dungeon
    int i = 0;
    while (i < MAX_MONSTERS) {
        int x = rand() % DUNGEON_SIZE;
        int y = rand() % DUNGEON_SIZE;
        if (dungeon[x][y] == '.') {
            monsters[i].position.x = x;
            monsters[i].position.y = y;
            monsters[i].health = 100;
            i++;
        }
    }
    num_monsters = MAX_MONSTERS;
}

void spawn_treasures() {
    // Spawn some treasures randomly in the dungeon
    int i = 0;
    while (i < MAX_TREASURES) {
        int x = rand() % DUNGEON_SIZE;
        int y = rand() % DUNGEON_SIZE;
        if (dungeon[x][y] == '.') {
            treasures[i].position.x = x;
            treasures[i].position.y = y;
            treasures[i].value = rand() % 100;
            i++;
        }
    }
    num_treasures = MAX_TREASURES;
}

void draw_dungeon() {
    // Draw the dungeon to the console
    for (int i = 0; i < DUNGEON_SIZE; i++) {
        for (int j = 0; j < DUNGEON_SIZE; j++) {
            printf("%c", dungeon[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void draw_monsters() {
    // Draw the monsters to the console
    for (int i = 0; i < num_monsters; i++) {
        printf("Monster %d: (%d, %d) Health: %d\n", i+1, monsters[i].position.x, monsters[i].position.y, monsters[i].health);
    }
    printf("\n");
}

void draw_treasures() {
    // Draw the treasures to the console
    for (int i = 0; i < num_treasures; i++) {
        printf("Treasure %d: (%d, %d) Value: %d\n", i+1, treasures[i].position.x, treasures[i].position.y, treasures[i].value);
    }
    printf("\n");
}

void move_player(Point *player_pos) {
    // Move the player based on user input
    char input;
    printf("Enter a direction (w,a,s,d): ");
    scanf(" %c", &input);
    switch (input) {
        case 'w':
            if (player_pos->x > 0) player_pos->x--;
            break;
        case 'a':
            if (player_pos->y > 0) player_pos->y--;
            break;
        case 's':
            if (player_pos->x < DUNGEON_SIZE-1) player_pos->x++;
            break;
        case 'd':
            if (player_pos->y < DUNGEON_SIZE-1) player_pos->y++;
            break;
        default:
            printf("Invalid input!\n");
            break;
    }
}

void attack_monsters(Point player_pos) {
    // Attack any monsters that the player is adjacent to
    for (int i = 0; i < num_monsters; i++) {
        if (abs(player_pos.x - monsters[i].position.x) <= 1 && abs(player_pos.y - monsters[i].position.y) <= 1) {
            printf("You attack Monster %d!\n", i+1);
            monsters[i].health -= rand() % 20;
            if (monsters[i].health <= 0) {
                printf("Monster %d has been defeated!\n", i+1);
                monsters[i] = monsters[num_monsters-1];
                num_monsters--;
            }
        }
    }
}

void pickup_treasures(Point player_pos) {
    // Pick up any treasures that the player is standing on
    for (int i = 0; i < num_treasures; i++) {
        if (player_pos.x == treasures[i].position.x && player_pos.y == treasures[i].position.y) {
            printf("You picked up Treasure %d worth %d gold!\n", i+1, treasures[i].value);
            treasures[i] = treasures[num_treasures-1];
            num_treasures--;
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    generate_dungeon();
    spawn_monsters();
    spawn_treasures();

    Point player_pos = {DUNGEON_SIZE/2, DUNGEON_SIZE/2}; // Start the player in the middle of the dungeon

    while (num_monsters > 0 && num_treasures > 0) {
        draw_dungeon();
        draw_monsters();
        draw_treasures();

        move_player(&player_pos);
        attack_monsters(player_pos);
        pickup_treasures(player_pos);
    }

    if (num_monsters == 0) {
        printf("Congratulations, you have defeated all the monsters!\n");
    } else {
        printf("Sorry, you died!\n");
    }

    return 0;
}