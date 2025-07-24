//FormAI DATASET v1.0 Category: Ebook reader ; Style: complete
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct book {
    char title[50];
    char author[50];
    char publisher[50];
    float price;
};

int main(){
    struct book b;
    FILE *fp;
    char filename[50], choice;
    printf("Enter the name of the file to be opened: ");
    gets(filename);

    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("The file does not exist.\n");
        exit(0);
    }

    printf("\n");
    printf("The contents of the file %s are: \n", filename);
    printf("Title\tAuthor\tPublisher\tPrice\n");

    while(fread(&b, sizeof(struct book), 1, fp)){
        printf("%s\t%s\t%s\t\t%.2f\n", b.title, b.author, b.publisher, b.price);
    }

    fclose(fp);

    return 0;
}