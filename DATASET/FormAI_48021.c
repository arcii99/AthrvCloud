//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_ENEMIES 3
#define MAX_ITEMS 3
#define PLAYER_MAX_HEALTH 100

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int gold;
    int room_index;
} Player;

typedef struct {
    char name[20];
    int health;
    int attack;
    int defense;
    int gold;
    int rare;
} Enemy;

typedef struct {
    char name[20];
    char description[50];
    int damage;
    int is_rare;
} Item;

typedef struct {
    char name[20];
    char description[50];
    int is_boss;
    int enemy_count;
    Enemy enemies[MAX_ENEMIES];
    Item items[MAX_ITEMS];
} Room;

void print_room(Room room) {
    printf("\nYou enter a %s\n", room.name);
    printf("%s\n", room.description);
    printf("There are %d enemies.\n", room.enemy_count);
    printf("Items available in the room: ");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (strlen(room.items[i].name) > 0) {
            printf("%s ", room.items[i].name);
        }
    }
    printf("\n");
    if (room.is_boss) {
        printf("WARNING: This is a boss room.\n");
    }
}

void generate_rooms(Room rooms[]) {
    strcpy(rooms[0].name, "Abandoned Living Room");
    strcpy(rooms[0].description, "The room is filled with cobwebs and dust, and the furniture is covered in sheets.");
    rooms[0].enemy_count = 2;
    rooms[0].enemies[0].health = 25;
    rooms[0].enemies[0].attack = 10;
    rooms[0].enemies[0].defense = 5;
    rooms[0].enemies[0].gold = 10;
    rooms[0].enemies[0].rare = 0;
    rooms[0].enemies[1].health = 20;
    rooms[0].enemies[1].attack = 8;
    rooms[0].enemies[1].defense = 4;
    rooms[0].enemies[1].gold = 8;
    rooms[0].enemies[1].rare = 0;
    rooms[0].items[0].damage = 5;
    rooms[0].items[0].is_rare = 0;
    strcpy(rooms[0].items[0].name, "Rusty Dagger");

    // Add more rooms here
}

void fill_room(Room *room) {
    srand(time(NULL));
    int rare_count = 0;
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (rand() % 2 == 0) {
            room->enemies[i].health = 20 + (rand() % 10);
            room->enemies[i].attack = 5 + (rand() % 5);
            room->enemies[i].defense = 2 + (rand() % 3);
            room->enemies[i].gold = 5 + (rand() % 10);
            if (rand() % 5 == 0 && rare_count < 1) {
                room->enemies[i].rare = 1;
                rare_count++;
            } else {
                room->enemies[i].rare = 0;
            }
        } else {
            room->enemies[i].health = 0;
            room->enemies[i].attack = 0;
            room->enemies[i].defense = 0;
            room->enemies[i].gold = 0;
            room->enemies[i].rare = 0;
        }
    }
    rare_count = 0;
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (rand() % 2 == 0 && strlen(room->items[i].name) == 0) {
            room->items[i].damage = 4 + (rand() % 7);
            if (rand() % 5 == 0 && rare_count < 1) {
                room->items[i].is_rare = 1;
                rare_count++;
            } else {
                room->items[i].is_rare = 0;
            }
            if (room->items[i].is_rare == 1) {
                strcpy(room->items[i].name, "Mysterious Amulet");
                strcpy(room->items[i].description, "A strange amulet with mystical powers.");
            } else {
                strcpy(room->items[i].name, "Health Potion");
                strcpy(room->items[i].description, "A potion that restores health.");
            }
        }
    }
}

void player_attack(Player *player, Enemy *enemy) {
    int damage = player->attack - enemy->defense;
    if (damage <= 0) {
        printf("\nYou attack the %s, but it doesn't do any damage.\n", enemy->name);
    } else {
        enemy->health -= damage;
        printf("\nYou attack the %s and deal %d damage.\n", enemy->name, damage);
    }
}

void enemy_attack(Player *player, Enemy *enemy) {
    int damage = enemy->attack - player->defense;
    if (damage <= 0) {
        printf("\nThe %s attacks you, but it doesn't do any damage.\n", enemy->name);
    } else {
        player->health -= damage;
        printf("\nThe %s attacks you and deals %d damage.\n", enemy->name, damage);
    }
}

