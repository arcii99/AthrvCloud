//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int health = 100;
int lives = 3;
int enemy_health = 50;
int enemy_lives = 1;
int game_over = 0;

pthread_mutex_t mutex_health;
pthread_mutex_t mutex_lives;
pthread_mutex_t mutex_enemy_health;
pthread_mutex_t mutex_enemy_lives;
pthread_mutex_t mutex_game_over;

void* fight(void* arg);

int main() {
    pthread_t thread;
    pthread_attr_t attr;

    pthread_mutex_init(&mutex_health, NULL);
    pthread_mutex_init(&mutex_lives, NULL);
    pthread_mutex_init(&mutex_enemy_health, NULL);
    pthread_mutex_init(&mutex_enemy_lives, NULL);
    pthread_mutex_init(&mutex_game_over, NULL);
    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    printf("Welcome to the adventure game!\n\n");
    printf("You are on a quest to defeat the enemy and save the kingdom. Good luck!\n\n");

    while (1) {
        pthread_create(&thread, &attr, fight, NULL);
        usleep(100 * 1000); // Sleep for 100ms
        pthread_mutex_lock(&mutex_game_over);
        if (game_over) {
            pthread_mutex_unlock(&mutex_game_over);
            break;
        }
        pthread_mutex_unlock(&mutex_game_over);
    }

    printf("Game over\n");
    printf("You have %d lives left\n", lives);

    pthread_mutex_destroy(&mutex_health);
    pthread_mutex_destroy(&mutex_lives);
    pthread_mutex_destroy(&mutex_enemy_health);
    pthread_mutex_destroy(&mutex_enemy_lives);
    pthread_mutex_destroy(&mutex_game_over);

    return 0;
}

void* fight(void* arg) {
    int damage;
    int enemy_damage;
    
    pthread_mutex_lock(&mutex_health);
    if (health <= 0) {
        printf("You died!\n");
        pthread_mutex_lock(&mutex_lives);
        lives--;
        if (lives <= 0) {
            game_over = 1;
            pthread_mutex_unlock(&mutex_game_over);
            pthread_mutex_unlock(&mutex_lives);
            pthread_mutex_unlock(&mutex_health);
            return NULL;
        }
        health = 100;
        printf("You have %d lives left\n", lives);
        pthread_mutex_unlock(&mutex_lives);
    }
    printf("Your health: %d\n", health);
    pthread_mutex_unlock(&mutex_health);

    pthread_mutex_lock(&mutex_enemy_health);
    if (enemy_health <= 0) {
        printf("You defeated the enemy!\n");
        pthread_mutex_lock(&mutex_enemy_lives);
        enemy_lives--;
        if (enemy_lives <= 0) {
            game_over = 1;
            pthread_mutex_unlock(&mutex_game_over);
            pthread_mutex_unlock(&mutex_enemy_lives);
            pthread_mutex_unlock(&mutex_enemy_health);
            return NULL;
        }
        enemy_health = 50;
        printf("Enemy lives left: %d\n", enemy_lives);
        pthread_mutex_unlock(&mutex_enemy_lives);
    }
    printf("Enemy health: %d\n", enemy_health);
    pthread_mutex_unlock(&mutex_enemy_health);

    damage = rand() % 20 + 1;
    enemy_damage = rand() % 15 + 1;

    printf("You hit the enemy for %d damage\n", damage);
    pthread_mutex_lock(&mutex_enemy_health);
    enemy_health -= damage;
    pthread_mutex_unlock(&mutex_enemy_health);

    printf("The enemy hit you for %d damage\n", enemy_damage);
    pthread_mutex_lock(&mutex_health);
    health -= enemy_damage;
    pthread_mutex_unlock(&mutex_health);

    return NULL;
}