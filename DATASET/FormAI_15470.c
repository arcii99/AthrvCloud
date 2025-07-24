//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: distributed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct access_point {
  char *ssid;
  int signal_strength;
};

struct access_point *parse_access_points(char *access_points_array[], int size) {
  struct access_point *access_points = malloc(size * sizeof(struct access_point));

  for(int i=0; i<size; i++) {
    char *ssid = strtok(access_points_array[i], ",");
    int signal_strength = atoi(strtok(NULL, ","));
    struct access_point ap = { ssid, signal_strength };
    access_points[i] = ap;
  }

  return access_points;
}

void average_signal_strength(struct access_point access_points[], int size, float *avg_signal_strength_ptr) {
  int sum_signal_strengths = 0;

  for(int i=0; i<size; i++) {
    sum_signal_strengths += access_points[i].signal_strength;
  }

  *avg_signal_strength_ptr = (float) sum_signal_strengths / size;
}

int main() {
  char *access_points_array[] = { "SSID1,80", "SSID2,70", "SSID3,90" };
  int size = sizeof(access_points_array) / sizeof(char *);

  struct access_point *access_points = parse_access_points(access_points_array, size);

  float avg_signal_strength;
  average_signal_strength(access_points, size, &avg_signal_strength);

  printf("Average signal strength: %.2f\n", avg_signal_strength);

  free(access_points);
  
  return 0;
}