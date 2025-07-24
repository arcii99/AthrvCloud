//FormAI DATASET v1.0 Category: Database querying ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

//Callback function to print query results
static int callback(void *data, int argc, char **argv, char **colName){
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", colName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(){

    sqlite3 *db;
    char *errMsg = 0;
    int result;

    //Open database
    result = sqlite3_open("Employees.db", &db);
    if(result != SQLITE_OK){
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    //Create table
    char *sqlCreate = "CREATE TABLE IF NOT EXISTS Employees("
                      "ID INT PRIMARY KEY NOT NULL,"
                      "Name TEXT NOT NULL,"
                      "Age INT NOT NULL,"
                      "Department TEXT NOT NULL);";

    result = sqlite3_exec(db, sqlCreate, 0, 0, &errMsg);
    if(result != SQLITE_OK){
        fprintf(stderr, "Failed to create table: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    //Insert sample data
    char *sqlInsert = "INSERT INTO Employees(ID,Name,Age,Department)"
                      "VALUES(1,'John Doe',28,'Marketing'),(2,'Jane Smith',32,'Sales'),(3,'Bob Johnson',24,'IT');";

    result = sqlite3_exec(db, sqlInsert, 0, 0, &errMsg);
    if(result != SQLITE_OK){
        fprintf(stderr, "Failed to insert data: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    //Query data
    char *sqlSelect = "SELECT * FROM Employees WHERE Department='IT';";

    printf("Querying Employees table for IT Department...\n");

    result = sqlite3_exec(db, sqlSelect, callback, 0, &errMsg);
    if(result != SQLITE_OK){
        fprintf(stderr, "Failed to select data: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    //Update data
    char *sqlUpdate = "UPDATE Employees SET Age=27 WHERE Name='Bob Johnson';";

    result = sqlite3_exec(db, sqlUpdate, 0, 0, &errMsg);
    if(result != SQLITE_OK){
        fprintf(stderr, "Failed to update data: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    //Query data again
    printf("Querying Employees table after updating Bob Johnson's age...\n");

    result = sqlite3_exec(db, sqlSelect, callback, 0, &errMsg);
    if(result != SQLITE_OK){
        fprintf(stderr, "Failed to select data: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    //Delete data
    char *sqlDelete = "DELETE FROM Employees WHERE Name='John Doe';";

    result = sqlite3_exec(db, sqlDelete, 0, 0, &errMsg);
    if(result != SQLITE_OK){
        fprintf(stderr, "Failed to delete data: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    //Query data one more time
    printf("Querying Employees table after deleting John Doe...\n");

    result = sqlite3_exec(db, sqlSelect, callback, 0, &errMsg);
    if(result != SQLITE_OK){
        fprintf(stderr, "Failed to select data: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_close(db);
        return 1;
    }

    //Close database
    sqlite3_close(db);

    return 0;
}