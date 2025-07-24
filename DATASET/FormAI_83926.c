//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_DISKS 5

int tower_a[NUM_DISKS], tower_b[NUM_DISKS], tower_c[NUM_DISKS];
int top_a = -1, top_b = -1, top_c = -1;
pthread_mutex_t mutex;

void print_towers() {
    printf("\nTower A: ");
    for (int i = top_a; i >= 0; i--) {
        printf("%d ", tower_a[i]);
    }
    printf("\nTower B: ");
    for (int i = top_b; i >= 0; i--) {
        printf("%d ", tower_b[i]);
    }
    printf("\nTower C: ");
    for (int i = top_c; i >= 0; i--) {
        printf("%d ", tower_c[i]);
    }
    printf("\n");
}

int pop(int *tower, int *top) {
    if (*top == -1) {
        return -1;
    }
    int disk = tower[*top];
    *top -= 1;
    return disk;
}

void push(int disk, int *tower, int *top) {
    *top += 1;
    tower[*top] = disk;
}

void move(int *from_tower, int *from_top, int *to_tower, int *to_top) {
    int disk = pop(from_tower, from_top);
    if (disk == -1) return;
    push(disk, to_tower, to_top);
    printf("Moved disk %d from tower %c to tower %c\n", disk, from_tower == tower_a ? 'A' : (from_tower == tower_b ? 'B' : 'C'),
           to_tower == tower_a ? 'A' : (to_tower == tower_b ? 'B' : 'C'));
    print_towers();
}

void* move_tower_a_to_b(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        move(tower_a, &top_a, tower_b, &top_b);
        pthread_mutex_unlock(&mutex);
        usleep(rand() % 1000000);
    }
}

void* move_tower_b_to_c(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        move(tower_b, &top_b, tower_c, &top_c);
        pthread_mutex_unlock(&mutex);
        usleep(rand() % 1000000);
    }
}

void* move_tower_c_to_a(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        move(tower_c, &top_c, tower_a, &top_a);
        pthread_mutex_unlock(&mutex);
        usleep(rand() % 1000000);
    }
}

int main() {
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_DISKS; i++) {
        tower_a[i] = NUM_DISKS - i;
        top_a++;
    }

    pthread_t thread_a_to_b, thread_b_to_c, thread_c_to_a;
    pthread_create(&thread_a_to_b, NULL, move_tower_a_to_b, NULL);
    pthread_create(&thread_b_to_c, NULL, move_tower_b_to_c, NULL);
    pthread_create(&thread_c_to_a, NULL, move_tower_c_to_a, NULL);

    pthread_join(thread_a_to_b, NULL);
    pthread_join(thread_b_to_c, NULL);
    pthread_join(thread_c_to_a, NULL);

    pthread_mutex_destroy(&mutex);

    return 0;
}