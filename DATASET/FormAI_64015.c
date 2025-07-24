//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20
#define MAX_MONSTER_COUNT 10
#define MAX_ITEMS_COUNT 10

struct Point {
    int x;
    int y;
};

struct Map {
    char tiles[MAX_HEIGHT][MAX_WIDTH];
    struct Point stairs;
};

struct Monster {
    char symbol;
    int health;
    struct Point position;
};

struct Item {
    char symbol;
    struct Point position;
};

char randomChar(char choices[], int count) {
    return choices[rand() % count];
}

void printMap(struct Map* map, struct Monster monsters[], int monsterCount, struct Item items[], int itemsCount) {
    for (int j = 0; j < MAX_HEIGHT; j++) {
        for (int i = 0; i < MAX_WIDTH; i++) {
            char symbol = ' ';
            for (int k = 0; k < monsterCount; k++) {
                if (monsters[k].position.x == i && monsters[k].position.y == j) {
                    symbol = monsters[k].symbol;
                    break;
                }
            }
            for (int k = 0; k < itemsCount; k++) {
                if (items[k].position.x == i && items[k].position.y == j) {
                    symbol = items[k].symbol;
                    break;
                }
            }
            if (i == map->stairs.x && j == map->stairs.y) {
                symbol = '>';
            } else {
                symbol = map->tiles[j][i];               
            }
            printf("%c", symbol);
        }
        printf("\n");
    }
}

void generateMap(struct Map* map) {
    // Initialize random number generator
    srand(time(NULL));
    
    // Generate blank map
    for (int j = 0; j < MAX_HEIGHT; j++) {
        for (int i = 0; i < MAX_WIDTH; i++) {
            map->tiles[j][i] = '#';
        }
    }
    
    // Add rooms to map
    int numRooms = 10;
    int minRoomSize = 3;
    int maxRoomSize = 8;
    for (int i = 0; i < numRooms; i++) {
        int roomWidth = rand() % (maxRoomSize - minRoomSize) + minRoomSize;
        int roomHeight = rand() % (maxRoomSize - minRoomSize) + minRoomSize;
        int roomX = rand() % (MAX_WIDTH - roomWidth);
        int roomY = rand() % (MAX_HEIGHT - roomHeight);
        
        for (int j = roomY; j < roomY + roomHeight; j++) {
            for (int k = roomX; k < roomX + roomWidth; k++) {
                map->tiles[j][k] = '.';
            }
        }
    }
    
    // Add hallways to map
    for (int i = 0; i < numRooms - 1; i++) {
        int startX = rand() % MAX_WIDTH;
        int startY = rand() % MAX_HEIGHT;
        int endX = rand() % MAX_WIDTH;
        int endY = rand() % MAX_HEIGHT;
        
        while (startX != endX || startY != endY) {
            if (startX < endX) {
                startX++;
            } else if (startX > endX) {
                startX--;
            }
            
            if (startY < endY) {
                startY++;
            } else if (startY > endY) {
                startY--;
            }
            
            map->tiles[startY][startX] = '.';
        }
    }
    
    // Add stairs to map
    do {
        map->stairs.x = rand() % MAX_WIDTH;
        map->stairs.y = rand() % MAX_HEIGHT;
    } while (map->tiles[map->stairs.y][map->stairs.x] != '.');
}

void generateMonsters(struct Monster monsters[], int count) {
    char choices[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
    for (int i = 0; i < count; i++) {
        monsters[i].symbol = randomChar(choices, 10);
        monsters[i].health = rand() % 10 + 1;
        monsters[i].position.x = rand() % MAX_WIDTH;
        monsters[i].position.y = rand() % MAX_HEIGHT;
    }
}

void generateItems(struct Item items[], int count) {
    char choices[] = { '!', '?', '+', '=', ')' };
    for (int i = 0; i < count; i++) {
        items[i].symbol = randomChar(choices, 5);
        items[i].position.x = rand() % MAX_WIDTH;
        items[i].position.y = rand() % MAX_HEIGHT;
    }
}

int main() {
    struct Map map;
    generateMap(&map);
    
    struct Monster monsters[MAX_MONSTER_COUNT];
    generateMonsters(monsters, MAX_MONSTER_COUNT);
    
    struct Item items[MAX_ITEMS_COUNT];
    generateItems(items, MAX_ITEMS_COUNT);
    
    while (1) {
        system("clear");
        printMap(&map, monsters, MAX_MONSTER_COUNT, items, MAX_ITEMS_COUNT);
        
        // Move monsters randomly
        for (int i = 0; i < MAX_MONSTER_COUNT; i++) {
            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;
            if (map.tiles[monsters[i].position.y + dy][monsters[i].position.x + dx] == '.') {
                monsters[i].position.x += dx;
                monsters[i].position.y += dy;
            }
        }
        
        // Check if player is dead
        int playerDead = 0;
        for (int i = 0; i < MAX_MONSTER_COUNT; i++) {
            if (monsters[i].position.x == 0 && monsters[i].position.y == 0) {
                playerDead = 1;
                break;
            }
        }
        if (playerDead) {
            printf("You died!\n");
            break;
        }
        
        // Check if player has reached the stairs
        if (monsters[0].position.x == map.stairs.x && monsters[0].position.y == map.stairs.y) {
            printf("You have reached the stairs!\n");
            break;
        }
        
        // Wait for input
        char input;
        printf("Enter direction (n/s/e/w): ");
        scanf(" %c", &input);
        
        // Move player
        int playerX = monsters[0].position.x;
        int playerY = monsters[0].position.y;
        switch (input) {
            case 'n':
                if (map.tiles[playerY - 1][playerX] == '.') {
                    monsters[0].position.y--;
                }
                break;
            case 's':
                if (map.tiles[playerY + 1][playerX] == '.') {
                    monsters[0].position.y++;
                }
                break;
            case 'e':
                if (map.tiles[playerY][playerX + 1] == '.') {
                    monsters[0].position.x++;
                }
                break;
            case 'w':
                if (map.tiles[playerY][playerX - 1] == '.') {
                    monsters[0].position.x--;
                }
                break;
        }
    }
    
    return 0;
}