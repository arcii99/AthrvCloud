//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: unmistakable
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 

#define VIRUS_SIGNATURE "if(1)" 

struct file{ 
    char data[10000]; 
}; 

int main(){ 
    struct file f; 
    int i,flag=0; 

    printf("Enter the file path: "); 
    scanf("%s",f.data); 

    FILE *fp; 
    fp=fopen(f.data,"r"); 

    if (fp == NULL){ 
        printf("File cannot be opened!"); 
        exit(1); 
    } 

    char line[256];

    while(fgets(line, sizeof(line), fp)) { 
        if(strstr(line, VIRUS_SIGNATURE) != NULL) { 
            printf("Warning! The file is infected with the virus signature: %s\n",VIRUS_SIGNATURE); 
            flag=1; 
            break; 
        } 
    } 

    if(flag==0){ 
        printf("The file is not infected with any known virus signature.\n"); 
    } 

    fclose(fp); 

    return 0; 
}