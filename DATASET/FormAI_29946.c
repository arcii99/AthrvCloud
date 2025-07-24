//FormAI DATASET v1.0 Category: Digital Diary ; Style: irregular
#include<stdio.h>
#include<string.h>

void main() {
    int date, month, year;
    char entry[100][100];
    char ans;
    FILE *fptr;
    fptr=fopen("diary.txt","a+");
    if(fptr==NULL) {
        printf("Error opening file.");
        exit(1);
    }
    printf("Welcome to My Digital Diary!\n");
    printf("Do you want to read previous entries? (y/n)");
    scanf("%c", &ans);
    if(ans=='y') { // read from file
        char c;
        while((c=getc(fptr))!=EOF) {
            putchar(c);
        }
    }
    printf("\n\nEnter today's date (dd mm yyyy): ");
    scanf("%d %d %d", &date, &month, &year);
    printf("Enter your entry for today: ");
    getchar(); // to remove \n from buffer
    fgets(entry[0], sizeof(entry[0]), stdin);
    printf("Would you like to add more to this entry? (y/n)");
    scanf(" %c", &ans);
    int i=1;
    while(ans=='y' && i<100) { // maximum 100 entries per day
        printf("Enter another entry: ");
        fgets(entry[i], sizeof(entry[i]), stdin);
        printf("Would you like to add more to this entry? (y/n)");
        scanf(" %c", &ans);
        i++;
    }
    fprintf(fptr, "Date: %d/%d/%d\n", date, month, year);
    fprintf(fptr, "Entries:\n");
    for(int j=0; j<i; j++) {
        fprintf(fptr, "%d. %s", j+1, entry[j]);
    }
    fprintf(fptr, "\n\n");
    printf("\nEntry added successfully!\n");
    fclose(fptr);
}