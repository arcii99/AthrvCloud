//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct song{
    char name[30];
    char artist[30];
    int year;
    int rating;
    struct song* next;
}song;

song *head = NULL, *tail = NULL;

int main(){
    int choice;

    do{
        printf("Welcome to the CyberPunk Music Library Management System.\n");
        printf("1. Add a new song\n");
        printf("2. Delete a song\n");
        printf("3. Display all songs\n");
        printf("4. Search for a song\n");
        printf("5. Sort songs by artist name\n");
        printf("6. Sort songs by year released\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_song();
                break;
            case 2:
                delete_song();
                break;
            case 3:
                display_songs();
                break;
            case 4:
                search_song();
                break;
            case 5:
                sort_by_artist();
                break;
            case 6:
                sort_by_year();
                break;
            case 7:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    
    }while(choice != 7);

    return 0;
}

void add_song(){
    song *new_song = (song*) malloc(sizeof(song));

    printf("Enter song name: ");
    scanf("%s", new_song->name);
    printf("Enter artist name: ");
    scanf("%s", new_song->artist);
    printf("Enter release year: ");
    scanf("%d", &new_song->year);
    printf("Enter rating (out of 10): ");
    scanf("%d", &new_song->rating);

    new_song->next = NULL;

    if(head == NULL){
        head = new_song;
        tail = new_song;
    }else{
        tail->next = new_song;
        tail = new_song;
    }

    printf("New song added successfully!\n");
}

void delete_song(){
    char name[30], artist[30];
    int flag = 0;   // to keep track if song was found or not
    
    if(head == NULL){
        printf("No songs in library!\n");
        return;
    }

    printf("Enter name of song to delete: ");
    scanf("%s", name);
    printf("Enter artist name: ");
    scanf("%s", artist);

    song *curr = head, *prev = NULL;

    while(curr != NULL){
        if(strcmp(curr->name, name) == 0 && strcmp(curr->artist, artist) == 0){
            flag = 1;
            if(curr == head){
                head = curr->next;
                free(curr);
            }else if(curr == tail){
                prev->next = NULL;
                tail = prev;
                free(curr);
            }else{
                prev->next = curr->next;
                free(curr);
            }
            printf("Song %s by %s deleted successfully!\n", name, artist);
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    if(flag == 0){
        printf("Song not found!\n");
    }
}

void display_songs(){
    if(head == NULL){
        printf("No songs in library!\n");
        return;
    }

    printf("Name\tArtist\tYear\tRating\n");
    printf("----\t------\t----\t------\n");

    song *curr = head;

    while(curr != NULL){
        printf("%s\t%s\t%d\t%d\n", curr->name, curr->artist, curr->year, curr->rating);
        curr = curr->next;
    }
}

void search_song(){
    char name[30];
    int flag = 0;
    
    if(head == NULL){
        printf("No songs in library!\n");
        return;
    }

    printf("Enter name of song to search: ");
    scanf("%s", name);

    song *curr = head;

    while(curr != NULL){
        if(strcmp(curr->name, name) == 0){
            flag = 1;
            printf("%s\t%s\t%d\t%d\n", curr->name, curr->artist, curr->year, curr->rating);
        }
        curr = curr->next;
    }

    if(flag == 0){
        printf("Song not found!\n");
    }
}

void sort_by_artist(){
    if(head == NULL){
        printf("No songs in library!\n");
        return;
    }

    song *p, *q;
    char temp[30];

    for(p = head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(strcmp(p->artist, q->artist) > 0){
                strcpy(temp, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, temp);
                strcpy(temp, p->artist);
                strcpy(p->artist, q->artist);
                strcpy(q->artist, temp);
                int t = p->year;
                p->year = q->year;
                q->year = t;
                t = p->rating;
                p->rating = q->rating;
                q->rating = t;
            }
        }
    }

    printf("Songs sorted by artist successfully!\n");
}

void sort_by_year(){
    if(head == NULL){
        printf("No songs in library!\n");
        return;
    }

    song *p, *q;
    char temp[30];

    for(p = head; p != NULL; p = p->next){
        for(q = p->next; q != NULL; q = q->next){
            if(p->year > q->year){
                strcpy(temp, p->name);
                strcpy(p->name, q->name);
                strcpy(q->name, temp);
                strcpy(temp, p->artist);
                strcpy(p->artist, q->artist);
                strcpy(q->artist, temp);
                int t = p->year;
                p->year = q->year;
                q->year = t;
                t = p->rating;
                p->rating = q->rating;
                q->rating = t;
            }
        }
    }

    printf("Songs sorted by year successfully!\n");
}