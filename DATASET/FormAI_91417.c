//FormAI DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<signal.h>
#include<sys/wait.h>

#define SENSOR_PATH "/sys/bus/w1/devices/28-3c01d607c5f3/w1_slave"

volatile sig_atomic_t flag = 0;
void handler(int sig){ // SIGINT handling function
    flag = 1;
}

int main(void){
    signal(SIGINT, handler);
    int fd;
    char buf[256], *temp;
    float temp_c;
    ssize_t nread;

    while(!flag){
        fd = open(SENSOR_PATH, O_RDONLY);
        if(fd == -1){
            perror("open");
            exit(EXIT_FAILURE);
        }

        nread = read(fd, buf, 256);
        if(nread == -1){
            perror("read");
            exit(EXIT_FAILURE);
        }

        temp = strchr(buf, '=');
        if(temp == NULL){
            fprintf(stderr, "Error: Invalid data format.\n");
            exit(EXIT_FAILURE);
        }

        temp++; // move past equal sign to actual temperature reading
        temp_c = strtof(temp, NULL) / 1000; // convert to celsius

        printf("Current temperature: %.2f C\n", temp_c);

        if(close(fd) == -1){
            perror("close");
            exit(EXIT_FAILURE);
        }

        sleep(1);
    }

    return 0;
}