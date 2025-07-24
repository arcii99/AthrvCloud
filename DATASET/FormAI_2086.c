//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_SAMPLES 10
#define CPU_USAGE "top -bn1 | grep \"Cpu(s)\" | \
    sed \"s/.*, *\([0-9.]*\)%* id.*/\1/\" | \
    awk '{print 100 - $1\"%\"}'"

int main() {
  int i, j;
  float cpu_usage[NUM_SAMPLES];
  FILE *fp;
  char output[1024];

  for (i = 0; i < NUM_SAMPLES; i++) {
    fp = popen(CPU_USAGE, "r");
    fgets(output, 1024, fp);
    pclose(fp);
    cpu_usage[i] = atof(output);
    usleep(1000000);
  }

  float avg_cpu_usage = 0.0;
  for (j = 0; j < NUM_SAMPLES; j++) {
    avg_cpu_usage += cpu_usage[j];
  }
  avg_cpu_usage /= NUM_SAMPLES;

  printf("Average CPU Usage: %.3f%%\n", avg_cpu_usage);

  return 0;
}