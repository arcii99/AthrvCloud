//FormAI DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
    FILE *fp;
    char ch;
    char file_name[25];

    printf("Enter name of a file:\n");
    scanf("%s",file_name);

    fp = fopen(file_name, "r");

    if(fp == NULL){
      fprintf(stderr,"Error opening file: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }

    printf("\nContents of the file %s:\n",file_name);
    while((ch = fgetc(fp)) != EOF)
      printf("%c", ch);

    if(ferror(fp)){
      fprintf(stderr, "\nError reading file: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }

    fclose(fp);
    printf("\nFile closed successfully\n");
    return 0;
}