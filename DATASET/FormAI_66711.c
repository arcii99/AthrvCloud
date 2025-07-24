//FormAI DATASET v1.0 Category: Database querying ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main() {
  
  printf("Greetings, user! Let's lookup some data in our database! :)\n");
  
  // Set up database connection
  MYSQL *conn;
  conn = mysql_init(NULL);
  if (!mysql_real_connect(conn, "localhost", "username", "password", "database_name", 0, NULL, 0)) {
    printf("Oops, there was an error connecting to the database! :(\n");
    exit(1);
  } else {
    printf("Connection to database successful! :)\n");
  }

  // Query the database
  char *query = "SELECT * FROM my_table WHERE name='Jane';";
  int status = mysql_query(conn, query);
  if (status) {
    printf("Uh oh! There was an error querying the database! :(\n");
    exit(1);
  }

  // Get the results
  MYSQL_RES *result = mysql_store_result(conn);
  if (!result) {
    printf("Oops, there was an error getting the results! :(\n");
    exit(1);
  }

  // Print the results
  MYSQL_ROW row;
  while ((row = mysql_fetch_row(result))) {
    printf("%s %s %s\n", row[0], row[1], row[2]);
  }

  // Clean up
  mysql_free_result(result);
  mysql_close(conn);
  printf("Thank you for using our program! Have a great day! :)\n");

  return 0;
}