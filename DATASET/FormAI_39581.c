//FormAI DATASET v1.0 Category: Digital Diary ; Style: energetic
#include<stdio.h>

int main()
{
    char date[20], time[20], entry[500];
    FILE *fptr;

    fptr = fopen("my_diary.txt", "a+"); // opening file in append mode

    printf("Enter the entry date in dd/mm/yyyy format: ");
    scanf("%s", &date);
    fprintf(fptr, "\nEntry Date: %s\n", date); // writing date to the file

    printf("Enter the entry time in hh:mm format: ");
    scanf("%s", &time);
    fprintf(fptr, "Entry Time: %s\n", time); // writing time to the file

    printf("Enter your thoughts and feelings for today: ");
    getchar(); // to clear the keyboard buffer
    fgets(entry, 500, stdin);
    fprintf(fptr, "Entry: %s\n", entry); // writing thoughts to the file

    printf("\nSuccessfully written to the diary!\n");

    fclose(fptr); // closing the file

    return 0;
}