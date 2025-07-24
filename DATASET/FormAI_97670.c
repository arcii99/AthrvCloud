//FormAI DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song{
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

int main(){
    int choice, i, n, flag = 0;
    struct song *library = NULL;

    printf("Enter number of songs: ");
    scanf("%d", &n);

    library = (struct song*)malloc(n * sizeof(struct song));

    for(i = 0; i < n; i++){
        printf("Enter details of song %d:\n", i+1);
        printf("Title: ");
        fflush(stdin);
        gets(library[i].title);
        printf("Artist: ");
        gets(library[i].artist);
        printf("Album: ");
        gets(library[i].album);
        printf("Year: ");
        scanf("%d", &library[i].year);
    }

    while(1){
        printf("\n\n1. Display all songs\n");
        printf("2. Search a song\n");
        printf("3. Add a new song\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: // Display all songs
                printf("\nSONG LIBRARY\n");
                printf("--------------------------------------------------------------------------------\n");
                printf("| %-30s | %-20s | %-20s | %-4s |\n", "Title", "Artist", "Album", "Year");
                printf("--------------------------------------------------------------------------------\n");
                for(i = 0; i < n; i++){
                    printf("| %-30s | %-20s | %-20s | %-4d |\n", library[i].title, library[i].artist, library[i].album, library[i].year);
                }
                printf("--------------------------------------------------------------------------------\n");
                break;

            case 2: // Search a song
                char search_title[50];
                printf("Enter the title of the song you want to search: ");
                fflush(stdin);
                gets(search_title);
                printf("\nSEARCH RESULT\n");
                printf("--------------------------------------------------------------------------------\n");
                printf("| %-30s | %-20s | %-20s | %-4s |\n", "Title", "Artist", "Album", "Year");
                printf("--------------------------------------------------------------------------------\n");
                for(i = 0; i < n; i++){
                    if(strcmp(search_title, library[i].title) == 0){
                        printf("| %-30s | %-20s | %-20s | %-4d |\n", library[i].title, library[i].artist, library[i].album, library[i].year);
                        flag = 1;
                    }
                }
                printf("--------------------------------------------------------------------------------\n");
                if(flag == 0){
                    printf("\nSorry, no song found with the title %s\n", search_title);
                }
                flag = 0;
                break;

            case 3: // Add a new song
                n++;
                library = (struct song*)realloc(library, n * sizeof(struct song));
                printf("\nEnter details of new song:\n");
                printf("Title: ");
                fflush(stdin);
                gets(library[n-1].title);
                printf("Artist: ");
                gets(library[n-1].artist);
                printf("Album: ");
                gets(library[n-1].album);
                printf("Year: ");
                scanf("%d", &library[n-1].year);
                printf("\nSong added successfully!\n");
                break;

            case 4: // Quit
                free(library);
                printf("\nThank you for using the program.\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}