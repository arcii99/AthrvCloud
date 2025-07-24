//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    while(1){
        pid_t pid=fork();
        if(pid == 0){
            //child process
            FILE* file=fopen("/proc/stat","r");
            fseek(file,0L,SEEK_SET);
            long double user1,nice,idle1,system1,idle2;
            fscanf(file,"cpu %Lf %Lf %Lf %Lf %Lf",&user1,&nice,&system1,&idle1,&idle2);
            fclose(file);
            sleep(1);
            file=fopen("/proc/stat","r");
            fseek(file,0L,SEEK_SET);
            long double user2,nice2,idle3,system2,idle4;
            fscanf(file,"cpu %Lf %Lf %Lf %Lf %Lf",&user2,&nice2,&system2,&idle3,&idle4);
            fclose(file);

            long double diff1=user2-user1;
            long double diff2=system2-system1;
            long double diff3=nice2-nice;
            long double sum=diff1+diff2+diff3+idle3-idle1;

            if(sum!=0){
                printf("CPU Usage: %.2Lf%%\n",100*(diff1+diff2+diff3)/sum);
            }
            else{
                 printf("CPU Usage: 0.00%%\n");
            }
            exit(0);
        }
        else{
            //parent process
            waitpid(pid,NULL,0);
        }
    }
    return 0;
}