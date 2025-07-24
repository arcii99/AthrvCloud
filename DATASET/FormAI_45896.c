//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

#define MAX_BULLETS 100

// Game space boundaries
#define LEFT_BOUNDARY 0
#define RIGHT_BOUNDARY 79
#define TOP_BOUNDARY 0
#define BOTTOM_BOUNDARY 23

// Spaceship width and height
#define SHIP_WIDTH 5
#define SHIP_HEIGHT 3

// Enemies width and height
#define ENEMY_WIDTH 5
#define ENEMY_HEIGHT 3

// Bullet width and height
#define BULLET_WIDTH 1
#define BULLET_HEIGHT 1

char space[BOTTOM_BOUNDARY][RIGHT_BOUNDARY];

struct KeyboardInput {
    int up, down, left, right, shoot;
};

struct Point {
    int x, y;
};

struct GameObject {
    struct Point position;
    struct Point velocity;
    int width, height;
    int lives;
    char symbol;
};

struct Bullet {
    struct GameObject object;
};

struct Enemy {
    struct GameObject object;
};

struct Spaceship {
    struct GameObject object;
};

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void initScreen() {
    int i, j;

    for (i = 0; i < BOTTOM_BOUNDARY; i++) {
        for (j = 0; j < RIGHT_BOUNDARY; j++) {
            if (i == BOTTOM_BOUNDARY - 1) {
                space[i][j] = '_';
            } else {
                space[i][j] = ' ';
            }
        }
    }
}

void setupSpaceship(struct Spaceship *ship) {
    ship->object.width = SHIP_WIDTH;
    ship->object.height = SHIP_HEIGHT;
    ship->object.lives = 3;
    ship->object.symbol = 'X';
    ship->object.position.x = (RIGHT_BOUNDARY - SHIP_WIDTH) / 2;
    ship->object.position.y = BOTTOM_BOUNDARY - SHIP_HEIGHT - 1;
}

void setupEnemies(struct Enemy enemies[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        enemies[i].object.width = ENEMY_WIDTH;
        enemies[i].object.height = ENEMY_HEIGHT;
        enemies[i].object.lives = 1;
        enemies[i].object.symbol = 'O';
        enemies[i].object.position.x = rand() % (RIGHT_BOUNDARY - ENEMY_WIDTH);
        enemies[i].object.position.y = rand() % (BOTTOM_BOUNDARY / 2);
        enemies[i].object.velocity.x = (rand() % 3) - 1;
        enemies[i].object.velocity.y = (rand() % 3) - 1;
    }
}

void drawGameObject(struct GameObject *object) {
    int i, j;

    for (i = 0; i < object->height; i++) {
        for (j = 0; j < object->width; j++) {
            space[object->position.y + i][object->position.x + j] = object->symbol;
        }
    }
}

void eraseGameObject(struct GameObject *object) {
    int i, j;

    for (i = 0; i < object->height; i++) {
        for (j = 0; j < object->width; j++) {
            space[object->position.y + i][object->position.x + j] = ' ';
        }
    }
}

void drawScreen() {
    int i, j;

    system("clear");

    for (i = 0; i < BOTTOM_BOUNDARY; i++) {
        for (j = 0; j < RIGHT_BOUNDARY; j++) {
            putchar(space[i][j]);
        }
        putchar('\n');
    }
}

void updateSpaceshipPosition(struct Spaceship *ship, struct KeyboardInput *input) {
    if (input->left && ship->object.position.x > LEFT_BOUNDARY) {
        ship->object.position.x--;
    }
    if (input->right && ship->object.position.x < RIGHT_BOUNDARY - SHIP_WIDTH) {
        ship->object.position.x++;
    }
    if (input->up && ship->object.position.y > TOP_BOUNDARY) {
        ship->object.position.y--;
    }
    if (input->down && ship->object.position.y < BOTTOM_BOUNDARY - SHIP_HEIGHT - 1) {
        ship->object.position.y++;
    }
}

void moveEnemies(struct Enemy enemies[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        enemies[i].object.position.x += enemies[i].object.velocity.x;
        enemies[i].object.position.y += enemies[i].object.velocity.y;

        // Bounce enemies off walls
        if (enemies[i].object.position.x < LEFT_BOUNDARY) {
            enemies[i].object.position.x = LEFT_BOUNDARY;
            enemies[i].object.velocity.x = -enemies[i].object.velocity.x;
        }
        if (enemies[i].object.position.x > RIGHT_BOUNDARY - ENEMY_WIDTH) {
            enemies[i].object.position.x = RIGHT_BOUNDARY - ENEMY_WIDTH;
            enemies[i].object.velocity.x = -enemies[i].object.velocity.x;
        }
        if (enemies[i].object.position.y < TOP_BOUNDARY) {
            enemies[i].object.position.y = TOP_BOUNDARY;
            enemies[i].object.velocity.y = -enemies[i].object.velocity.y;
        }
        if (enemies[i].object.position.y > BOTTOM_BOUNDARY - ENEMY_HEIGHT - 1) {
            enemies[i].object.position.y = BOTTOM_BOUNDARY - ENEMY_HEIGHT - 1;
            enemies[i].object.velocity.y = -enemies[i].object.velocity.y;
        }
    }
}

