//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

void hanoi(int num_of_disks,char source,char auxiliary,char destination){
    if(num_of_disks==1){
        printf("Move disk 1 from %c to %c\n",source,destination);
        return;
    }
    hanoi(num_of_disks-1,source,destination,auxiliary);
    printf("Move disk %d from %c to %c\n",num_of_disks,source,destination);
    hanoi(num_of_disks-1,auxiliary,source,destination);
}

int main(){
    int num_of_disks;
    printf("Enter the number of disks in the tower of Hanoi: ");
    scanf("%d",&num_of_disks);
    if(num_of_disks<1){
        printf("Invalid number of disks\n");
        return 0;
    }
    printf("Surrealist Tower of Hanoi!\n");
    printf("Observe the transmigration of the Leona Helena Oracles in a circular vortex!\n");
    hanoi(num_of_disks,'A','B','C');
    printf("The Surrealism is now complete.\n");
    return 0;
}