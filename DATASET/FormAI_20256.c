//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 1000

struct Metadata{
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    char genre[MAX_LENGTH];
    char year[MAX_LENGTH];
};

int main(int argc, char **argv){

    if(argc!=2){
        printf("Invalid argument\n");
        printf("Usage: ./metadata <filename>\n");
        exit(1);
    }

    char* filename=argv[1];
    FILE* file=fopen(filename,"r");

    if(file==NULL){
        printf("File does not exist\n");
        exit(1);
    }

    char metadata_line[MAX_LENGTH];
    struct Metadata metadata={.artist="",.album="",.genre="",.year=""};

    while(fgets(metadata_line,MAX_LENGTH,file)){

        if(strncmp(metadata_line,"Artist:",7)==0){
            strcpy(metadata.artist,&metadata_line[8]);
        }
        else if(strncmp(metadata_line,"Album:",6)==0){
            strcpy(metadata.album,&metadata_line[7]);
        }
        else if(strncmp(metadata_line,"Genre:",6)==0){
            strcpy(metadata.genre,&metadata_line[7]);
        }
        else if(strncmp(metadata_line,"Year:",5)==0){
            strcpy(metadata.year,&metadata_line[6]);
        }

    }

    fclose(file);

    printf("Artist: %s\n",metadata.artist);
    printf("Album: %s\n",metadata.album);
    printf("Genre: %s\n",metadata.genre);
    printf("Year: %s\n",metadata.year);

    return 0;
}