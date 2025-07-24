//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include<stdio.h>
void tower_of_hanoi(char from, char aux, char to, int n){
    if(n==1){
        printf("Move disk 1 from %c to %c\n",from,to);
        return;
    }
    tower_of_hanoi(from,to,aux,n-1);
    printf("Move disk %d from %c to %c\n",n,from,to);
    tower_of_hanoi(aux,from,to,n-1);
}

int main(){
    int n=3; //Enter the number of disks
    printf("Welcome to Tower of Hanoi post-apocalyptic style\n");
    tower_of_hanoi('A','B','C',n);
    printf("Congratulations! You have saved human race by moving all the disks to the final tower\n");
    return 0;
}