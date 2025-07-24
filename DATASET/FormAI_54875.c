//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

/* This program calculates the maximum number of activities that can be scheduled
 * given a set of activities with start and finish times.
 * It uses a Greedy Algorithm that selects activities with the earliest finish time first.
 */

typedef struct {
  int start, finish;
} activity;

int compare_activities(const void* a, const void* b) {
  int fa = ((activity*)a)->finish;
  int fb = ((activity*)b)->finish;

  return (fa > fb) - (fa < fb);
}

int select_activities(activity activities[], int num_activities) {
  int selected_activities[num_activities];
  int selected_count = 0, current_finish = 0;

  qsort(activities, num_activities, sizeof(activity), compare_activities);

  for (int i = 0; i < num_activities; i++) {
    if (activities[i].start >= current_finish) {
      selected_activities[selected_count++] = i;
      current_finish = activities[i].finish;
    }
  }

  // Print the selected activities
  printf("The selected activities are:\n");
  for (int i = 0; i < selected_count; i++) {
    printf("Activity %d: Start time: %d, Finish time: %d\n", selected_activities[i] + 1, activities[selected_activities[i]].start, activities[selected_activities[i]].finish);
  }

  return selected_count;
}

int main() {
  int num_activities = 0;
  printf("Enter the number of activities: ");
  scanf("%d", &num_activities);

  // Allocate memory for the activities
  activity* activities = malloc(num_activities * sizeof(activity));

  // Read in the activities
  printf("Enter the start and finish times for each activity:\n");
  for (int i = 0; i < num_activities; i++) {
    printf("Activity %d: ", i + 1);
    scanf("%d %d", &activities[i].start, &activities[i].finish);
  }

  int max_activities = select_activities(activities, num_activities);
  printf("The maximum number of activities that can be scheduled is: %d\n", max_activities);

  free(activities);
  return 0;
}