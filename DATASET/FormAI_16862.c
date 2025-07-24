//FormAI DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <string.h>

// Define constants
#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 10

// Define data types
typedef struct {
    char name[MAX_NAME_LENGTH];
    char id[MAX_ID_LENGTH];
    int score;
} StudentRecord;

typedef struct {
    int num_records;
    StudentRecord records[MAX_RECORDS];
} StudentDatabase;

typedef struct {
    int index;
    StudentRecord *record;
} IndexItem;

typedef struct {
    char index_id[MAX_ID_LENGTH];
    int num_items;
    IndexItem items[MAX_RECORDS];
} Index;

// Function prototypes
void search_by_name(StudentDatabase db, Index name_index);
void search_by_id(StudentDatabase db, Index id_index);
void search_by_score(StudentDatabase db, Index score_index);

int main() {
    // Initialize the database
    StudentDatabase db = {
        .num_records = 6,
        .records = {
            {"Alice", "1001", 90},
            {"Bob", "1002", 85},
            {"Charlie", "1003", 92},
            {"Dave", "1004", 80},
            {"Eve", "1005", 95},
            {"Frank", "1006", 88}
        }
    };
    
    // Initialize the indexes
    Index name_index = {
        .index_id = "name",
        .num_items = db.num_records
    };
    Index id_index = {
        .index_id = "id",
        .num_items = db.num_records
    };
    Index score_index = {
        .index_id = "score",
        .num_items = db.num_records
    };
    
    // Populate the indexes
    for (int i = 0; i < db.num_records; i++) {
        // Name index
        name_index.items[i].index = i;
        name_index.items[i].record = &db.records[i];
        // ID index
        id_index.items[i].index = i;
        id_index.items[i].record = &db.records[i];
        // Score index
        score_index.items[i].index = i;
        score_index.items[i].record = &db.records[i];
    }
    
    // Sort the indexes
    for (int i = 0; i < name_index.num_items-1; i++) {
        for (int j = i+1; j < name_index.num_items; j++) {
            if (strcmp(name_index.items[i].record->name, name_index.items[j].record->name) > 0) {
                IndexItem temp = name_index.items[i];
                name_index.items[i] = name_index.items[j];
                name_index.items[j] = temp;
            }
        }
    }
    for (int i = 0; i < id_index.num_items-1; i++) {
        for (int j = i+1; j < id_index.num_items; j++) {
            if (strcmp(id_index.items[i].record->id, id_index.items[j].record->id) > 0) {
                IndexItem temp = id_index.items[i];
                id_index.items[i] = id_index.items[j];
                id_index.items[j] = temp;
            }
        }
    }
    for (int i = 0; i < score_index.num_items-1; i++) {
        for (int j = i+1; j < score_index.num_items; j++) {
            if (score_index.items[i].record->score > score_index.items[j].record->score) {
                IndexItem temp = score_index.items[i];
                score_index.items[i] = score_index.items[j];
                score_index.items[j] = temp;
            }
        }
    }
    
    // Search the database using the indexes
    search_by_name(db, name_index);
    search_by_id(db, id_index);
    search_by_score(db, score_index);
    
    return 0;
}

void search_by_name(StudentDatabase db, Index name_index) {
    printf("Enter name to search for: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    
    int i = 0;
    int j = name_index.num_items-1;
    while (i <= j) {
        int mid = (i+j)/2;
        if (strcmp(name_index.items[mid].record->name, name) == 0) {
            printf("%s %s %d\n", name_index.items[mid].record->name, name_index.items[mid].record->id, name_index.items[mid].record->score);
            return;
        } else if (strcmp(name_index.items[mid].record->name, name) < 0) {
            i = mid+1;
        } else {
            j = mid-1;
        }
    }
    printf("Record not found.\n");
}

void search_by_id(StudentDatabase db, Index id_index) {
    printf("Enter ID to search for: ");
    char id[MAX_ID_LENGTH];
    scanf("%s", id);
    
    int i = 0;
    int j = id_index.num_items-1;
    while (i <= j) {
        int mid = (i+j)/2;
        if (strcmp(id_index.items[mid].record->id, id) == 0) {
            printf("%s %s %d\n", id_index.items[mid].record->name, id_index.items[mid].record->id, id_index.items[mid].record->score);
            return;
        } else if (strcmp(id_index.items[mid].record->id, id) < 0) {
            i = mid+1;
        } else {
            j = mid-1;
        }
    }
    printf("Record not found.\n");
}

void search_by_score(StudentDatabase db, Index score_index) {
    printf("Enter minimum score to search for: ");
    int min_score;
    scanf("%d", &min_score);
    printf("Enter maximum score to search for: ");
    int max_score;
    scanf("%d", &max_score);
    
    for (int i = 0; i < score_index.num_items; i++) {
        if (score_index.items[i].record->score >= min_score && score_index.items[i].record->score <= max_score) {
            printf("%s %s %d\n", score_index.items[i].record->name, score_index.items[i].record->id, score_index.items[i].record->score);
        }
    }
}