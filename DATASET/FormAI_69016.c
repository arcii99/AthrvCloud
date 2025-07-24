//FormAI DATASET v1.0 Category: File handling ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

//Function to read the config file
int read_config_file(char filename[], char config[][MAX_SIZE], int max_config){
    int count=0;
    FILE *fp=fopen(filename,"r");
    
    if(fp==NULL){
        printf("Error opening file!");
        exit(0);
    }
    
    char line[MAX_SIZE];
    while(fgets(line,MAX_SIZE,fp)!=NULL && count<max_config){
        if(line[0]=='#')
            continue;
        int len=0;
        while(line[len]!='\n' && len<MAX_SIZE && line[len]!='='){
            config[count][len]=line[len];
            len++;
        }
        config[count][len]='\0';
        count++;
    }
    
    fclose(fp);
    return count;
}

//Function to display the config values
void display_config(char config[][MAX_SIZE], int count){
    for(int i=0;i<count;i++){
        printf("%s ",config[i]);
    }
    printf("\n");
}

int main(){
    char config[MAX_SIZE][MAX_SIZE];
    int count=read_config_file("config.txt",config,10);
    display_config(config,count);
    return 0;
}