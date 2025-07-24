//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include <stdio.h>
#include <string.h>

int main() {
    FILE *input_file, *output_file;
    char buffer[1000];
    
    input_file = fopen("input.html", "r");
    output_file = fopen("output.html", "w");

    if(input_file == NULL || output_file == NULL) {
        printf("Error opening files!");
        return 1;
    }

    while(fgets(buffer, 1000, input_file) != NULL) {
        // apply beautification modifications to buffer here
        // then write modified buffer to output file using fprintf()
        fprintf(output_file, "%s", buffer);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}