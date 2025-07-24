//FormAI DATASET v1.0 Category: Data mining ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_RECORDS 10000
#define NUM_OF_ATTRIBUTES 13

struct Record {
  int id;
  int age;
  char gender[10];
  char occupation[20];
  int income;
  char hometown[25];
  int num_of_friends;
  int num_of_likes;
  int num_of_shares;
  int num_of_comments;
  int num_of_views;
  int num_of_followers;
  int num_of_messages;
};

int main() {
  struct Record records[TOTAL_RECORDS];

  // Generating random records
  for (int i = 0; i < TOTAL_RECORDS; i++) {
    records[i].id = i + 1;
    records[i].age = rand() % 50 + 18;
    if (rand() % 2 == 0) {
      sprintf(records[i].gender, "Male");
    } else {
      sprintf(records[i].gender, "Female");
    }
    sprintf(records[i].occupation, "Occupation %d", rand() % 20 + 1);
    records[i].income = rand() % 100000 + 20000;
    sprintf(records[i].hometown, "City %d", rand() % 50 + 1);
    records[i].num_of_friends = rand() % 1000 + 50;
    records[i].num_of_likes = rand() % 1000 + 50;
    records[i].num_of_shares = rand() % 100 + 10;
    records[i].num_of_comments = rand() % 100 + 10;
    records[i].num_of_views = rand() % 10000 + 1000;
    records[i].num_of_followers = rand() % 500 + 50;
    records[i].num_of_messages = rand() % 100 + 10;
  }

  // Age Distribution
  int age_distribution[50] = {0};
  for (int i = 0; i < TOTAL_RECORDS; i++) {
    age_distribution[records[i].age - 18]++;
  }
  printf("\nAge Distribution:\n");
  for (int i = 0; i < 50; i++) {
    printf("Age %d: %d\n", i + 18, age_distribution[i]);
  }

  // Occupation Distribution
  int occupation_distribution[20] = {0};
  for (int i = 0; i < TOTAL_RECORDS; i++) {
    for (int j = 0; j < 20; j++) {
      if (strcmp(records[i].occupation, "Occupation %d", j + 1) == 0) {
        occupation_distribution[j]++;
        break;
      }
    }
  }
  printf("\nOccupation Distribution:\n");
  for (int i = 0; i < 20; i++) {
    printf("%s: %d\n", "Occupation %d", i + 1, occupation_distribution[i]);
  }

  // Gender Distribution
  int male_count = 0, female_count = 0;
  for (int i = 0; i < TOTAL_RECORDS; i++) {
    if (strcmp(records[i].gender, "Male") == 0) {
      male_count++;
    } else {
      female_count++;
    }
  }
  printf("\nGender Distribution:\n");
  printf("Male: %d\n", male_count);
  printf("Female: %d\n", female_count);

  // Income Distribution
  int income_distribution[10] = {0};
  for (int i = 0; i < TOTAL_RECORDS; i++) {
    income_distribution[records[i].income / 10000 - 2]++;
  }
  printf("\nIncome Distribution:\n");
  for (int i = 0; i < 10; i++) {
    printf("$%d - $%d: %d\n", (i + 2) * 10000, (i + 3) * 10000 - 1, income_distribution[i]);
  }

  // Hometown Distribution
  int hometown_distribution[50] = {0};
  for (int i = 0; i < TOTAL_RECORDS; i++) {
    for (int j = 0; j < 50; j++) {
      if (strcmp(records[i].hometown, "City %d", j + 1) == 0) {
        hometown_distribution[j]++;
        break;
      }
    }
  }
  printf("\nHometown Distribution:\n");
  for (int i = 0; i < 50; i++) {
    printf("%s: %d\n", "City %d", i + 1, hometown_distribution[i]);
  }

  // Friends-Likes Ratio
  int total_friends = 0, total_likes = 0;
  for (int i = 0; i < TOTAL_RECORDS; i++) {
    total_friends += records[i].num_of_friends;
    total_likes += records[i].num_of_likes;
  }
  float ratio = (float)total_likes / total_friends;
  printf("\nFriends-Likes Ratio:\n");
  printf("%.2f\n", ratio);

  return 0;
}