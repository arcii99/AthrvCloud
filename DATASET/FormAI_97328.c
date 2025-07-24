//FormAI DATASET v1.0 Category: Log analysis ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void print_header(FILE *output_file) {
  fprintf(output_file, "<tr>");
  fprintf(output_file, "<th>Date</th>");
  fprintf(output_file, "<th>Error Code</th>");
  fprintf(output_file, "<th>Message</th>");
  fprintf(output_file, "<th>File Name</th>");
  fprintf(output_file, "<th>Function Name</th>");
  fprintf(output_file, "<th>Line Number</th>");
  fprintf(output_file, "</tr>\n");
}

void print_log(FILE *output_file, char *line) {
  char *token;
  char *line_copy = strdup(line);

  fprintf(output_file, "<tr>");

  token = strtok(line_copy, " ");
  fprintf(output_file, "<td>%s</td>", token);  // date

  token = strtok(NULL, " ");
  fprintf(output_file, "<td>%s</td>", token);  // error code

  token = strtok(NULL, " ");
  fprintf(output_file, "<td>%s</td>", token);  // message

  token = strtok(NULL, " ");
  token = strtok(NULL, " ");
  fprintf(output_file, "<td>%s</td>", strtok(NULL, ":"));  // file name

  token = strtok(NULL, " ");
  fprintf(output_file, "<td>%s</td>", token);  // function name

  token = strtok(NULL, " ");
  token = strtok(NULL, " ");
  fprintf(output_file, "<td>%s</td>", token);  // line number

  fprintf(output_file, "</tr>\n");

  free(line_copy);
}

void parse_log(FILE *input_file, FILE *output_file) {
  char line[MAX_LINE_LENGTH];
  int first_line = 1;

  fprintf(output_file, "<table>\n");

  while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
    if (first_line) {  // ignore first line
      first_line = 0;
      continue;
    }
    print_log(output_file, line);
  }

  fprintf(output_file, "</table>\n");
}

int main(int argc, char *argv[]) {
  FILE *input_file;
  FILE *output_file;

  if (argc != 3) {
    printf("Usage: %s <input-file> <output-file>\n", argv[0]);
    return 1;
  }

  input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Error: cannot open input file '%s'\n", argv[1]);
    return 1;
  }

  output_file = fopen(argv[2], "w");
  if (output_file == NULL) {
    printf("Error: cannot open output file '%s'\n", argv[2]);
    fclose(input_file);
    return 1;
  }

  fprintf(output_file, "<html>\n");
  fprintf(output_file, "<head><title>Log Analysis</title></head>\n");
  fprintf(output_file, "<body>\n");

  fprintf(output_file, "<h1>Log Analysis</h1>\n");

  parse_log(input_file, output_file);

  fprintf(output_file, "</body>\n");
  fprintf(output_file, "</html>\n");

  fclose(input_file);
  fclose(output_file);

  return 0;
}