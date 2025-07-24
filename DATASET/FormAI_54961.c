//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){

    char url[100];

    printf("Enter the URL of the website: ");
    scanf("%s", url);

    while(1){

        FILE *fp;
        char ping_cmd[200];
        sprintf(ping_cmd, "ping -c 1 %s > /dev/null", url);
        fp = popen(ping_cmd, "r");
        pclose(fp);
        
        FILE *fileptr;
        char filename[100];
        sprintf(filename,"%s.html",url);
        fileptr=fopen(filename,"r");
        
        if(fileptr==NULL){
            printf("Website is down!\n");
            printf("Restarting server...\n");
            char restart_cmd[200];
            sprintf(restart_cmd, "sudo service apache2 restart > /dev/null");
            FILE *fp3;
            fp3= popen(restart_cmd, "r");
            pclose(fp3);
            printf("Server restarted!\n");
        }

        sleep(60);
    }
    return 0;
}