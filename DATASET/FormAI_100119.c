//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
 
struct MusicLibrary{
    int songID;
    char songName[30];
    char artistName[30];
    char albumName[30];
    int year;
    int genre;
} music[100];
 
int numberOfSongs = 0;
 
int main() {
    int choice;
   
    do{
        printf("\n--- MUSIC LIBRARY MANAGEMENT SYSTEM ---\n");
        printf("1. Add a new song\n");
        printf("2. Display all songs\n");
        printf("3. Search for a song\n");
        printf("4. Delete a song\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
       
        switch(choice){
            case 1:
                addSong();
                break;
   
            case 2:
                displayAll();
                break;
               
            case 3:
                searchSong();
                break;
                   
            case 4:
                deleteSong();
                break;
                   
            case 5:{
                printf("\nThank you for using the Music Library Management System!\n");
                exit(0);
            }
            default:{
                printf("\nInvalid choice! Please Try again.\n");
            }
        }
    }while(choice != 5);
   
    return 0;
}
 
void addSong(){
    printf("\nEnter the Song ID: ");
    scanf("%d", &music[numberOfSongs].songID);
 
    printf("Enter the Song Name: ");
    scanf("%s", &music[numberOfSongs].songName);
 
    printf("Enter the Artist Name: ");
    scanf("%s", &music[numberOfSongs].artistName);
 
    printf("Enter the Album Name: ");
    scanf("%s", &music[numberOfSongs].albumName);
 
    printf("Enter the Year: ");
    scanf("%d", &music[numberOfSongs].year);
 
    printf("Enter the Genre (1.Rock, 2.Pop, 3.Jazz, 4.Classical): ");
    scanf("%d", &music[numberOfSongs].genre);
   
    printf("\nSong successfully added to Music Library!\n");
   
    numberOfSongs++;
}
 
void displayAll(){
    printf("\n--- DISPLAYING ALL SONGS IN THE MUSIC LIBRARY ---\n");
    printf("%-10s %-30s %-30s %-30s %-10s %-10s\n", "SONG ID", "SONG NAME", "ARTIST NAME", "ALBUM NAME", "YEAR", "GENRE");
   
    for(int i=0; i<numberOfSongs; i++){
        printf("%-10d %-30s %-30s %-30s %-10d %-10d\n", music[i].songID, music[i].songName, music[i].artistName, music[i].albumName, music[i].year, music[i].genre);
    }
}
 
void searchSong(){
    int searchID;
    int found = 0;
   
    printf("\nEnter Song ID to Search: ");
    scanf("%d", &searchID);
   
    for(int i=0; i<numberOfSongs; i++){
        if(music[i].songID == searchID){
            printf("%-10s %-30s %-30s %-30s %-10s %-10s\n", "SONG ID", "SONG NAME", "ARTIST NAME", "ALBUM NAME", "YEAR", "GENRE");
            printf("%-10d %-30s %-30s %-30s %-10d %-10d\n", music[i].songID, music[i].songName, music[i].artistName, music[i].albumName, music[i].year, music[i].genre);
            found = 1;
            break;
        }
    }
   
    if(found == 0){
        printf("\nSong not found in Music Library.\n");
    }
}
 
void deleteSong(){
    int deleteID;
    int found = 0;
   
    printf("\nEnter Song ID to Delete: ");
    scanf("%d", &deleteID);
   
    for(int i=0; i<numberOfSongs; i++){
        if(music[i].songID == deleteID){
            found = 1;
           
            for(int j=i; j<numberOfSongs-1; j++){
                music[j].songID = music[j+1].songID;
                strcpy(music[j].songName, music[j+1].songName);
                strcpy(music[j].artistName, music[j+1].artistName);
                strcpy(music[j].albumName, music[j+1].albumName);
                music[j].year = music[j+1].year;
                music[j].genre = music[j+1].genre;
            }
           
            numberOfSongs--;
            break;
        }
    }
   
    if(found == 1){
        printf("\nSong successfully deleted from Music Library!\n");
    }
    else{
        printf("\nSong not found in Music Library.\n");
    }
}