//FormAI DATASET v1.0 Category: Digital Diary ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    //Create a file pointer and open the file in append mode
    FILE *fp;
    fp = fopen("diary.txt","a");

    //Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //Display and store the date in file
    fprintf(fp,"\nEntry on Date: %d-%02d-%02d\n", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);
    printf("Hello there! Welcome to your Digital Diary! Please enter your thoughts for today:\n");

    //Read and store the user input in file
    char entry[1000];
    scanf(" %[^\n]", entry);
    fprintf(fp,"Entry: %s\n",entry);

    //Close the file
    fclose(fp);
    printf("Thank You for using Digital Diary!\n");

    return 0;
}