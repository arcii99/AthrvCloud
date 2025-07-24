//FormAI DATASET v1.0 Category: Smart home light control ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){
    int fd;
    char * light_status;
    char * buff[10];

    fd = open("/home/user/smarthome/light_control.txt", O_RDWR);

    if(fd == -1){
        printf("Error while opening the file!\n");
        exit(-1);
    }

    printf("Welcome to the Smart Home Light Control Program.\n");

    printf("The current status of the light is: ");
    read(fd, light_status, 10);
    printf("%s\n", light_status);

    printf("Enter '1' to turn on the light, '0' to turn it off: ");
    scanf("%s", buff);

    if(buff[0] == '1'){
        write(fd, "on", 2);
        printf("Light turned on successfully!\n");
    }
    else if(buff[0] == '0'){
        write(fd, "off", 3);
        printf("Light turned off successfully!\n");
    }
    else{
        printf("Invalid input!\n");
        exit(-1);
    }

    close(fd);

    return 0;
}