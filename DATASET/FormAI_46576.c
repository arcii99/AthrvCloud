//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Linus Torvalds
#include<stdio.h>
#include<unistd.h>

int main(){
    int *p;
    int sum=0;
    int load=0;
    while(1){
        p=(int*)malloc(1024*1024*sizeof(int));
        for(int i=0;i<=1024*1024;i++){
            p[i]=i;
            sum+=p[i];
        }
        load=((sum/(1024*1024))/100)*100;
        printf("CPU usage: %d %\n", load);
        free(p);
        sleep(1);
    }
    return 0;
}