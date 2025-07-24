//FormAI DATASET v1.0 Category: Database simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ANIMALS 10

struct Animal {
  int id;
  char name[20];
  int age;
  char favorite_song[50];
  char favorite_dance[50];
};

struct AnimalDatabase {
  struct Animal animals[MAX_ANIMALS];
  int num_animals;
};

void initialize_database(struct AnimalDatabase *db) {
  db->num_animals = 0;
}

void add_animal(struct AnimalDatabase *db, struct Animal animal) {
  db->animals[db->num_animals] = animal;
  db->num_animals++;
}

void print_database(struct AnimalDatabase db) {
  printf("======= ANIMAL DATABASE =======\n");
  for (int i = 0; i < db.num_animals; i++) {
    struct Animal animal = db.animals[i];
    printf("ID: %d\n", animal.id);
    printf("Name: %s\n", animal.name);
    printf("Age: %d\n", animal.age);
    printf("Favorite Song: %s\n", animal.favorite_song);
    printf("Favorite Dance: %s\n", animal.favorite_dance);
    printf("\n");
  }
}

int main() {
  struct AnimalDatabase db;
  initialize_database(&db);

  struct Animal cat = {1, "Whiskers", 4, "I Will Survive", "The Feline Fling"};
  add_animal(&db, cat);

  struct Animal dog = {2, "Barkley", 2, "Who Let the Dogs Out", "The Waggy Tail"};
  add_animal(&db, dog);

  struct Animal bird = {3, "Tweetie", 1, "Fly Like an Eagle", "The Feathered Shuffle"};
  add_animal(&db, bird);

  print_database(db);
  
  return 0;
}