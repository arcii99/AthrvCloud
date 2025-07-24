//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Claude Shannon
#include <stdio.h>

typedef struct {
  int value;
  int offset;
} IndexEntry;

int main() {
  FILE *datafile = fopen("data.db", "rb");
  FILE *indexfile = fopen("index.dat", "wb");

  IndexEntry index[1000];
  int num_entries = 0;
  int offset = 0;

  while (!feof(datafile)) {
    int value;
    fread(&value, sizeof(int), 1, datafile);

    if (num_entries == 0 || value > index[num_entries-1].value) {
      index[num_entries].value = value;
      index[num_entries].offset = offset;
      num_entries++;
    }

    offset += sizeof(int);
  }

  fwrite(index, sizeof(IndexEntry), num_entries, indexfile);

  fclose(datafile);
  fclose(indexfile);

  return 0;
}