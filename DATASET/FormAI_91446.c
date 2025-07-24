//FormAI DATASET v1.0 Category: Database querying ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

// callback function for printing the query results
static int callback(void *data, int argc, char **argv, char **azColName){
    int i;
    printf("|");
    for(i=0; i<argc; i++){
        printf("%s = %s\t|", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n----------------------------------\n");
    return 0;
}

int main(int argc, char** argv) {
    
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";

    rc = sqlite3_open("test.db", &db);
    if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
    } else {
      fprintf(stderr, "Opened database successfully\n");
    }
    
    // Create tables if they don't already exist
    sql = "CREATE TABLE IF NOT EXISTS students(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE INT NOT NULL, GRADE INT NOT NULL);"
            "CREATE TABLE IF NOT EXISTS courses(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, DESCRIPTION TEXT NOT NULL);"
            "CREATE TABLE IF NOT EXISTS enrollments(STUDENT_ID INT, COURSE_ID INT, PRIMARY KEY(STUDENT_ID, COURSE_ID), FOREIGN KEY(STUDENT_ID) REFERENCES students(ID), FOREIGN KEY(COURSE_ID) REFERENCES courses(ID));";
    
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return(0);
    } else {
      fprintf(stdout, "Tables created successfully\n");
    }

    // Insert data into tables
    sql = "INSERT INTO students (ID, NAME, AGE, GRADE) VALUES (1, 'John Smith', 16, 10);"
            "INSERT INTO students (ID, NAME, AGE, GRADE) VALUES (2, 'Mary Johnson', 17, 11);"
            "INSERT INTO students (ID, NAME, AGE, GRADE) VALUES (3, 'David Lee', 15, 9);"
            "INSERT INTO courses (ID, NAME, DESCRIPTION) VALUES (1, 'Math', 'Calculus and Trigonometry');"
            "INSERT INTO courses (ID, NAME, DESCRIPTION) VALUES (2, 'Science', 'Biology and Physics');"
            "INSERT INTO courses (ID, NAME, DESCRIPTION) VALUES (3, 'History', 'World and American History');"
            "INSERT INTO enrollments (STUDENT_ID, COURSE_ID) VALUES (1, 1);"
            "INSERT INTO enrollments (STUDENT_ID, COURSE_ID) VALUES (1, 2);"
            "INSERT INTO enrollments (STUDENT_ID, COURSE_ID) VALUES (2, 2);"
            "INSERT INTO enrollments (STUDENT_ID, COURSE_ID) VALUES (2, 3);"
            "INSERT INTO enrollments (STUDENT_ID, COURSE_ID) VALUES (3, 1);"
            "INSERT INTO enrollments (STUDENT_ID, COURSE_ID) VALUES (3, 3);";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return(0);
    } else {
      fprintf(stdout, "Data inserted successfully\n");
    }

    // SELECT query to get all the students enrolled in a specific course
    sql = "SELECT students.NAME, courses.NAME "
            "FROM students, courses, enrollments "
            "WHERE students.ID = enrollments.STUDENT_ID "
            "AND courses.ID = enrollments.COURSE_ID "
            "AND courses.NAME = 'Science';";

    // Execute the query and print the results
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
      return(0);
    }

    // Close the database connection
    sqlite3_close(db);
    
    return 0;
}