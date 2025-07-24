//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 256
#define MAX_FIELDS 20

typedef struct {
  char fields[MAX_FIELDS][MAX_FIELD_LEN];
  int num_fields;
} CsvRecord;

CsvRecord* parse_csv_line(char* line) {
  CsvRecord* rec = (CsvRecord*)malloc(sizeof(CsvRecord));
  rec->num_fields = 0;

  char* tok = strtok(line, ",");
  while(tok) {
    strncpy(rec->fields[rec->num_fields++], tok, MAX_FIELD_LEN);
    tok = strtok(NULL, ",");
  }

  return rec;
}

int main(int argc, char** argv) {
  FILE* fp = fopen("data.csv", "r");
  if(!fp) {
    printf("Failed to open CSV file.\n");
    return 1;
  }

  char line[MAX_LINE_LEN];
  while(fgets(line, MAX_LINE_LEN, fp)) {
    CsvRecord* rec = parse_csv_line(line);

    // Do something with the record here
    for(int i=0; i<rec->num_fields; i++) {
      printf("%s ", rec->fields[i]);
    }
    printf("\n");

    free(rec);
  }

  fclose(fp);
  return 0;
}