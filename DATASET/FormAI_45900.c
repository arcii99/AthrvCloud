//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int total_memory, free_memory, used_memory;
    FILE* fp;
    char ch;
    char* str;
    fp = popen("free -m", "r");
    if(fp == NULL)
    {
        printf("Failed to run command\n");
        exit(1);
    }
    str = (char*)malloc(sizeof(char)*1000);
    while(fgets(str, 1000, fp) != NULL){
        printf("%s", str);
        if(strstr(str, "Mem:") != NULL){
            sscanf(str, "%c %d %d %d", &ch, &total_memory, &used_memory, &free_memory);
            printf("Total memory is %d MB\n",total_memory);
            printf("Used memory is %d MB\n",used_memory);
            printf("Free memory is %d MB\n",free_memory);
            break;
        }
    }
    free(str);
    pclose(fp);
    return 0;
}