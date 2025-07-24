//FormAI DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

void beautify(char *filename) {
  FILE *fp, *out;
  char c;
  int indent = 0;

  fp = fopen(filename, "r");
  if (!fp) {
    printf("Unable to open file\n");
    return;
  }

  out = fopen("beautified.html", "w");
  if (!out) {
    printf("Unable to create file\n");
    fclose(fp);
    return;
  }

  while ((c = fgetc(fp)) != EOF) {
    if (c == '<') {
      fprintf(out, "%c", c);
      if ((c = fgetc(fp)) != EOF && c == '/') {
        indent -= 2;
        fprintf(out, "\n");
        int i;
        for (i = 0; i < indent; i++) {
          fprintf(out, " ");
        }
      } else {
        indent += 2;
        fprintf(out, "\n");
        int i;
        for (i = 0; i < indent; i++) {
          fprintf(out, " ");
        }
        fprintf(out, "%c", c);
      }
    } else if (c == '>') {
      fprintf(out, "%c\n", c);
    } else {
      fprintf(out, "%c", c);
    }
  }

  fclose(fp);
  fclose(out);
}

int main() {
  beautify("index.html");
  return 0;
}