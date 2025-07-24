//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
void hanoi(int n, char source, char destination, char auxiliary){
    if(n==0){
        printf("Please enter more than 0. I am surprised that you decided to make my job tough!");
        exit(0);
    }
    if(n==1){
        printf("Moving Disk 1 from %c to %c\n", source, destination);
        return;
    }
    hanoi(n-1, source, auxiliary, destination);
    printf("Moving Disk %d from %c to %c\n", n, source, destination);
    hanoi(n-1, auxiliary, destination, source);
}
int main(){
    int n;
    printf("Please enter the number of disks:\n");
    scanf("%d", &n);
    printf("You entered %d. That's an odd number. I am surprised.\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}