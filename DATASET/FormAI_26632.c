//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_CPU_COUNT 8 // Assuming 8 CPU Cores
#define MAX_BUFFER_SIZE 1024

int main(){
   int fds[MAX_CPU_COUNT];
   char buffer[MAX_CPU_COUNT][MAX_BUFFER_SIZE];
   char *tokens[MAX_CPU_COUNT][11];
   int prev_active[MAX_CPU_COUNT] = {0};
   int prev_total[MAX_CPU_COUNT] = {0};
   // Open all the cpu? file descriptors for reading
   for(int i=0;i < MAX_CPU_COUNT;i++){
        char filename[20];
        sprintf(filename,"/proc/stat");
        fds[i] = open(filename,O_RDONLY);
        if(fds[i] == -1){
            printf("Failed to open %s\n",filename);
            exit(1);
        }
    }
   while(1){
        int active[MAX_CPU_COUNT] = {0};
        int total[MAX_CPU_COUNT] = {0};
        lseek(fds[0],0,SEEK_SET); // Rewind the file descriptor to beginning
        for(int i=0;i<MAX_CPU_COUNT;i++){
            memset(buffer[i],0,MAX_BUFFER_SIZE);
            read(fds[i],buffer[i],MAX_BUFFER_SIZE);
            char *token = strtok(buffer[i]," ");
            for(int j=0;j<11;j++){
                tokens[i][j] = token;
	        token = strtok(NULL," ");
	        if(token == NULL) break;	
            }
    	    for(int j=1;j<11;j++) total[i] += atoi(tokens[i][j]);
            active[i] = total[i] - atoi(tokens[i][4]);
        }
    printf("CPU Core\t|  Usage\n");
    for(int i=0;i<MAX_CPU_COUNT;i++){
        float usage = 0;
        if(prev_active[i] != 0){
            int active_diff = active[i] - prev_active[i];
            int total_diff = total[i] - prev_total[i];
            usage = 100*((float)active_diff)/((float)total_diff);
        }
        printf("%d\t\t|  %.2f%%\n",i,usage);
    }
    memcpy(prev_active,active,sizeof active);
    memcpy(prev_total,total,sizeof total);

    sleep(1);
   }
}