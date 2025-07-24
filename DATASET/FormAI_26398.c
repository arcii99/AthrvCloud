//FormAI DATASET v1.0 Category: File Backup System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char original[100], backup[100];
    FILE *in, *out;

    printf("Enter the name of the file you want to backup: ");
    scanf("%s", original);
    printf("Enter the name of the backup file: ");
    scanf("%s", backup);

    in = fopen(original, "r");
    if(in == NULL){
        printf("Error opening the original file.");
        exit(1);
    }

    out = fopen(backup, "w");
    if(out == NULL){
        printf("Error opening the backup file.");
        fclose(in);
        exit(1);
    }

    char c;
    while((c = fgetc(in)) != EOF){
        fputc(c, out);
    }

    printf("Backup successful!");
    fclose(in);
    fclose(out);
    return 0;
}