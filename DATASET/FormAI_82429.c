//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h> 

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 20
#define PLAYER_WIDTH 5
#define PLAYER_HEIGHT 1
#define ENEMY_WIDTH 3
#define ENEMY_HEIGHT 1
#define BULLET_WIDTH 1
#define BULLET_HEIGHT 1
#define MAX_ENEMIES 10
#define MAX_BULLETS 3

typedef struct {
    int x;
    int y;
} Vec2;

typedef struct {
    Vec2 pos;
    int width;
    int height;
} Entity;

typedef struct {
    Entity entity;
    bool active;
} Bullet;

typedef struct {
    Entity entity;
    bool isAlive;
} Enemy;

typedef struct {
    Entity entity;
    int score;
    int livesLeft;
} Player;

// Player Movement Functions
void MoveLeft(Player *player) {
    if(player->entity.pos.x > 0) {
        player->entity.pos.x--;
    }
}

void MoveRight(Player *player) {
    if(player->entity.pos.x + player->entity.width < SCREEN_WIDTH) {
        player->entity.pos.x++;
    }
}

// Vector Functions
Vec2 CreateVec2(int x, int y) {
    Vec2 vec;
    vec.x = x;
    vec.y = y;
    return vec;
}

Vec2 Vec2Add(Vec2 vec1, Vec2 vec2) {
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    return vec1;
}

// Entity Functions
bool CheckCollision(Entity entity1, Entity entity2) {
    if((entity1.pos.y + entity1.height) < entity2.pos.y) return false;
    if(entity1.pos.y > (entity2.pos.y + entity2.height)) return false;
    if((entity1.pos.x + entity1.width) < entity2.pos.x) return false;
    if(entity1.pos.x > (entity2.pos.x + entity2.width)) return false;
    return true;
}

// Bullet Functions
void InitBullet(Bullet *bullet, Vec2 pos) {
    bullet->entity.pos = pos;
    bullet->entity.width = BULLET_WIDTH;
    bullet->entity.height = BULLET_HEIGHT;
    bullet->active = true;
}

Vec2 MoveBulletUp(Vec2 pos) {
    pos.y--;
    return pos;
}

void DrawBullet(Bullet bullet) {
    printf("\033[%d;%dH*\033[0m", bullet.entity.pos.y, bullet.entity.pos.x);
}

void DestroyBullet(Bullet *bullet) {
    bullet->active = false;
}

// Enemy Functions
void InitEnemy(Enemy *enemy, Vec2 pos) {
    enemy->entity.pos = pos;
    enemy->entity.width = ENEMY_WIDTH;
    enemy->entity.height = ENEMY_HEIGHT;
    enemy->isAlive = true;
}

Vec2 MoveEnemyDown(Vec2 pos) {
    pos.y++;
    return pos;
}

void DrawEnemy(Enemy enemy) {
    printf("\033[%d;%dH@\033[0m", enemy.entity.pos.y, enemy.entity.pos.x);
}

void DestroyEnemy(Enemy *enemy) {
    enemy->isAlive = false;
}

// Player Functions
void InitPlayer(Player *player, Vec2 pos) {
    player->entity.pos = pos;
    player->entity.width = PLAYER_WIDTH;
    player->entity.height = PLAYER_HEIGHT;
    player->score = 0;
    player->livesLeft = 3;
}

void KillPlayer(Player *player) {
    player->livesLeft--;
    player->entity.pos = CreateVec2(SCREEN_WIDTH/2 - PLAYER_WIDTH/2, SCREEN_HEIGHT - PLAYER_HEIGHT - 1); // player repositioned to centre
}

void DrawPlayer(Player player) {
    printf("\033[%d;%dH%c%c%c%c%c\033[0m", player.entity.pos.y,
           player.entity.pos.x, '/', '=', '=', '=', '\\');
}

// Game Functions
void DrawBorders() {
    // Draw top border
    printf("\033[%d;%dH", 0, 0);
    for(int i = 0; i < SCREEN_WIDTH; i++) {
        printf("_");
    }

    // Draw bottom border
    printf("\033[%d;%dH", SCREEN_HEIGHT, 0);
    for(int i = 0; i < SCREEN_WIDTH; i++) {
        printf("_");
    }

    // Draw left and right borders
    for(int i = 1; i < SCREEN_HEIGHT; i++) {
        printf("\033[%d;%dH|", i, 0); // left
        printf("\033[%d;%dH|", i, SCREEN_WIDTH-1); // right
    }
}

