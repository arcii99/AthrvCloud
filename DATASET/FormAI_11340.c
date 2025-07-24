//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

int main(){
    printf("Shocked! An Antivirus scanner? This sounds like a task for the toughest of coders!\n");
    printf("Alright, let's do this!\n");

    // Let's start by getting the list of files in the current directory
    struct dirent *de; // Pointer for directory entry 
    DIR *dr = opendir("."); // opendir() returns a pointer of DIR type. 
    if (dr == NULL){ 
        printf("Could not open current directory" ); 
        return 0; 
    } 

    int count=0; // Counter for scanned files

    printf("Scanning files...\n");
    while ((de = readdir(dr)) != NULL){
        if(strcmp(de->d_name,".")==0 || strcmp(de->d_name,"..")==0)
            continue; // Ignore current and parent directory

        FILE *f = fopen(de->d_name,"r");
        if(f == NULL){
            printf("Could not open file %s\n",de->d_name);
            continue;
        }

        char c[1000000];
        fgets(c,1000000,f); // Let's read just the first line to detect any suspicious activity
        fclose(f);
        
        // Let's check if the file contains the phrase "virus"
        if(strstr(c,"virus") != NULL){
            printf("WARNING: File %s may contain virus!\n",de->d_name);
        }
        count++;
    }

    closedir(dr); //Close directory pointer
    printf("%d files scanned successfully!\n",count);
    printf("Phew! That was intense! Let's hope we caught all the potential viruses!\n");

    return 0;
}