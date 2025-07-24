//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* JSON object structure */
typedef struct {
    char *name;
    char *value;
} json_object;

/* JSON parser function */
void parse_json(char *json_string, json_object **objects, int *num_objects) {
    int i, j, k, l, len;
    int object_count = 0;
    char *token;
    char *key;
    char *value;
    char *str_start;
    char *str_end;
    char *sub_string;
    char *temp_string;
    
    /* Allocate memory for objects array */
    *objects = malloc(sizeof(json_object));
    if (*objects == NULL) {
        printf("ERROR: Failed to allocate memory for objects array.\n");
        exit(EXIT_FAILURE);
    }
    
    /* Get length of JSON string */
    len = strlen(json_string);
    
    /* Loop through JSON string */
    for (i = 0; i < len; i++) {
        /* Check for beginning of object */
        if (json_string[i] == '{') {
            /* Get substring containing object */
            str_start = json_string + i;
            str_end = strchr(str_start, '}');
            if (str_end == NULL) {
                printf("ERROR: Invalid JSON.\n");
                exit(EXIT_FAILURE);
            }
            sub_string = malloc(str_end - str_start + 2);
            if (sub_string == NULL) {
                printf("ERROR: Failed to allocate memory for substring.\n");
                exit(EXIT_FAILURE);
            }
            strncpy(sub_string, str_start, str_end - str_start + 1);
            sub_string[str_end - str_start + 1] = '\0';
            
            /* Allocate memory for object name and value */
            key = malloc(strlen(sub_string) + 1);
            if (key == NULL) {
                printf("ERROR: Failed to allocate memory for key.\n");
                exit(EXIT_FAILURE);
            }
            value = malloc(strlen(sub_string) + 1);
            if (value == NULL) {
                printf("ERROR: Failed to allocate memory for value.\n");
                exit(EXIT_FAILURE);
            }
            
            /* Loop through object */
            j = 0;
            while (sub_string[j] != '}') {
                /* Get key */
                str_start = sub_string + j;
                str_end = strchr(str_start, ':');
                if (str_end == NULL) {
                    printf("ERROR: Invalid JSON.\n");
                    exit(EXIT_FAILURE);
                }
                sub_string[str_end - sub_string] = '\0';
                strcpy(key, str_start);
                for (k = strlen(key) - 1; k >= 0; k--) {
                    if (isspace(key[k])) {
                        key[k] = '\0';
                    } else {
                        break;
                    }
                }
                j = str_end - sub_string + 1;
                
                /* Get value */
                if (sub_string[j] == '{') {
                    /* Value is an object */
                    l = j;
                    temp_string = sub_string + j;
                    while (*temp_string != '}') {
                        if (*temp_string == '{') {
                            l++;
                        } else if (*temp_string == '}') {
                            l--;
                        }
                        temp_string++;
                    }
                    temp_string++;
                    strncpy(value, sub_string + j, temp_string - (sub_string + j));
                    value[temp_string - (sub_string + j)] = '\0';
                    j = temp_string - sub_string;
                } else {
                    /* Value is a string or number */
                    str_start = sub_string + j;
                    if (sub_string[j] == '"') {
                        /* Value is a string */
                        str_start++;
                        str_end = strchr(str_start, '"');
                        if (str_end == NULL) {
                            printf("ERROR: Invalid JSON.\n");
                            exit(EXIT_FAILURE);
                        }
                        sub_string[str_end - sub_string] = '\0';
                        strcpy(value, str_start);
                        j = str_end - sub_string + 1;
                    } else {
                        /* Value is a number */
                        str_end = str_start;
                        while (*str_end != ',' && *str_end != '}') {
                            str_end++;
                        }
                        strncpy(value, str_start, str_end - str_start);
                        value[str_end - str_start] = '\0';
                        j = str_end - sub_string;
                    }
                }
                
                /* Add object to objects array */
                (*objects)[object_count].name = malloc(strlen(key) + 1);
                if ((*objects)[object_count].name == NULL) {
                    printf("ERROR: Failed to allocate memory for name.\n");
                    exit(EXIT_FAILURE);
                }
                (*objects)[object_count].value = malloc(strlen(value) + 1);
                if ((*objects)[object_count].value == NULL) {
                    printf("ERROR: Failed to allocate memory for value.\n");
                    exit(EXIT_FAILURE);
                }
                strcpy((*objects)[object_count].name, key);
                strcpy((*objects)[object_count].value, value);
                object_count++;
                
                /* Reallocate memory for objects array */
                *objects = realloc(*objects, (object_count + 1) * sizeof(json_object));
                if (*objects == NULL) {
                    printf("ERROR: Failed to reallocate memory for objects array.\n");
                    exit(EXIT_FAILURE);
                }
            }
            
            /* Free memory for key, value, and substring */
            free(key);
            free(value);
            free(sub_string);
            
            /* Update i to skip over processed object */
            i += str_end - str_start;
        }
    }
    
    /* Set num_objects to number of objects found */
    *num_objects = object_count;
}

int main() {
    char json_str[] = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    json_object *objects;
    int num_objects = 0;
    
    /* Parse JSON string */
    parse_json(json_str, &objects, &num_objects);
    
    /* Print object values */
    printf("Object 1:\nName: %s\nValue: %s\n", objects[0].name, objects[0].value);
    printf("Object 2:\nName: %s\nValue: %s\n", objects[1].name, objects[1].value);
    printf("Object 3:\nName: %s\nValue: %s\n", objects[2].name, objects[2].value);
    
    /* Free memory */
    free(objects[0].name);
    free(objects[0].value);
    free(objects[1].name);
    free(objects[1].value);
    free(objects[2].name);
    free(objects[2].value);
    free(objects);
    
    return 0;
}