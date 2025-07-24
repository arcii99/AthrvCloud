//FormAI DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char f1[100], f2[100], c;
    int choice, found = 0;

    printf("Enter name of first file to read: ");
    scanf("%s", f1);

    printf("Enter name of second file to write: ");
    scanf("%s", f2);

    fp1 = fopen(f1, "r");
    if (fp1 == NULL) {
        printf("%s file cannot be opened.\n", f1);
        exit(0);
    }

    fp2 = fopen(f2, "w");
    if (fp2 == NULL) {
        printf("%s file cannot be opened.\n", f2);
        exit(0);
    }

    printf("Enter a character to search in %s: ", f1);
    scanf(" %c", &c);

    while (fgets(f1, 100, fp1)) {
        if (strstr(f1, &c)) {
            found++;
            fprintf(fp2, "%s", f1);
        }
    }

    if (found == 0) {
        printf("%c not found in %s.\n", c, f1);
    } else {
        printf("%d occurrences of %c found in %s and written to %s.\n", found, c, f1, f2);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}