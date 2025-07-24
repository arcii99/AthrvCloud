//FormAI DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    
    int choice = -1;
    int cnt = 0;
    char entries[1000][1000];
    
    while(choice != 0) {
        printf("\n\nWelcome to your digital diary. Choose an option: \n");
        printf("1. Enter a new entry\n");
        printf("2. View previous entries\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("\nEnter your entry: ");
                getchar();
                fgets(entries[cnt], sizeof(entries[cnt]), stdin); // read input from user
                cnt++;
                break;
            
            case 2:
                printf("\nHere are your previous entries: \n");
                for(int i=0; i<cnt; i++) {
                    printf("%d. %s", i+1, entries[i]); // print all the entries
                }
                break;
            
            case 0:
                printf("\nGoodbye!\n");
                break;
                
            default:
                printf("\nInvalid option, please try again.\n");
        }
    }
    
    return 0;
}