//FormAI DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
    FILE *fp;
    char ch;

    fp = fopen("love.rj", "w+");

    fprintf(fp, "Romeo and Juliet.\n");

    fputs("What's in a name? That which we call a rose By any other name would smell as sweet.", fp);
    fputs("Good night, good night! Parting is such sweet sorrow", fp);
    fputs("O Romeo, Romeo, wherefore art thou Romeo?", fp);

    fseek(fp, 0, SEEK_SET);

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);

    return 0;
}