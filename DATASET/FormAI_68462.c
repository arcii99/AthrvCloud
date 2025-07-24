//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char name[50];
    int health;
    int armor;
    Position position;
} Player;

typedef struct {
    char name[50];
    int health;
    int armor;
    Position position;
} Enemy;

void printBoard(char board[][10], int x, int y) {
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char board[][10], Player *player, char direction) {

    int x = player->position.x;
    int y = player->position.y;

    if(direction == 'w' && x>0) {
        board[x][y] = '-';
        player->position.x--;
    } else if(direction == 's' && x<9) {
        board[x][y] = '-';
        player->position.x++;
    } else if(direction == 'a' && y>0) {
        board[x][y] = '-';
        player->position.y--;
    } else if(direction == 'd' && y<9) {
        board[x][y] = '-';
        player->position.y++;
    } 
    board[player->position.x][player->position.y] = 'P';
}

void moveEnemy(char board[][10], Enemy *enemy) {

    int x = enemy->position.x;
    int y = enemy->position.y;
    int dir = rand()%4;

    if(dir == 0 && x>0) {
        board[x][y] = '-';
        enemy->position.x--;
    } else if(dir == 1 && x<9) {
        board[x][y] = '-';
        enemy->position.x++;
    } else if(dir == 2 && y>0) {
        board[x][y] = '-';
        enemy->position.y--;
    } else if(dir == 3 && y<9) {
        board[x][y] = '-';
        enemy->position.y++;
    } 
    board[enemy->position.x][enemy->position.y] = 'E';
}

void fight(Player *player, Enemy *enemy) {

    int playerDamage = rand()%10 + 1;
    int enemyDamage = rand()%10 + 1;

    if(player->armor > 0) {
        player->armor--;
    } else {
        player->health -= enemyDamage;
    }

    if(enemy->armor > 0) {
        enemy->armor--;
    } else {
        enemy->health -= playerDamage;
    }
}

int main() {

    srand(time(NULL));

    Player player = {"John", 100, 10, {0, 0}};
    Enemy enemy = {"Alien", 50, 5, {9, 9}};
    char board[10][10];

    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            board[i][j] = '-';
        }
    }

    board[0][0] = 'P';
    board[9][9] = 'E';

    printf("\nA space adventure awaits you, %s!", player.name);
    printf("\nPress 'w' to move up, 's' to move down, 'a' to move left, or 'd' to move right.\n");
    printf("If you collide with an enemy, you will fight!\n\n");

    char input;
    int gameOver = 0;

    while(!gameOver) {

        printBoard(board, 10, 10);
        printf("Player health: %d, armor: %d. Enemy health: %d, armor: %d.\n", player.health, player.armor, enemy.health, enemy.armor);

        printf("Enter direction: ");
        scanf(" %c", &input);

        movePlayer(board, &player, input);
        moveEnemy(board, &enemy);

        if(player.position.x == enemy.position.x && player.position.y == enemy.position.y) {
            printf("\nYou encountered an enemy! Prepare for battle.\n");
            while(player.health > 0 && enemy.health > 0) {
                fight(&player, &enemy);
            }

            if(player.health <= 0) {
                printf("\nGame over! %s was defeated by the %s.\n", player.name, enemy.name);
                gameOver = 1;
            } else {
                printf("\nCongratulations! %s defeated the %s.\n", player.name, enemy.name);
                gameOver = 1;
            }
        }
    }
    return 0;
}