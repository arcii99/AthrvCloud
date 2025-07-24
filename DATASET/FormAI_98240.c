//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define n 5

void initialize(int tower1[], int tower2[], int tower3[]);
void print_towers(int tower1[], int tower2[], int tower3[]);
void move_tower(int disk, int source[], int dest[], int temp[]);
int* get_top(int tower[]);
void push(int disk, int tower[]);
void pop(int tower[]);

int main() {

    int tower1[n] = {0};
    int tower2[n] = {0};
    int tower3[n] = {0};

    initialize(tower1, tower2, tower3);

    printf("Initial Configuration:\n");
    print_towers(tower1, tower2, tower3);

    move_tower(n, tower1, tower2, tower3);

    printf("Final Configuration:\n");
    print_towers(tower1, tower2, tower3);

    return 0;
}

void initialize(int tower1[], int tower2[], int tower3[]) {

    srand(time(NULL));

    for(int i = 0; i < n; i++) {
        int disk = (rand() % 10) + 1;
        push(disk, tower1);
    }
}

void print_towers(int tower1[], int tower2[], int tower3[]) {

    printf("\n");

    for(int i = n-1; i >= 0; i--) {
        printf("%d\t", tower1[i]);
        printf("%d\t", tower2[i]);
        printf("%d\n", tower3[i]);
    }

    printf("-------------\n");
    printf("Tower 1\t Tower 2\t Tower 3\n\n");
}

void move_tower(int disk, int source[], int dest[], int temp[]) {

    if(disk == 1) {
        int* top = get_top(source);
        push(*top, dest);
        pop(source);
        return;
    }

    move_tower(disk-1, source, temp, dest);
    move_tower(1, source, dest, temp);
    move_tower(disk-1, temp, dest, source);
}

int* get_top(int tower[]) {

    for(int i = n-1; i >= 0; i--) {
        if(tower[i] != 0) {
            return &tower[i];
        }
    }

    return NULL;
}

void push(int disk, int tower[]) {

    int* top = get_top(tower);

    if(top == NULL) {
        tower[0] = disk;
        return;
    }

    top++;
    *top = disk;
}

void pop(int tower[]) {

    int* top = get_top(tower);

    if(top == NULL) {
        return;
    }

    *top = 0;
    top--;
}