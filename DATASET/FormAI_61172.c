//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
    FILE *fp;
    char path[1035];

    //keep monitoring every second
    while(1){
        fp = popen("free -m", "r");
        if (fp == NULL) {
             printf("Failed to run command\n" );
             exit(1);
        }

        //Read the output of "free -m"
        while (fgets(path, sizeof(path), fp) != NULL) {
            printf("%s", path);
        }

        pclose(fp);

        //delay for 1 sec
        sleep(1);
    }
    return 0;
}