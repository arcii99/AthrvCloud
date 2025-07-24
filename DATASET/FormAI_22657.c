//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMIES 5
#define MAX_HEALTH 10

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    char* name;
    int health;
    Coordinate position;
} Player;

typedef struct {
    char* name;
    int health;
    Coordinate position;
} Enemy;

void generateEnemies(Enemy *enemies){
    int i;
    for(i = 0; i < MAX_ENEMIES; i++){
        enemies[i].name = "Alien";
        enemies[i].health = rand() % MAX_HEALTH + 1;
        enemies[i].position.x = rand() % 10;
        enemies[i].position.y = rand() % 10;
    }
}

void movePlayer(Player *player, int x, int y){
    player->position.x += x;
    player->position.y += y;
}

void attackEnemy(Player *player, Enemy *enemy){
    printf("You attacked the %s!\n", enemy->name);
    enemy->health -= 1;
    if(enemy->health <= 0){
        printf("You defeated the %s!\n", enemy->name);
    } else {
        printf("The %s has %d health left.\n", enemy->name, enemy->health);
    }
}

void printMap(Player *player, Enemy *enemies){
    int i, j;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(player->position.x == i && player->position.y == j){
                printf("P ");
            } else {
                int k;
                int enemyFlag = 0;
                for(k = 0; k < MAX_ENEMIES; k++){
                    if(enemies[k].position.x == i && enemies[k].position.y == j && enemies[k].health > 0){
                        printf("E ");
                        enemyFlag = 1;
                        break;
                    }
                }
                if(!enemyFlag){
                    printf("- ");
                }
            }
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    Player player = {"You", MAX_HEALTH, {0, 0}};
    Enemy enemies[MAX_ENEMIES];
    generateEnemies(enemies);

    printf("Welcome to Procedural Space Adventure!\n");
    while(player.health > 0){
        printf("\nYour health: %d\n\n", player.health);
        printMap(&player, enemies);
        printf("\nChoose a direction to move in:\n");
        printf("1. Up\n");
        printf("2. Down\n");
        printf("3. Left\n");
        printf("4. Right\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                movePlayer(&player, -1, 0);
                break;
            case 2:
                movePlayer(&player, 1, 0);
                break;
            case 3:
                movePlayer(&player, 0, -1);
                break;
            case 4:
                movePlayer(&player, 0, 1);
                break;
            default:
                printf("Invalid choice.\n");
        }
        int i;
        for(i = 0; i < MAX_ENEMIES; i++){
            if(enemies[i].health > 0 && player.position.x == enemies[i].position.x && player.position.y == enemies[i].position.y){
                printf("You encountered an enemy!\n");
                printf("1. Attack\n");
                printf("2. Run\n");
                int choice;
                scanf("%d", &choice);
                if(choice == 1){
                    attackEnemy(&player, &enemies[i]);
                } else {
                    printf("You ran away.\n");
                }
                break;
            }
        }
        int enemiesLeft = 0;
        for(i = 0; i < MAX_ENEMIES; i++){
            if(enemies[i].health > 0){
                enemiesLeft++;
            }
        }
        if(enemiesLeft == 0){
            printf("\nCongratulations! You have defeated all the enemies!\n");
            break;
        }
    }

    printf("\nGame over!\n");

    return 0;
}