//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_ENEMY_HEALTH 20
#define MAX_PLAYER_HEALTH 50
#define MAX_ITEMS 10

struct Enemy {
    char name[MAX_NAME_LENGTH];
    int max_health;
    int health;
    int damage;
    int experience;
    int gold;
};

struct Item {
    char name[MAX_NAME_LENGTH];
    int health;
    int damage;
};

struct Player {
    char name[MAX_NAME_LENGTH];
    int level;
    int experience;
    int gold;
    int max_health;
    int health;
    int damage;
    struct Item inventory[MAX_ITEMS];
    int num_items;
};

void init_enemies(struct Enemy enemies[]) {
    strcpy(enemies[0].name, "Zog");
    enemies[0].max_health = 10;
    enemies[0].health = 10;
    enemies[0].damage = 5;
    enemies[0].experience = 10;
    enemies[0].gold = 5;

    strcpy(enemies[1].name, "Grok");
    enemies[1].max_health = 15;
    enemies[1].health = 15;
    enemies[1].damage = 7;
    enemies[1].experience = 20;
    enemies[1].gold = 10;

    strcpy(enemies[2].name, "Florg");
    enemies[2].max_health = 20;
    enemies[2].health = 20;
    enemies[2].damage = 10;
    enemies[2].experience = 30;
    enemies[2].gold = 15;

    strcpy(enemies[3].name, "Norg");
    enemies[3].max_health = 25;
    enemies[3].health = 25;
    enemies[3].damage = 15;
    enemies[3].experience = 40;
    enemies[3].gold = 20;
}

void init_items(struct Item items[]) {
    strcpy(items[0].name, "Health Potion");
    items[0].health = 10;
    items[0].damage = 0;

    strcpy(items[1].name, "Damage Potion");
    items[1].health = 0;
    items[1].damage = 5;
}

void init_player(struct Player *player) {
    printf("Enter your name: ");
    scanf("%s", player->name);
    player->level = 1;
    player->experience = 0;
    player->gold = 20;
    player->max_health = MAX_PLAYER_HEALTH;
    player->health = MAX_PLAYER_HEALTH;
    player->damage = 5;
    player->num_items = 0;
}

void print_player(struct Player player) {
    printf("Name: %s\n", player.name);
    printf("Level: %d\n", player.level);
    printf("Experience: %d\n", player.experience);
    printf("Gold: %d\n", player.gold);
    printf("Health: %d/%d\n", player.health, player.max_health);
    printf("Damage: %d\n", player.damage);
    printf("Inventory:\n");
    for (int i = 0; i < player.num_items; i++) {
        printf("- %s\n", player.inventory[i].name);
    }
}

void add_item(struct Player *player, struct Item item) {
    if (player->num_items < MAX_ITEMS) {
        player->inventory[player->num_items] = item;
        player->num_items++;
        printf("Added %s to inventory.\n", item.name);
    } else {
        printf("Inventory is full, %s not added.\n", item.name);
    }
}

void remove_item(struct Player *player, int index) {
    if (index < player->num_items) {
        printf("Removed %s from inventory.\n", player->inventory[index].name);
        player->num_items--;
        for (int i = index; i < player->num_items; i++) {
            player->inventory[i] = player->inventory[i + 1];
        }
    } else {
        printf("Invalid inventory index.\n");
    }
}

void attack(struct Player *player, struct Enemy *enemy) {
    int damage = player->damage;
    printf("%s attacks %s for %d damage!\n", player->name, enemy->name, damage);
    enemy->health -= damage;
    if (enemy->health <= 0) {
        printf("%s is defeated! You gain %d experience and %d gold.\n", enemy->name, enemy->experience, enemy->gold);
        player->experience += enemy->experience;
        player->gold += enemy->gold;
        enemy->health = enemy->max_health;
    } else {
        printf("%s has %d/%d health left.\n", enemy->name, enemy->health, enemy->max_health);
        damage = enemy->damage;
        printf("%s counterattacks for %d damage!\n", enemy->name, damage);
        player->health -= damage;
        if (player->health <= 0) {
            printf("%s has been defeated!\n", player->name);
        } else {
            printf("%s has %d/%d health left.\n", player->name, player->health, player->max_health);
        }
    }
}

void use_item(struct Player *player, int index) {
    if (index < player->num_items) {
        struct Item item = player->inventory[index];
        printf("%s uses %s.\n", player->name, item.name);
        player->health += item.health;
        if (player->health > player->max_health) {
            player->health = player->max_health;
        }
        player->damage += item.damage;
        remove_item(player, index);
    } else {
        printf("Invalid inventory index.\n");
    }
}

void main() {
    struct Enemy enemies[4];
    init_enemies(enemies);
    struct Item items[2];
    init_items(items);
    struct Player player;
    init_player(&player);

    printf("Welcome to the Procedural Space Adventure!\n");

    printf("%s boards their spaceship and sets off to explore the galaxy.\n", player.name);
    printf("%s encounters a group of hostile aliens!\n", player.name);

    int round = 1;
    while (1) {
        printf("---------------------------------------------\n");
        printf("Round %d: %s vs. %s\n", round, player.name, enemies[player.level - 1].name);
        print_player(player);
        printf("---------------------------------------------\n");

        int action;
        printf("1. Attack\n");
        printf("2. Use item\n");
        printf("3. Quit\n");
        printf("Choose an action: ");
        scanf("%d", &action);

        if (action == 1) {
            attack(&player, &enemies[player.level - 1]);
            if (player.experience >= player.level * 100) {
                player.level++;
                player.max_health += 10;
                player.health = player.max_health;
                player.damage += 2;
                printf("Congratulations, you have leveled up to level %d!\n", player.level);
            }
        } else if (action == 2) {
            printf("Inventory:\n");
            for (int i = 0; i < player.num_items; i++) {
                printf("%d. %s\n", i + 1, player.inventory[i].name);
            }
            printf("Choose an item: ");
            int item_index;
            scanf("%d", &item_index);
            use_item(&player, item_index - 1);
        } else if (action == 3) {
            printf("Exiting game...\n");
            break;
        } else {
            printf("Invalid action.\n");
        }

        if (player.health <= 0) {
            break;
        }

        if (player.level > 4) {
            printf("Congratulations, you have completed the Procedural Space Adventure!\n");
            break;
        }

        round++;
    }
}