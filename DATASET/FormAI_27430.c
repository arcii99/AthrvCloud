//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Romeo and Juliet
#include <stdio.h>

void Hanoi(int count, int towerA[], int towerB[], int towerC[]){
    if(count >= 1){
        Hanoi(count-1, towerA, towerC, towerB);
        int disk = towerA[0];
        printf("Move disk %d from Tower %c to Tower %c\n", disk, 'A', 'C');
        towerC[0] = disk;
        towerA[0] = 0;
        Hanoi(count-1, towerB, towerA, towerC);
    }
}

int main(){
    int count = 3; //number of disks
    int towerA[3] = {3,2,1};
    int towerB[3] = {0,0,0};
    int towerC[3] = {0,0,0};
    Hanoi(count, towerA, towerB, towerC);
    return 0;
}