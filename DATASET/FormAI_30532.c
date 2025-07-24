//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Exercise {
  char name[50];
  int reps;
  int sets;
  int weight;

  struct Exercise* next;
};

struct date {
  int day;
  int month;
  int year;
  struct Exercise* exercise; 
};

struct Calendar {
  struct date dates[365];
};

struct FitnessTracker {
  char name[50];
  int age;
  float weight;
  struct Calendar calendar;
};

void addExercise(struct FitnessTracker* tracker, struct date* d) {
  printf("Enter the exercise name: ");
  scanf("%s", (*d).exercise->name);

  printf("Enter the number of sets: ");
  scanf("%d", &(*d).exercise->sets);

  printf("Enter the number of reps: ");
  scanf("%d", &(*d).exercise->reps);

  printf("Enter the weight lifted: ");
  scanf("%d", &(*d).exercise->weight);
}

void viewExercise(struct FitnessTracker* tracker, struct date* d) {
  printf("Exercise: %s\n", (*d).exercise->name);
  printf("Sets: %d\n", (*d).exercise->sets);
  printf("Reps: %d\n", (*d).exercise->reps);
  printf("Weight lifted: %d\n", (*d).exercise->weight);
}

void viewDate(struct FitnessTracker* tracker) {
  int day, month, year;
  printf("Enter the date to view (dd mm yyyy): ");
  scanf("%d %d %d", &day, &month, &year);
  struct date d = tracker->calendar.dates[((year - 1) * 365) + ((month - 1) * 31) + day - 1];
  viewExercise(tracker, &d);
}

void addDate(struct FitnessTracker* tracker) {
  int day, month, year;
  printf("Enter the date (dd mm yyyy): ");
  scanf("%d %d %d", &day, &month, &year);
  struct date* d = &tracker->calendar.dates[((year - 1) * 365) + ((month - 1) * 31) + day - 1];
  (*d).exercise = malloc(sizeof(struct Exercise));
  addExercise(tracker, d);
}

int main() {
  struct FitnessTracker tracker;
  printf("Enter your name: ");
  scanf("%s", tracker.name);

  printf("Enter your age: ");
  scanf("%d", &tracker.age);

  printf("Enter your weight: ");
  scanf("%f", &tracker.weight);

  while (1) {
    int choice;

    printf("\n\n1. Add exercise\n");
    printf("2. View exercise\n");
    printf("3. Add date\n");
    printf("4. View date\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
      addDate(&tracker);
    }

    else if (choice == 2) {
      viewDate(&tracker);
    }

    else if (choice == 3) {
      addDate(&tracker);
    }

    else if (choice == 4) {
      viewDate(&tracker);
    }

    else if (choice == 5) {
      exit(0);
    }

    else {
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}