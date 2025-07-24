//FormAI DATASET v1.0 Category: Database querying ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sqlite3.h>

// Define callback function for execute SQL commands
static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]){
	sqlite3 *DB;
	char *errorMessage;
	int status;
	
	// Open the database
	status = sqlite3_open("example.db", &DB);

	if(status){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(DB));
		return 0;
	}
	else{
		fprintf(stderr, "Opened database successfully\n");
	}

	// Create table
	char *createTable = "CREATE TABLE BOOKS("  \
		"ID INT PRIMARY KEY     NOT NULL," \
		"TITLE           TEXT    NOT NULL," \
		"AUTHOR          TEXT    NOT NULL," \
		"PRICE           REAL );";

	status = sqlite3_exec(DB, createTable, callback, 0, &errorMessage);

	if(status != SQLITE_OK){
		fprintf(stderr, "Create table error: %s\n", errorMessage);
		sqlite3_free(errorMessage);
	}
	else{
		fprintf(stdout, "Table created successfully\n");
	}

	// Insert into table
	char *insertData = "INSERT INTO BOOKS (ID, TITLE, AUTHOR, PRICE) " 
		"VALUES (1, 'Database Programming with SQLite3', 'Chris Newman', 29.99);" \
		"INSERT INTO BOOKS (ID, TITLE, AUTHOR, PRICE) " \
		"VALUES (2, 'SQLite3 - A Comprehensive Guide', 'Mike Owens', 24.99);" \
		"INSERT INTO BOOKS (ID, TITLE, AUTHOR, PRICE) " \
		"VALUES (3, 'SQLite3 Quick Start', 'Riaan Nel', 19.99);" \
		"INSERT INTO BOOKS (ID, TITLE, AUTHOR, PRICE) " \
		"VALUES (4, 'Beginning SQL Programming', 'Rod Stephens', 34.99);";

	status = sqlite3_exec(DB, insertData, callback, 0, &errorMessage);

	if(status != SQLITE_OK){
		fprintf(stderr, "Insert data error: %s\n", errorMessage);
		sqlite3_free(errorMessage);
	}
	else{
		fprintf(stdout, "Data inserted successfully\n");
	}

	// Select from table
	char *selectData = "SELECT ID, TITLE, AUTHOR, PRICE FROM BOOKS;";

	status = sqlite3_exec(DB, selectData, callback, (void*) "Select data", &errorMessage);

	if(status != SQLITE_OK){
		fprintf(stderr, "Select data error: %s\n", errorMessage);
		sqlite3_free(errorMessage);
	}
	else{
		fprintf(stdout, "Data selected successfully\n");
	}

	// Update table
	char *updateData = "UPDATE BOOKS set PRICE = 27.99 where ID=3;";

	status = sqlite3_exec(DB, updateData, callback, 0, &errorMessage);

	if(status != SQLITE_OK){
		fprintf(stderr, "Update data error: %s\n", errorMessage);
		sqlite3_free(errorMessage);
	}
	else{
		fprintf(stdout, "Data updated successfully\n");
	}

	// Delete from table
	char *deleteData = "DELETE from BOOKS where ID=4;";

	status = sqlite3_exec(DB, deleteData, callback, 0, &errorMessage);

	if(status != SQLITE_OK){
		fprintf(stderr, "Delete data error: %s\n", errorMessage);
		sqlite3_free(errorMessage);
	}
	else{
		fprintf(stdout, "Data deleted successfully\n");
	}

	// Close database
	sqlite3_close(DB);

	return 0;
}