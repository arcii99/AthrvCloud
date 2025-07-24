//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100

char input[MAX_LINES][MAX_LENGTH];
char output[MAX_LINES][MAX_LENGTH];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *beautifyCode(void *tid) {
  int start = *((int*) tid);
  int end = start + (MAX_LINES / 4);

  for (int i = start; i < end; i++) {
    if (strstr(input[i], "<html>") != NULL || strstr(input[i], "<HTML>") != NULL) {
      strcpy(output[i], "<html>\n");
      pthread_mutex_lock(&lock);
    }

    else if (strstr(input[i], "<body>") != NULL || strstr(input[i], "<BODY>") != NULL) {
      strcpy(output[i], "  <body>\n");
      pthread_mutex_lock(&lock);
    }

    else if (strstr(input[i], "<head>") != NULL || strstr(input[i], "<HEAD>") != NULL) {
      strcpy(output[i], "  <head>\n");
      pthread_mutex_lock(&lock);
    }

    else if (strstr(input[i], "</html>") != NULL || strstr(input[i], "</HTML>") != NULL) {
      strcpy(output[i], "</html>\n");
      pthread_mutex_unlock(&lock);
    }

    else if (strstr(input[i], "</body>") != NULL || strstr(input[i], "</BODY>") != NULL) {
      strcpy(output[i], "  </body>\n");
      pthread_mutex_unlock(&lock);
    }

    else if (strstr(input[i], "</head>") != NULL || strstr(input[i], "</HEAD>") != NULL) {
      strcpy(output[i], "  </head>\n");
      pthread_mutex_unlock(&lock);
    }

    else {
      strcpy(output[i], input[i]);
    }
  }

  pthread_exit(NULL);
}

int main() {
  char filename[100];
  printf("Enter the name of file to be beautified: ");
  scanf("%s", filename);

  FILE *file_pointer = fopen(filename, "r");
  if (file_pointer == NULL) {
    printf("Unable to open the file.\n");
    exit(1);
  }

  int i = 0;
  while (fgets(input[i], MAX_LENGTH, file_pointer)) {
    i++;
  }

  fclose(file_pointer);

  pthread_t threads[4];
  int thread_id[4];

  for (int j = 0; j < 4; j++) {
    thread_id[j] = j * (MAX_LINES / 4);
    pthread_create(&threads[j], NULL, beautifyCode, &thread_id[j]);
  }

  for (int j = 0; j < 4; j++) {
    pthread_join(threads[j], NULL);
  }

  FILE *output_file_pointer = fopen("output.html", "w+");
  if (output_file_pointer == NULL) {
    printf("Unable to create the output file.\n");
    exit(1);
  }

  for (int j = 0; j < i; j++) {
    fprintf(output_file_pointer, "%s", output[j]);
  }

  fclose(output_file_pointer);

  return 0;
}