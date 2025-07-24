//FormAI DATASET v1.0 Category: Ebook reader ; Style: medieval
#include<stdio.h>
#include<stdlib.h>

int main(){
    char fileName[50];
    printf("Enter the file name to open: ");
    scanf("%s", fileName);
    FILE *file = fopen(fileName, "r");
    if(file == NULL){
        printf("Error opening the file.\n");
        exit(1);
    }
    printf("\n\n\t\t\t================================================================= \n");
    printf("\t\t\t|                     MEDIEVAL EBOOK READER                      |\n");
    printf("\t\t\t================================================================= \n\n\n");
    
    char c;
    while((c = fgetc(file)) != EOF){
        printf("%c", c);
    }

    fclose(file);
    return 0;
}