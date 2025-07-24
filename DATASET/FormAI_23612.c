//FormAI DATASET v1.0 Category: System process viewer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void cryptic_sysview(){
    printf("\n\nPlease enter admin password to view system processes: ");

    char password[100];
    fgets(password, sizeof(password), stdin);

    if(strcmp(password, "swordfish\n") == 0){
        printf("Access granted\n");

        DIR *d;
        struct dirent *dir;
        d = opendir("/proc");

        if(d){
            printf("\n\n%s\n\n", "PID | Process Name | Status | Owner");
            while((dir = readdir(d)) != NULL){
                int pid = atoi(dir->d_name);
                if(pid != 0){
                    char filename[50];
                    sprintf(filename, "/proc/%d/status", pid);

                    FILE *fp = fopen(filename, "r");
                    if(fp != NULL){
                        char line[256];
                        int i = 0;
                        char name[50], status[50], owner[50];
                        while(fgets(line, sizeof(line), fp)){
                            i++;
                            if(i == 1){
                                strcpy(name, line);
                            }else if(i==3){
                                strcpy(status, line);
                            }else if(i==11){
                                strcpy(owner, line); 
                            }
                        }
                        fclose(fp);
                        printf("%s|%s|%s|%s", dir->d_name, name, status, owner);
                    }
                }
            }
            closedir(d);
        }
    }else{
        printf("Access denied\n");
    }
}

int main(){
    cryptic_sysview();
    return 0;
}