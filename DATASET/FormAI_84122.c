//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void towerOfHanoi(int n, char from, char to, char aux){
    if(n == 1){
        printf("\nMove Disk 1 from tower %c to tower %c", from, to);
        return;
    }
    towerOfHanoi(n-1, from, aux, to);
    printf("\nMove Disk %d from tower %c to tower %c", n, from, to);
    towerOfHanoi(n-1, aux, to, from);
}

int main(){
    int num_disks;
    printf("Enter the number of disks (minimum 3): ");
    scanf("%d", &num_disks);

    if(num_disks < 3){
        printf("\nAt least 3 disks are required for this problem.");
        return 0;
    }

    printf("\nPuzzle initiated...");

    //Futuristic animation
    int i, j;
    srand(time(NULL));
    for(i = 1; i <= num_disks; i++){
        for(j = 0; j < 5; j++){
            printf("\n");
            int k;
            for(k = 0; k < i; k++){
                printf("%cO%c", rand()%94+33, rand()%94+33);
            }
        }
        printf("\n");
    }

    towerOfHanoi(num_disks, 'A', 'C', 'B');

    //Completion message
    printf("\n\nPuzzle solved. Congratulations, human.");
    return 0;
}