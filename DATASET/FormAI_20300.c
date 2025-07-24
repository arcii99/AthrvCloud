//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFER_SIZE 512

struct remote{
    int up;
    int down;
    int left;
    int right;
};

struct remote initialize(){
    struct remote r;
    r.up = 0;
    r.down = 0;
    r.left = 0;
    r.right = 0;
    return r;
}

void moveUp(int fd){
    write(fd, "UP\n", 3);
}

void moveDown(int fd){
    write(fd, "DOWN\n", 5);
}

void moveLeft(int fd){
    write(fd, "LEFT\n", 5);
}

void moveRight(int fd){
    write(fd, "RIGHT\n", 6);
}

int main(){
    struct remote control = initialize();
    int fd = open("/dev/cdrone", O_RDWR);
    char buffer[BUFFER_SIZE];
    while(1){
        read(fd, buffer, BUFFER_SIZE);
        if(control.up == 1){
            moveUp(fd);
            control.up = 0;
        }
        else if(control.down == 1){
            moveDown(fd);
            control.down = 0;
        }
        else if(control.left == 1){
            moveLeft(fd);
            control.left = 0;
        }
        else if(control.right == 1){
            moveRight(fd);
            control.right = 0;
        }
        if(strcmp(buffer, "up") == 0){
            control.up = 1;
        }
        else if(strcmp(buffer, "down") == 0){
            control.down = 1;
        }
        else if(strcmp(buffer, "left") == 0){
            control.left = 1;
        }
        else if(strcmp(buffer, "right") == 0){
            control.right = 1;
        }
        sleep(1);
    }
    return 0;
}