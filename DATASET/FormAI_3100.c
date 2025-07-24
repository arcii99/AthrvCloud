//FormAI DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "your_password"
#define DATABASE "your_database"

int main()
{
  MYSQL *conn;
  MYSQL_RES *res;
  MYSQL_ROW row;

  conn = mysql_init(NULL);

  /* Connect to database */
  if (!mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0))
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  /* Execute SQL Query */
  if (mysql_query(conn, "SELECT * FROM your_table"))
  {
    fprintf(stderr, "%s\n", mysql_error(conn));
    exit(1);
  }

  res = mysql_use_result(conn);

  /* Analyze data */
  while ((row = mysql_fetch_row(res)) != NULL)
  {
    printf("%s %s %s\n", row[0], row[1], row[2]);
  }

  /* Free memory */
  mysql_free_result(res);
  mysql_close(conn);

  return 0;
}