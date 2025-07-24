//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the prime number to be used as the hash function
#define PRIME 31

// Define the maximum length of a virus signature
#define MAX_SIG_LEN 20

// Define the maximum number of virus signatures to be stored in the database
#define MAX_SIG_NUM 10000

// Define the structure of a virus signature
typedef struct {
    char sig[MAX_SIG_LEN];
} virus_sig;

// Define the structure of the virus database
typedef struct {
    virus_sig sigs[MAX_SIG_NUM];
    int num_sigs;
} virus_db;

// Define the hash function
int hash(char *str) {
    int hash_val = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        hash_val = (hash_val * PRIME + (int)str[i]) % MAX_SIG_NUM;
    }
    return hash_val;
}

// Define the function to add a virus signature to the database
void add_signature(virus_db *db, char *sig) {
    if (db->num_sigs < MAX_SIG_NUM) {
        int index = hash(sig);
        strcpy(db->sigs[index].sig, sig);
        db->num_sigs++;
    }
}

// Define the function to check a file for virus signatures
void check_file(virus_db *db, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File %s not found.\n", filename);
        return;
    }
    char line[MAX_SIG_LEN];
    while (fgets(line, MAX_SIG_LEN, fp)) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        int index = hash(line);
        if (strcmp(db->sigs[index].sig, line) == 0) {
            printf("Virus signature %s found in file %s.\n", line, filename);
        }
    }
    fclose(fp);
}

int main() {
    virus_db db;
    db.num_sigs = 0;

    // Add some virus signatures to the database
    add_signature(&db, "eicar");
    add_signature(&db, "notavirus");
    add_signature(&db, "malware");
    add_signature(&db, "trojan");
    add_signature(&db, "worm");

    // Check some files for virus signatures
    check_file(&db, "sample.txt");
    check_file(&db, "eicar.txt");
    check_file(&db, "notavirus.txt");
    check_file(&db, "malware.txt");
    check_file(&db, "trojan.txt");
    check_file(&db, "worm.txt");

    return 0;
}