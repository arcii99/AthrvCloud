//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>

int main(){
    char filename[20];
    printf("Enter the file name to scan: ");
    scanf("%s", filename);

    printf("Scanning file %s...\n", filename);

    FILE *file = fopen(filename, "r");
    if(file == NULL){
        printf("ERROR: File not found.\n");
        return 0;
    }

    printf("Analyzing file content...\n");

    char current_char;
    int virus_count = 0;

    while((current_char = fgetc(file)) != EOF){
        if(current_char == 'v' || current_char == 'V'){
            current_char = fgetc(file);
            if(current_char == 'i' || current_char == 'I'){
                current_char = fgetc(file);
                if(current_char == 'r' || current_char == 'R'){
                    current_char = fgetc(file);
                    if(current_char == 'u' || current_char == 'U'){
                        current_char = fgetc(file);
                        if(current_char == 's' || current_char == 'S'){
                            virus_count++;
                            printf("ERROR: Virus detected at position %ld\n", ftell(file));
                        }
                    }
                }
            }
        }
    }

    if(virus_count == 0){
        printf("File is safe.\n");
    }else{
        printf("%d virus(es) detected.\n", virus_count);
    }

    fclose(file);
    return 0;
}