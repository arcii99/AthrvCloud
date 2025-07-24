//FormAI DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the C Music Library Management System! Let's rock and roll!\n");

    int num_songs = 0;
    printf("How many songs do you want to add to your library? ");
    scanf("%d", &num_songs);

    char song_list[num_songs][100];
    printf("Great! Let's start adding songs to your library.\n");

    for (int i = 0; i < num_songs; i++) {
        printf("Enter the name of song #%d: ", i+1);
        scanf("%s", song_list[i]);
        printf("'%s' has been added to your library!\n", song_list[i]);
    }

    printf("Your current music library:\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%d. %s\n", i+1, song_list[i]);
    }

    printf("Would you like to remove a song from your library? (Y/N) ");
    char answer;
    scanf(" %c", &answer);

    if (answer == 'Y' || answer == 'y') {
        int index_to_remove;
        printf("Which song would you like to remove? Enter the corresponding number: ");
        scanf("%d", &index_to_remove);
        for (int i = index_to_remove - 1; i < num_songs - 1; i++) {
            // shift all elements to the left to remove the selected song from the list
            strcpy(song_list[i], song_list[i+1]);
        }
        num_songs--;
        printf("'%s' has been successfully removed from your library!\n", song_list[index_to_remove-1]);

        printf("Your updated music library:\n");
        for (int i = 0; i < num_songs; i++) {
            printf("%d. %s\n", i+1, song_list[i]);
        }
    } else {
        printf("Okay, thanks for using the C Music Library Management System. See you later, alligator!\n");
    }

    return 0;
}