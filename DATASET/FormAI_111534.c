//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

void scan(char* path){
    DIR *dir = opendir(path);
    struct dirent *entry;   
    char *exe = ".exe";
    while((entry = readdir(dir)) != NULL){
        char *filepath = malloc(strlen(path)+strlen(entry->d_name)+2);
        sprintf(filepath,"%s/%s",path,entry->d_name);
        if(entry->d_type == DT_DIR && strcmp(entry->d_name,".")!= 0 && strcmp(entry->d_name,"..")!=0)
            scan(filepath);
        else{
            if(strstr(filepath,exe) != NULL)
                printf("\nFound virus in %s",filepath);
        }
        free(filepath);
    }
    closedir(dir);
}

int main(){
    char* path = "/home/user/Desktop";
    printf("Starting antivirus scan, please wait....");
    scan(path);
    printf("\nScan completed successfully!");
    return 0;
}