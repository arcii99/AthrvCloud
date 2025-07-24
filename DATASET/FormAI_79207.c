//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    char from_peg;
    char to_peg;
    char aux_peg;
} Tower;

void move_disk(char from_peg, char to_peg) {
    printf("Move disk from %c to %c\n", from_peg, to_peg);
}

void tower_of_hanoi(int n, char from_peg, char to_peg, char aux_peg) {
    if (n == 1) {
        move_disk(from_peg, to_peg);
        return;
    }
    tower_of_hanoi(n-1, from_peg, aux_peg, to_peg);
    move_disk(from_peg, to_peg);
    tower_of_hanoi(n-1, aux_peg, to_peg, from_peg);
}

int main() {
    Tower *tower = (Tower*) malloc(sizeof(Tower));
    
    printf("Enter number of disks:\n");
    scanf("%d", &tower->n);
    
    printf("Enter name of starting peg:\n");
    scanf(" %c", &tower->from_peg);
    
    printf("Enter name of destination peg:\n");
    scanf(" %c", &tower->to_peg);
    
    printf("Enter name of auxiliary peg:\n");
    scanf(" %c", &tower->aux_peg);
    
    printf("Moving %d disks from %c to %c using %c as auxilary peg:\n", 
           tower->n, tower->from_peg, tower->to_peg, tower->aux_peg);
    
    tower_of_hanoi(tower->n, tower->from_peg, tower->to_peg, tower->aux_peg);
    
    free(tower);
    return 0;
}