void player_use_item(Player *player, Item *item) {
    if (strcmp(item->name, "Health Potion") == 0) {
        player->health = player->health + item->damage;
        printf("\nYou drink the health potion and restore %d health.\n", item->damage);
    } else if (strcmp(item->name, "Mysterious Amulet") == 0) {
        printf("\nThe amulet glows with a strange power...\n");
        if (item->is_rare) {
            player->attack += item->damage;
            printf("...and you feel a surge of power as your attack increases by %d!\n", item->damage);
        } else {
            player->defense += item->damage;
            printf("...and you feel protected as your defense increases by %d!\n", item->damage);
        }
    }
}

void enter_room(Player *player, Room rooms[], int index) {
    int input;
    Room current_room = rooms[index];
    print_room(current_room);

    if (current_room.enemy_count > 0) {
        printf("\nYou are attacked by %d enemies!\n", current_room.enemy_count);
        for (int i = 0; i < MAX_ENEMIES; i++) {
            if (current_room.enemies[i].health > 0) {
                printf("\n%s: %d health\n", current_room.enemies[i].name, current_room.enemies[i].health);
            }
        }
        while (1) {
            printf("\nWhat will you do?\n\n");
            printf("1 - Attack\n");
            printf("2 - Use Item\n");
            scanf("%d", &input);
            if (input == 1) {
                for (int i = 0; i < MAX_ENEMIES; i++) {
                    if (current_room.enemies[i].health > 0) {
                        printf("\n%s attacks!\n", current_room.enemies[i].name);
                        enemy_attack(player, &current_room.enemies[i]);
                        if (player->health <= 0) {
                            printf("\nYou are out of health! GAME OVER.\n");
                            exit(0);
                        }
                    }
                }
                for (int i = 0; i < MAX_ENEMIES; i++) {
                    if (current_room.enemies[i].health > 0) {
                        player_attack(player, &current_room.enemies[i]);
                    }
                }
                int enemies_defeated = 0;
                for (int i = 0; i < MAX_ENEMIES; i++) {
                    if (current_room.enemies[i].health <= 0) {
                        enemies_defeated++;
                    }
                }
                if (enemies_defeated == current_room.enemy_count) {
                    printf("\nYou defeated all the enemies in the room!\n");
                    player->gold += current_room.enemy_count * 10;
                    printf("\nYou earned %d gold.\n", current_room.enemy_count * 10);
                    current_room.enemy_count = 0; // remove enemies from room
                }
            } else if (input == 2) {
                printf("\nWhat item do you want to use?\n");
                for (int i = 0; i < MAX_ITEMS; i++) {
                    if (strlen(current_room.items[i].name) > 0) {
                        printf("%d - %s\n", i + 1, current_room.items[i].name);
                    }
                }
                scanf("%d", &input);
                player_use_item(player, &current_room.items[input - 1]);
                current_room.items[input - 1].damage = 0; // remove used item from room
            }
        }
    } else {
        printf("\nThe room is empty.\n");
    }
    rooms[index] = current_room;
    player->room_index = index;
}

int main() {
    Room rooms[MAX_ROOMS];
    Player player = {"Player", PLAYER_MAX_HEALTH, 10, 5, 0, 0};

    generate_rooms(rooms);

    printf("Welcome to the Haunted House Simulator!\n");
    printf("\nYou find yourself in a dark, spooky house...\n\n");

    while (1) {
        printf("\nWhat will you do?\n\n");
        printf("1 - Move to the next room\n");
        printf("2 - Check your status\n");
        printf("3 - Quit the game\n");
        int input;
        scanf("%d", &input);
        if (input == 1) {
            if (player.room_index < MAX_ROOMS - 1) {
                player.room_index++;
                fill_room(&rooms[player.room_index]);
                enter_room(&player, rooms, player.room_index);
            } else {
                printf("\nYou have explored the entire house. Congratulations!\n");
                printf("You earned %d gold.\n", player.gold);
                exit(0);
            }
        } else if (input == 2) {
            printf("\nPlayer status:\n\n");
            printf("Name: %s\n", player.name);
            printf("Health: %d\n", player.health);
            printf("Attack: %d\n", player.attack);
            printf("Defense: %d\n", player.defense);
            printf("Gold: %d\n", player.gold);
        } else if (input == 3) {
            exit(0);
        }
    }

    return 0;
}