//FormAI DATASET v1.0 Category: Data mining ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 50
#define MAX_STR_LEN 50

typedef struct {
    double data[MAX_COLS];
    char label[MAX_STR_LEN];
} Record;

typedef struct {
    Record rows[MAX_ROWS];
    int num_rows;
    int num_cols;
} Dataset;

void print_dataset(Dataset d) {
    printf("Number of Rows: %d\n", d.num_rows);
    printf("Number of Columns: %d\n", d.num_cols);
    for (int i = 0; i < d.num_rows; i++) {
        printf("%d: ", i);
        for (int j = 0; j < d.num_cols; j++) {
            printf("%.2f ", d.rows[i].data[j]);
        }
        printf("(%s)\n", d.rows[i].label);
    }
}

void add_record(Dataset *d, Record r) {
    if (d->num_rows < MAX_ROWS && r.label != NULL) {
        for (int i = 0; i < d->num_cols; i++) {
            d->rows[d->num_rows].data[i] = r.data[i];
        }
        for (int i = 0; i < MAX_STR_LEN; i++) {
            d->rows[d->num_rows].label[i] = r.label[i];
            if (r.label[i] == '\0') {
                break;
            }
        }
        d->num_rows++;
    }
}

Dataset filter_dataset(Dataset d, double min, double max, int column) {
    Dataset new_dataset = {0};
    new_dataset.num_cols = d.num_cols;
    for (int i = 0; i < d.num_rows; i++) {
        if (d.rows[i].data[column] >= min && d.rows[i].data[column] <= max) {
            add_record(&new_dataset, d.rows[i]);
        }
    }
    return new_dataset;
}

int main() {
    // Create initial dataset
    Dataset d = {0};
    d.num_cols = 3;
    d.rows[0].data[0] = 1.1;
    d.rows[0].data[1] = 2.2;
    d.rows[0].data[2] = 3.3;
    d.rows[0].label[0] = 'a';
    d.rows[0].label[1] = '\0';
    d.num_rows = 1;
    add_record(&d, (Record) {{4.4, 5.5, 6.6}, "b"});
    add_record(&d, (Record) {{7.7, 8.8, 9.9}, "c"});
    add_record(&d, (Record) {{10.1, 11.2, 12.3}, "d"});
    print_dataset(d);

    // Filter dataset
    Dataset filtered_dataset = filter_dataset(d, 5.0, 10.0, 1);
    printf("\nFiltered Dataset:\n");
    print_dataset(filtered_dataset);

    return 0;
}