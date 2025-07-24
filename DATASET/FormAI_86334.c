//FormAI DATASET v1.0 Category: HTML beautifier ; Style: curious
#include <stdio.h>
#include <stdlib.h>

//Function to beautify the HTML code
void beautify_html(char* input_file, char* output_file) {
    FILE *in_fp, *out_fp;
    in_fp = fopen(input_file, "r");
    out_fp = fopen(output_file, "w");
    int indent_level = 0;
    int i;
    
    //Loop through each line of the input file
    char line[1000];
    while (fgets(line, sizeof(line), in_fp)) {
        //Check for opening tags
        if (strstr(line, "<")) {
            for (i = 0; i < indent_level; i++) {
                fprintf(out_fp, "\t");
            }
            fprintf(out_fp, "%s", line);
            indent_level++;
        }
        //Check for closing tags
        else if (strstr(line, ">")) {
            indent_level--;
            for (i = 0; i < indent_level; i++) {
                fprintf(out_fp, "\t");
            }
            fprintf(out_fp, "%s", line);
        }
        //If line doesn't contain tags
        else {
            for (i = 0; i < indent_level; i++) {
                fprintf(out_fp, "\t");
            }
            fprintf(out_fp, "%s", line);
        }
    }
    fclose(in_fp);
    fclose(out_fp);
}

int main() {
    char* input_file = "input.html";
    char* output_file = "output.html";
    beautify_html(input_file, output_file);
    return 0;
}