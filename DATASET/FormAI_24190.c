//FormAI DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdlib.h>
#include <stdio.h>
#include <mysql/mysql.h>

int main(int argc, char const *argv[]) {
  // Set up a connection to the database
  MYSQL *conn = mysql_init(NULL);
  if (conn == NULL) {
    printf("Oh no! The database connection failed. Please try again later.\n");
    return 1;
  }

  if (mysql_real_connect(conn, "localhost", "root", "password", NULL, 0, NULL, 0) == NULL) {
    printf("Uh-oh! It looks like we couldn't connect to the database. Please try again later.\n");
    return 1;
  }

  // Create a new query to get the average age of users
  char query[100];
  sprintf(query, "SELECT AVG(age) FROM users");

  // Execute the query
  if (mysql_query(conn, query) != 0) {
    printf("There was a problem with the query. Please try again later.\n");
    mysql_close(conn);
    return 1;
  }

  // Get the results of the query
  MYSQL_RES *result = mysql_store_result(conn);
  if (result == NULL) {
    printf("Hmm, we didn't get any results. Please try again later.\n");
    mysql_close(conn);
    return 1;
  }

  // Print out the query results
  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result))) {
    printf("Nice! The average age of our users is %s years old!\n", row[0]);
  }

  // Clean up and close the database connection
  mysql_free_result(result);
  mysql_close(conn);

  return 0;
}