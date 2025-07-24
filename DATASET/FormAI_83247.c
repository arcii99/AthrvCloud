//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SECTION_SIZE 1024
#define MAX_FIELD_SIZE 1024

typedef struct
{
    char *key;
    char *value;
} field;

typedef struct
{
    char *name;
    int num_fields;
    field *fields;
} section;

int parse_file(char *filename, section **sections);
char* get_section_name(char *line);
char* get_field_key(char *line);
char* get_field_value(char *line);
void print_sections(section **sections);
void free_sections(section **sections);

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Usage: metadata_extractor <filename>\n");
        exit(1);
    }

    section **sections;

    int num_sections = parse_file(argv[1], &sections);

    printf("Sections:\n");

    print_sections(sections);

    free_sections(sections);

    return 0;
}

int parse_file(char *filename, section **sections)
{
    FILE *file;

    if((file = fopen(filename, "r")) == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    int num_sections = 0;
    char line[MAX_SECTION_SIZE];

    *sections = malloc(sizeof(section));

    section *current_section = NULL;

    while(fgets(line, MAX_SECTION_SIZE, file) != NULL)
    {
        char *section_name = get_section_name(line);

        if(section_name != NULL)
        {
            if(current_section != NULL)
            {
                num_sections++;
                *sections = realloc(*sections, sizeof(section) * (num_sections + 1));
            }

            current_section = &((*sections)[num_sections]);
            current_section->name = section_name;
            current_section->num_fields = 0;
            current_section->fields = NULL;
        }
        else if(current_section != NULL)
        {
            char *field_key = get_field_key(line);
            char *field_value = get_field_value(line);

            if(field_key != NULL && field_value != NULL)
            {
                current_section->num_fields++;
                current_section->fields = realloc(current_section->fields, sizeof(field) * current_section->num_fields);

                field *current_field = &(current_section->fields[current_section->num_fields - 1]);
                current_field->key = field_key;
                current_field->value = field_value;
            }
        }
    }

    fclose(file);

    return num_sections;
}

char* get_section_name(char *line)
{
    if(line[0] == '[')
    {
        char *section_name = malloc(strlen(line) - 2);
        strncpy(section_name, line + 1, strlen(line) - 3);
        section_name[strlen(line) - 3] = '\0';
        return section_name;
    }

    return NULL;
}

char* get_field_key(char *line)
{
    char *key = malloc(MAX_FIELD_SIZE);

    if(sscanf(line, "%[a-zA-Z0-9_]=", key) == 1)
        return key;

    free(key);

    return NULL;
}

char* get_field_value(char *line)
{
    char *value = malloc(MAX_FIELD_SIZE);

    if(sscanf(line, "%*[^=]=%[^\n]", value) == 1)
        return value;

    free(value);

    return NULL;
}

void print_sections(section **sections)
{
    for(int i=0; (*sections)[i].name != NULL; i++)
    {
        printf("[%s]\n", (*sections)[i].name);

        for(int j=0; j<(*sections)[i].num_fields; j++)
        {
            printf("%s=%s\n", (*sections)[i].fields[j].key, (*sections)[i].fields[j].value);
        }

        printf("\n");
    }
}

void free_sections(section **sections)
{
    for(int i=0; (*sections)[i].name != NULL; i++)
    {
        for(int j=0; j<(*sections)[i].num_fields; j++)
        {
            free((*sections)[i].fields[j].key);
            free((*sections)[i].fields[j].value);
        }

        free((*sections)[i].name);
        free((*sections)[i].fields);
    }

    free(*sections);
}