void moveBullets(struct Bullet bullets[], int count) {
    int i;

    for (i = 0; i < count; i++) {
        bullets[i].object.position.x += bullets[i].object.velocity.x;
        bullets[i].object.position.y -= bullets[i].object.velocity.y;

        // Erase bullet if it goes out of screen boundaries
        if (bullets[i].object.position.y < TOP_BOUNDARY) {
            eraseGameObject(&(bullets[i].object));
            bullets[i].object.position.x = -1;
            bullets[i].object.position.y = -1;
            bullets[i].object.velocity.x = 0;
            bullets[i].object.velocity.y = 0;
        }
    }
}

void shootBullet(struct Bullet bullets[], int count, struct Spaceship *ship) {
    int i;

    for (i = 0; i < count; i++) {
        if (bullets[i].object.position.y < 0) {
            bullets[i].object.position.x = ship->object.position.x + SHIP_WIDTH / 2;
            bullets[i].object.position.y = ship->object.position.y - BULLET_HEIGHT;
            bullets[i].object.velocity.x = 0;
            bullets[i].object.velocity.y = 1;
            drawGameObject(&(bullets[i].object));
            return;
        }
    }
}

int detectCollision(struct GameObject *object1, struct GameObject *object2) {
    if (object1->position.x < object2->position.x + object2->width &&
        object1->position.x + object1->width > object2->position.x &&
        object1->position.y < object2->position.y + object2->height &&
        object1->position.y + object1->height > object2->position.y) {
        // Collision detected
        return 1;
    }
    return 0;
}

void checkCollisions(struct Spaceship *ship, struct Enemy enemies[], int enemyCount, struct Bullet bullets[], int bulletCount) {
    int i, j;

    // Check if player collided with enemy
    for (i = 0; i < enemyCount; i++) {
        if (detectCollision(&(ship->object), &(enemies[i].object))) {
            ship->object.lives--;
            eraseGameObject(&(enemies[i].object));
            enemies[i].object.position.x = rand() % (RIGHT_BOUNDARY - ENEMY_WIDTH);
            enemies[i].object.position.y = rand() % (BOTTOM_BOUNDARY / 2);
            enemies[i].object.velocity.x = (rand() % 3) - 1;
            enemies[i].object.velocity.y = (rand() % 3) - 1;
            drawGameObject(&(enemies[i].object));
        }
    }

    // Check if bullet collided with enemy
    for (i = 0; i < enemyCount; i++) {
        for (j = 0; j < bulletCount; j++) {
            if (detectCollision(&(enemies[i].object), &(bullets[j].object))) {
                enemies[i].object.lives--;
                if (enemies[i].object.lives <= 0) {
                    eraseGameObject(&(enemies[i].object));
                    enemies[i].object.position.x = rand() % (RIGHT_BOUNDARY - ENEMY_WIDTH);
                    enemies[i].object.position.y = rand() % (BOTTOM_BOUNDARY / 2);
                    enemies[i].object.velocity.x = (rand() % 3) - 1;
                    enemies[i].object.velocity.y = (rand() % 3) - 1;
                }
                eraseGameObject(&(bullets[j].object));
                bullets[j].object.position.x = -1;
                bullets[j].object.position.y = -1;
                bullets[j].object.velocity.x = 0;
                bullets[j].object.velocity.y = 0;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int i, j;
    struct KeyboardInput input = {0, 0, 0, 0, 0};
    struct Spaceship ship;
    struct Enemy enemies[10];
    struct Bullet bullets[MAX_BULLETS];

    srand(time(NULL));

    setupSpaceship(&ship);
    setupEnemies(enemies, 10);

    for (i = 0; i < MAX_BULLETS; i++) {
        bullets[i].object.width = BULLET_WIDTH;
        bullets[i].object.height = BULLET_HEIGHT;
        bullets[i].object.lives = 1;
        bullets[i].object.symbol = '|';
        bullets[i].object.position.x = -1;
        bullets[i].object.position.y = -1;
        bullets[i].object.velocity.x = 0;
        bullets[i].object.velocity.y = 0;
    }

    initScreen();

    while (ship.object.lives > 0) {
        // Handle keyboard input
        if (kbhit()) {
            switch (getchar()) {
                case 'q':
                    return 0;
                case 'a':
                    input.left = 1;
                    break;
                case 'd':
                    input.right = 1;
                    break;
                case 'w':
                    input.up = 1;
                    break;
                case 's':
                    input.down = 1;
                    break;
                case ' ':
                    input.shoot = 1;
                    break;
            }
        } else {
            input.left = 0;
            input.right = 0;
            input.up = 0;
            input.down = 0;
            input.shoot = 0;
        }

        // Move player spaceship
        eraseGameObject(&(ship.object));
        updateSpaceshipPosition(&ship, &input);
        drawGameObject(&(ship.object));

        // Move enemies
        moveEnemies(enemies, 10);

        // Move bullets and detect collisions
        moveBullets(bullets, MAX_BULLETS);
        checkCollisions(&ship, enemies, 10, bullets, MAX_BULLETS);

        // Shoot bullet if spacebar was pressed
        if (input.shoot) {
            shootBullet(bullets, MAX_BULLETS, &ship);
        }

        drawScreen();
        usleep(10000);
    }

    return 0;
}