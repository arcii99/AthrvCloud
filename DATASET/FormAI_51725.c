//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>

/* This is a program that solves the Tower of Hanoi problem with a unique twist! The tower now consists of 
   three towers, each with a different set of disks. The goal is to swap the positions of any two disks 
   while adhering to the rules of the game. */

void drawTower(int t1[], int t2[], int t3[], int length){  // Helper function to print towers
    for(int i = length - 1; i >= 0; i--){  
        printf("%d\t%d\t%d\n", t1[i], t2[i], t3[i]);
    }
    printf("------\t------\t------\n");
}

void move(int t1[], int t2[], int t3[], int from, int to, int length){  // Recursive function to solve game
    if(length == 1){  // Base case
        if(from == 1 && to == 2){  // Moving disk from tower 1 to 2
            t2[length - 1] = t1[length - 1];
            t1[length - 1] = 0;
        }
        else if(from == 1 && to == 3){  // Moving disk from tower 1 to 3
            t3[length - 1] = t1[length - 1];
            t1[length - 1] = 0;
        }
        else if(from == 2 && to == 1){  // Moving disk from tower 2 to 1
            t1[length - 1] = t2[length - 1];
            t2[length - 1] = 0;
        }
        else if(from == 2 && to == 3){  // Moving disk from tower 2 to 3
            t3[length - 1] = t2[length - 1];
            t2[length - 1] = 0;
        }
        else if(from == 3 && to == 1){  // Moving disk from tower 3 to 1
            t1[length - 1] = t3[length - 1];
            t3[length - 1] = 0;
        }
        else if(from == 3 && to == 2){  // Moving disk from tower 3 to 2
            t2[length - 1] = t3[length - 1];
            t3[length - 1] = 0;
        }
        drawTower(t1, t2, t3, length);  // Draw the resulting tower
    }
    else{  // Recursive case
        int other;
        if(from == 1 && to == 2){  // Other tower is 3
            other = 3;
        }
        else if(from == 1 && to == 3){  // Other tower is 2
            other = 2;
        }
        else if(from == 2 && to == 1){  // Other tower is 3
            other = 3;
        }
        else if(from == 2 && to == 3){  // Other tower is 1
            other = 1;
        }
        else if(from == 3 && to == 1){  // Other tower is 2
            other = 2;
        }
        else if(from == 3 && to == 2){  // Other tower is 1
            other = 1;
        }
        move(t1, t2, t3, from, other, length - 1);
        move(t1, t2, t3, from, to, 1);
        move(t1, t2, t3, other, to, length - 1);
    }
}

int main(){
    int n1, n2, n3;  // Number of disks in each tower
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("Please enter the number of disks in the first tower: ");
    scanf("%d", &n1);
    printf("Please enter the number of disks in the second tower: ");
    scanf("%d", &n2);
    printf("Please enter the number of disks in the third tower: ");
    scanf("%d", &n3);
    int t1[n1], t2[n2], t3[n3];  // Declare towers
    for(int i = 0; i < n1; i++){  // Initialize first tower with correct number of disks
        t1[i] = n1 - i;
    }
    for(int i = 0; i < n2; i++){  // Initialize second tower with correct number of disks
        t2[i] = n2 - i;
    }
    for(int i = 0; i < n3; i++){  // Initialize third tower with correct number of disks
        t3[i] = n3 - i;
    }
    printf("\nHere is the starting tower:\n");
    drawTower(t1, t2, t3, (n1 + n2 + n3));  // Draw the starting tower
    printf("Please enter the tower numbers to swap the disks (1, 2, or 3):\n");
    int from, to;
    printf("From: ");
    scanf("%d", &from);
    printf("To: ");
    scanf("%d", &to);
    move(t1, t2, t3, from, to, (n1 + n2 + n3));  // Solve the game recursively
    return 0;
}