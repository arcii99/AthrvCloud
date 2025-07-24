//FormAI DATASET v1.0 Category: Digital Diary ; Style: portable
#include<stdio.h>
#include<time.h>

int main(){

    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    char filename[20];
    sprintf(filename, "diary_%02d-%02d-%04d.txt", timeinfo->tm_mday, timeinfo->tm_mon+1, timeinfo->tm_year+1900);

    FILE *fileptr;

    fileptr = fopen(filename, "a");
    if (fileptr == NULL){
        printf("Unable to open file!");
        return 1;
    }

    char entry[100];
    printf("Write your entry for today's diary: ");
    fgets(entry, 100, stdin);

    fprintf(fileptr, "%02d:%02d - %s\n", timeinfo->tm_hour, timeinfo->tm_min, entry);

    fclose(fileptr);

    printf("Your entry has been saved to %s", filename);

    return 0;

}