void DrawGameInfo(Player player) {
    char scoreStr[10], livesStr[3];
    sprintf(scoreStr, "Score: %d", player.score);
    sprintf(livesStr, "L: %d", player.livesLeft);
    printf("\033[%d;%dH%s\033[0m", SCREEN_HEIGHT+2, 0, scoreStr);
    printf("\033[%d;%dH%s\033[0m", SCREEN_HEIGHT+2, SCREEN_WIDTH-3, livesStr);
}

void SpawnEnemies(Enemy enemies[]) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        InitEnemy(&enemies[i], CreateVec2(i * (ENEMY_WIDTH+1) + 1, 2));
    }
}

void DrawEnemies(Enemy enemies[]) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(enemies[i].isAlive) DrawEnemy(enemies[i]);
    }
}

void InitBullets(Bullet bullets[]) {
    for(int i = 0; i < MAX_BULLETS; i++) {
        bullets[i].active = false;
    }
}

void FireBullet(Bullet bullets[], Player player) {
    for(int i = 0; i < MAX_BULLETS; i++) {
        if(!bullets[i].active) {
            InitBullet(&bullets[i], MoveBulletUp(Vec2Add(player.entity.pos, CreateVec2(PLAYER_WIDTH/2, 0))));
            break;
        }
    }
}

void DrawBullets(Bullet bullets[]) {
    for(int i = 0; i < MAX_BULLETS; i++) {
        if(bullets[i].active) DrawBullet(bullets[i]);
    }
}

void UpdateBullets(Bullet bullets[], Enemy enemies[], Player *player) {
    for(int i = 0; i < MAX_BULLETS; i++) {
        if(bullets[i].active) {
            bullets[i].entity.pos = MoveBulletUp(bullets[i].entity.pos);

            // Check if bullet hit an enemy
            for(int j = 0; j < MAX_ENEMIES; j++) {
                if(enemies[j].isAlive) {
                    if(CheckCollision(bullets[i].entity, enemies[j].entity)) {
                        DestroyBullet(&bullets[i]);
                        DestroyEnemy(&enemies[j]);
                        player->score++;
                    }
                }
            }

            // Check if bullet hit top of screen
            if(bullets[i].entity.pos.y <= 0) DestroyBullet(&bullets[i]);
        }
    }
}

void UpdateEnemies(Enemy enemies[], Player *player) {
    for(int i = 0; i < MAX_ENEMIES; i++) {
        if(enemies[i].isAlive) {
            enemies[i].entity.pos = MoveEnemyDown(enemies[i].entity.pos);

            // Check if enemy hit bottom of screen
            if(enemies[i].entity.pos.y >= SCREEN_HEIGHT) {
                DestroyEnemy(&enemies[i]);
                KillPlayer(player);
            }

            // Check if enemy collided with player
            if(CheckCollision(enemies[i].entity, player->entity)) {
                DestroyEnemy(&enemies[i]);
                KillPlayer(player);
            }
        }
    }
}

int main() {
    Player player;
    InitPlayer(&player, CreateVec2(SCREEN_WIDTH/2 - PLAYER_WIDTH/2, SCREEN_HEIGHT - PLAYER_HEIGHT - 1));

    Bullet bullets[MAX_BULLETS];
    InitBullets(bullets);

    Enemy enemies[MAX_ENEMIES];
    SpawnEnemies(enemies);

    char input;

    while(player.livesLeft) {
        system("clear");
        DrawBorders();
        DrawGameInfo(player);
        DrawPlayer(player);
        DrawEnemies(enemies);
        DrawBullets(bullets);

        UpdateBullets(bullets, enemies, &player);
        UpdateEnemies(enemies, &player);

        input = getchar();
        if(input == 'a') MoveLeft(&player);
        if(input == 'd') MoveRight(&player);
        if(input == ' ') FireBullet(bullets, player);
    }

    printf("\033[%d;%dHGAME OVER\033[0m", SCREEN_HEIGHT/2, SCREEN_WIDTH/2 - 4);

    return 0;
}