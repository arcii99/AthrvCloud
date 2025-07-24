//FormAI DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(){
    DIR *dir;
    struct dirent *dp;
    FILE *fp;
    char cmd[1024];
    char path[1024];
    char line[1024];
    printf("%-8s %-8s %-8s %-8s\n", "PID", "PPID", "USER", "CMD");
    if((dir = opendir("/proc")) == NULL) 
        perror("Failed to open /proc directory"), exit(1);   
    while((dp=readdir(dir))!=NULL) {
        if(dp->d_type==4 && atoi(dp->d_name)!=0) {
            sprintf(path, "/proc/%s/status", dp->d_name);
            if((fp=fopen(path, "r"))!=NULL) {
                char user[1024];
                int ppid=-1;
                int pid=atoi(dp->d_name);
               
                while(fgets(line, 1024, fp)!=NULL) {
                    if(sscanf(line, "PPid: %d", &ppid)==1);
                    else if(sscanf(line, "Uid: %*d %s", user)==1);
                }
                fclose(fp);
                sprintf(path, "/proc/%s/cmdline", dp->d_name);
                cmd[0]=0;
               
                if((fp=fopen(path, "r"))!=NULL) {
                    fgets(cmd, 1024, fp);
                    fclose(fp);
                }
                printf("%-8d %-8d %-8s %-8s\n", pid, ppid, user, cmd);
            }
        }           
    }
    closedir(dir);
    return 0;
}