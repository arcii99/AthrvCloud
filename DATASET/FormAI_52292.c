//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: artistic
#include <stdio.h>

#define MAX_X 20
#define MAX_Y 10

typedef struct {
    int x;
    int y;
} Position;

typedef enum {
    ALIVE,
    DEAD
} LifeStatus;

typedef struct {
    Position pos;
    LifeStatus status;
    char symbol;
} Player;

typedef struct {
    Position pos;
    LifeStatus status;
    char symbol;
} Enemy;

char arena[MAX_Y][MAX_X];

void initializeArena() {
    int i, j;
    for (i = 0; i < MAX_Y; i++) {
        for (j = 0; j < MAX_X; j++) {
            arena[i][j] = '-';
        }
    }
}

Player spawnPlayer() {
    Player player = {
        .pos = {
            .x = MAX_X / 2,
            .y = MAX_Y - 1
        },
        .status = ALIVE,
        .symbol = 'X'
    };

    arena[player.pos.y][player.pos.x] = player.symbol;

    return player;
}

Enemy spawnEnemy() {
    Enemy enemy = {
        .pos = {
            .x = 0,
            .y = 0
        },
        .status = ALIVE,
        .symbol = 'O'
    };

    int enemySpawnX = rand() % MAX_X;
    int enemySpawnY = rand() % (MAX_Y / 2);

    enemy.pos.x = enemySpawnX;
    enemy.pos.y = enemySpawnY;

    arena[enemy.pos.y][enemy.pos.x] = enemy.symbol;

    return enemy;
}

void renderArena() {
    int i, j;
    for (i = 0; i < MAX_Y; i++) {
        for (j = 0; j < MAX_X; j++) {
            printf("%c", arena[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(Player *player, int direction) {
    int newX = player->pos.x + direction;

    if (newX >= 0 && newX < MAX_X) {
        arena[player->pos.y][player->pos.x] = '-';
        player->pos.x = newX;
        arena[player->pos.y][player->pos.x] = player->symbol;
    }
}

void moveEnemy(Enemy *enemy) {
    arena[enemy->pos.y][enemy->pos.x] = '-';
    enemy->pos.y += 1;
    arena[enemy->pos.y][enemy->pos.x] = enemy->symbol;

    if (enemy->pos.y >= MAX_Y) {
        enemy->status = DEAD;
    }
}

void handleInput(Player *player) {
    int direction;

    printf("Enter direction: ");
    scanf("%d", &direction);

    movePlayer(player, direction);
}

int main() {
    int gameOver = 0;
    initializeArena();
    Player player = spawnPlayer();
    Enemy enemy = spawnEnemy();

    while (!gameOver) {
        renderArena();
        handleInput(&player);
        moveEnemy(&enemy);

        if (player.pos.y == enemy.pos.y && player.pos.x == enemy.pos.x) {
            player.status = DEAD;
            gameOver = 1;
        }

        if (player.status == DEAD) {
            printf("Game Over!\n");
            return 0;
        }
    }

    return 0;
}