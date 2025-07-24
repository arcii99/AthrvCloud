//FormAI DATASET v1.0 Category: Data recovery tool ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

int main() {
  int num_files;
  printf("Enter the number of files to recover data from: ");
  scanf("%d", &num_files);

  char** filenames = (char**)malloc(num_files * sizeof(char*));
  for(int i = 0; i < num_files; i++) {
    filenames[i] = (char*)malloc(sizeof(char) * 100);
    printf("Enter the name of file %d: ", i+1);
    scanf("%s", filenames[i]);
  }

  FILE* dest_file = fopen("recovered_data.txt", "w");

  for(int i = 0; i < num_files; i++) {
    FILE* src_file = fopen(filenames[i], "r");
    if(src_file == NULL) {
      printf("Error: Unable to open %s\n", filenames[i]);
      return 1;
    }

    printf("Recovering data from %s...\n", filenames[i]);

    char c;
    while((c = getc(src_file)) != EOF) {
      fprintf(dest_file, "%c", c);
    }

    fclose(src_file);
  }

  fclose(dest_file);

  printf("Data successfully recovered and written to recovered_data.txt\n");

  for(int i = 0; i < num_files; i++) {
    free(filenames[i]);
  }
  free(filenames);

  return 0;
}