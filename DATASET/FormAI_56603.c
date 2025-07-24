//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTISTS  100
#define MAX_ALBUMS   1000
#define MAX_TRACKS   10000

struct artist {
   char name[50];
   char nationality[20];
};

struct album {
   char title[50];
   int release_year;
   struct artist *ptr_artist;
};

struct track {
   char title[50];
   int duration;
   struct artist *ptr_artist;
   struct album *ptr_album;
};

struct library {
   struct artist artists[MAX_ARTISTS];
   int n_artists;
   struct album albums[MAX_ALBUMS];
   int n_albums;
   struct track tracks[MAX_TRACKS];
   int n_tracks;
};

void add_artist(struct library *lib) {
   if (lib->n_artists >= MAX_ARTISTS) {
      printf("Sorry, cannot add more artists\n");
   } else {
      printf("Enter artist name: ");
      scanf("%49s", lib->artists[lib->n_artists].name);
      printf("Enter artist nationality: ");
      scanf("%19s", lib->artists[lib->n_artists].nationality);
      lib->n_artists++;
      printf("New artist added!\n");
   }
}

void add_album(struct library *lib) {
   if (lib->n_albums >= MAX_ALBUMS) {
      printf("Sorry, cannot add more albums\n");
   } else {
      printf("Enter album title: ");
      scanf("%49s", lib->albums[lib->n_albums].title);
      printf("Enter album release year: ");
      scanf("%d", &lib->albums[lib->n_albums].release_year);
      printf("Enter artist name for the album: ");
      char artist_name[50];
      scanf("%49s", artist_name);
      int found = 0;
      for (int i = 0; i < lib->n_artists; i++) {
         if (strcmp(artist_name, lib->artists[i].name) == 0) {
            lib->albums[lib->n_albums].ptr_artist = &lib->artists[i];
            found = 1;
            break;
         }
      }
      if (!found) {
         printf("Cannot find the artist\n");
         return;
      }
      lib->n_albums++;
      printf("New album added!\n");
   }
}

void add_track(struct library *lib) {
   if (lib->n_tracks >= MAX_TRACKS) {
      printf("Sorry, cannot add more tracks\n");
   } else {
      printf("Enter track title: ");
      scanf("%49s", lib->tracks[lib->n_tracks].title);
      printf("Enter track duration in seconds: ");
      scanf("%d", &lib->tracks[lib->n_tracks].duration);
      printf("Enter artist name for the track: ");
      char artist_name[50];
      scanf("%49s", artist_name);
      int found_artist = 0;
      for (int i = 0; i < lib->n_artists; i++) {
         if (strcmp(artist_name, lib->artists[i].name) == 0) {
            lib->tracks[lib->n_tracks].ptr_artist = &lib->artists[i];
            found_artist = 1;
            break;
         }
      }
      if (!found_artist) {
         printf("Cannot find the artist\n");
         return;
      }
      printf("Enter album title for the track: ");
      char album_title[50];
      scanf("%49s", album_title);
      int found_album = 0;
      for (int i = 0; i < lib->n_albums; i++) {
         if (strcmp(album_title, lib->albums[i].title) == 0) {
            lib->tracks[lib->n_tracks].ptr_album = &lib->albums[i];
            found_album = 1;
            break;
         }
      }
      if (!found_album) {
         printf("Cannot find the album\n");
         return;
      }
      lib->n_tracks++;
      printf("New track added!\n");
   }
}

void print_artists(struct library *lib) {
   for (int i = 0; i < lib->n_artists; i++) {
      printf("%s (%s)\n", lib->artists[i].name, lib->artists[i].nationality);
   }
}

void print_albums(struct library *lib) {
   for (int i = 0; i < lib->n_albums; i++) {
      printf("%s (%d) by %s (%s)\n", lib->albums[i].title, lib->albums[i].release_year,
             lib->albums[i].ptr_artist->name, lib->albums[i].ptr_artist->nationality);
   }
}

void print_tracks(struct library *lib) {
   for (int i = 0; i < lib->n_tracks; i++) {
      printf("%s (%d seconds) on %s by %s (%s)\n", lib->tracks[i].title, lib->tracks[i].duration,
             lib->tracks[i].ptr_album->title, lib->tracks[i].ptr_artist->name, 
             lib->tracks[i].ptr_artist->nationality);
   }
}

int main() {
   printf("Welcome to Cryptic Music Library Management System!\n\n");
   struct library lib = {0};
   while (1) {
      printf("Choose an option:\n");
      printf("1. Add a new artist\n");
      printf("2. Add a new album\n");
      printf("3. Add a new track\n");
      printf("4. Print all artists\n");
      printf("5. Print all albums\n");
      printf("6. Print all tracks\n");
      printf("7. Exit\n");
      int option;
      scanf("%d", &option);
      switch (option) {
         case 1:
            add_artist(&lib);
            break;
         case 2:
            add_album(&lib);
            break;
         case 3:
            add_track(&lib);
            break;
         case 4:
            print_artists(&lib);
            break;
         case 5:
            print_albums(&lib);
            break;
         case 6:
            print_tracks(&lib);
            break;
         case 7:
            printf("Thanks for using our system. Goodbye!\n");
            return 0;
         default:
            printf("Invalid option. Please try again.\n");
            break;         
      }
   }
   return 0;
}