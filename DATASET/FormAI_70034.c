//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct spaceship {
    char *name;
    int health;
    int speed;
    int damage;
};

typedef struct spaceship spaceship;

int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void attack_spaceship(spaceship *attacker, spaceship *defender) {
    printf("%s attacks %s for %d damage!\n", attacker->name, defender->name, attacker->damage);
    defender->health -= attacker->damage;
}

void move_spaceship(spaceship *s) {
    printf("%s is moving at %d speed!\n", s->name, s->speed);
}

int main() {

    srand(time(0)); // seed random number generator
    
    spaceship player = {"Player", 100, 10, 20};
    
    spaceship enemy1 = {"Enemy 1", 75, generate_random_number(5, 20), generate_random_number(10, 15)};
    spaceship enemy2 = {"Enemy 2", 50, generate_random_number(5, 20), generate_random_number(10, 15)};
    spaceship enemy3 = {"Enemy 3", 125, generate_random_number(5, 20), generate_random_number(10, 15)};
    
    printf("Welcome to the Procedural Space Adventure Game!\n\n");
    printf("Your mission is to defeat all enemy spaceships to save the galaxy!\n\n");

    move_spaceship(&player);
    
    attack_spaceship(&player, &enemy1);
    attack_spaceship(&player, &enemy1);
    attack_spaceship(&player, &enemy1);
    
    move_spaceship(&player);
    
    attack_spaceship(&enemy1, &player);
    attack_spaceship(&enemy1, &player);

    move_spaceship(&player);
    
    attack_spaceship(&player, &enemy2);
    attack_spaceship(&player, &enemy2);
    attack_spaceship(&player, &enemy2);
    
    move_spaceship(&player);
    
    attack_spaceship(&enemy2, &player);
    attack_spaceship(&enemy2, &player);
    
    move_spaceship(&player);
    
    attack_spaceship(&enemy3, &player);
    attack_spaceship(&enemy3, &player);
    attack_spaceship(&enemy3, &player);
    
    printf("Congratulations! You saved the galaxy!\n\n");

    return 0;
}