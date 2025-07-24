//FormAI DATASET v1.0 Category: Database querying ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
  MYSQL *conn = mysql_init(NULL);

  if (conn == NULL) {
    printf("Error: Failed to initialize MySQL connection\n");
    exit(1);
  }

  // Connect to the database
  if (mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0) == NULL) {
    printf("Error: Failed to connect to the database with error %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
  }

  // Execute SQL query
  const char *query = "SELECT * FROM students WHERE age > 21";
  if (mysql_query(conn, query) != 0) {
    printf("Error: Failed to execute query with error %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
  }

  // Fetch results and print them
  MYSQL_RES *result = mysql_store_result(conn);
  if (result == NULL) {
    printf("Error: Failed to fetch results with error %s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
  }

  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result))) {
    printf("ID: %s, Name: %s, Age: %s\n", row[0], row[1], row[2]);
  }

  // Clean up
  mysql_free_result(result);
  mysql_close(conn);
  return 0;
}