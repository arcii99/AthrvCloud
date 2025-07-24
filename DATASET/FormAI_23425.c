//FormAI DATASET v1.0 Category: Music Library Management System ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct MusicLibrary{
    char albumName[50];
    char artistName[50];
    char genre[50];
    int trackCount;
};

int main()
{
    int numAlbums;
    printf("Enter the number of albums in your music library: ");
    scanf("%d",&numAlbums);
    struct MusicLibrary *albumList = (struct MusicLibrary*) malloc(numAlbums*sizeof(struct MusicLibrary));
    int index=0;
    while(index<numAlbums)
    {
        printf("\nEnter the details of album %d: \n",index+1);
        printf("Album Name: ");
        scanf("%s",albumList[index].albumName);
        printf("Artist Name: ");
        scanf("%s",albumList[index].artistName);
        printf("Genre: ");
        scanf("%s",albumList[index].genre);
        printf("Track Count: ");
        scanf("%d",&albumList[index].trackCount);
        index++;
    }
    printf("\n\n Here is your Music Library: \n\n");
    printf("%-30s %-30s %-30s %s\n\n","ALBUM NAME","ARTIST","GENRE","TRACK COUNT");
    index=0;
    while(index<numAlbums)
    {
        printf("%-30s %-30s %-30s %d\n",albumList[index].albumName,albumList[index].artistName,albumList[index].genre,albumList[index].trackCount);
        index++;   
    }
    free(albumList);
    return 0; 
}