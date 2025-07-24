//FormAI DATASET v1.0 Category: Dice Roller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

void async_dice_roller() {
    int fd[2];
    pipe(fd);
    int pid = fork();
    if (pid == 0) {
        // Child process
        close(fd[0]);
        srand(time(NULL));
        int roll = rand() % 6 + 1;
        write(fd[1], &roll, sizeof(roll));
        close(fd[1]);
    } else {
        // Parent process
        close(fd[1]);
        int roll;
        read(fd[0], &roll, sizeof(roll));
        printf("The roll is: %d\n", roll);
        close(fd[0]);
    }
}

int main() {
    async_dice_roller();
    return 0;
}