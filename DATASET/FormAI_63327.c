//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_SIZE 4096

// function to add a new string to the dictionary
int add_to_dict(char dictionary[][17], char *str, int dict_size) {
    strcpy(dictionary[dict_size], str);
    return dict_size + 1;
}

// function to find the index of a string in the dictionary
int find_in_dict(char dictionary[][17], char *str, int dict_size) {
    int i;
    for(i=0; i<dict_size; i++) {
        if(strcmp(dictionary[i], str)==0)
            return i;
    }
    return -1;
}

// function to compress a string using the LZW algorithm
void compress(char *str) {
    int i, j, dict_size=256, curr_code=256, len=strlen(str);
    char dictionary[MAX_DICT_SIZE][17], curr_prefix[17], curr_suffix[2];
    
    // initialize the dictionary with ASCII characters
    for(i=0; i<256; i++) {
        dictionary[i][0] = i;
        dictionary[i][1] = '\0';
    }
    
    // compress the string
    curr_prefix[0] = str[0];
    curr_prefix[1] = '\0';
    for(i=1; i<len; i++) {
        curr_suffix[0] = str[i];
        curr_suffix[1] = '\0';
        char temp[17] = "";
        strcat(temp, curr_prefix);
        strcat(temp, curr_suffix);
        if(find_in_dict(dictionary, temp, dict_size)!=-1) {
            strcpy(curr_prefix, temp);
        } else {
            printf("%d ", find_in_dict(dictionary, curr_prefix, dict_size-1));
            dict_size = add_to_dict(dictionary, temp, dict_size);
            curr_prefix[0] = curr_suffix[0];
            curr_prefix[1] = '\0';
        }
    }
    printf("%d\n", find_in_dict(dictionary, curr_prefix, dict_size-1));
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    scanf("%[^\n]%*c", str);
    printf("Compressed string:\n");
    compress(str);
    return 0;
}