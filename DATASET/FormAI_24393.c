//FormAI DATASET v1.0 Category: File Backup System ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(){
    char source_file[100], destination_file[100];
    printf("Welcome to the hilarious File Backup System!\n");
    printf("Please enter the file you want to backup: \n");
    scanf("%s", source_file);
    printf("Please enter the destination the backup should go to: \n");
    scanf("%s", destination_file);
    printf("Initiating backup...\n");
    sleep(2);
    printf("Backup in progress...\n");
    sleep(3);
    printf("Backup complete! Now let's do some magic...\n");
    FILE *source, *destination;
    source = fopen(source_file, "r");
    destination = fopen(destination_file, "w");
    if(source == NULL){
        printf("Oh no! The file %s doesn't seem to exist\n", source_file);
        return 0;
    }
    else if(destination == NULL){
        printf("Looks like there was an issue creating the backup file: %s\n", destination_file);
        return 0;
    }
    else{
        printf("Processing the backup...\n");
        char ch;
        while((ch = fgetc(source)) != EOF){
            fputc(ch, destination);
        }
        fclose(source);
        fclose(destination);
        printf("Backup successfully created! Check it out at %s\n", destination_file);
    }
    return 0;
}