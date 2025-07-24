//FormAI DATASET v1.0 Category: Database querying ; Style: beginner-friendly
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>  // Note: You will need to install the MySQL Connector/C library

int main(int argc, char *argv[]) {

   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;
   
   char *server = "localhost";
   char *user = "root";
   char *password = "password";  // replace with your own MySQL password
   char *database = "mydb";
   char query[1000];
   
   conn = mysql_init(NULL);

   if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   strcpy(query, "SELECT * FROM employees WHERE salary > ");
   strcat(query, argv[1]);  // get the user-supplied salary threshold
   strcat(query, ";");

   if (mysql_query(conn, query)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   res = mysql_use_result(conn);

   printf("Employee Name\t \t Salary\n");  // table header
   while ((row = mysql_fetch_row(res)) != NULL) {
      printf("%s\t \t %s\n", row[1], row[3]);  // print employee name and salary
   }

   mysql_free_result(res);
   mysql_close(conn);
   
   return 0;
}