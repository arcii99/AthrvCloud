//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void beautify_html(char *input_filename, char *output_filename){
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w+");
    
    if(!input_file){
        printf("Error opening input file!\n");
        return;
    }
    
    if(!output_file){
        printf("Error opening output file!\n");
        return;
    }
    
    char last_char_read = '\0';
    char current_char_read = fgetc(input_file);
    
    while(current_char_read != EOF){
        
        if(last_char_read == '<' && current_char_read != '/'){
            fprintf(output_file, "\n"); // Insert a new line before a tag.
            fprintf(output_file, "  "); // Indentation before the tag
        }
        
        fprintf(output_file, "%c", current_char_read); // Write the actual character
        
        if(current_char_read == '>'){
            fprintf(output_file, "\n"); // Insert a new line after a tag
            if(last_char_read == '<' || last_char_read == '/'){
                fprintf(output_file, "  "); // Additional indentation after opening or closing tag
            }
        }
        
        last_char_read = current_char_read;
        current_char_read = fgetc(input_file);
    }
    
    fclose(input_file);
    fclose(output_file);
}

int main(){
    beautify_html("input.html", "output.html");
    return 0;
}