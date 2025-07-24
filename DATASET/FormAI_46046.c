//FormAI DATASET v1.0 Category: Database querying ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql/mysql.h> //Include MySQL header files

int main()
{
   MYSQL *con = mysql_init(NULL); //Create a MYSQL object

   if(con == NULL)
   {
      fprintf(stderr, "%s\n", mysql_error(con)); //Print error message if object could not be created
      exit(1);
   }

   //Connect to the MySQL database
   if(mysql_real_connect(con, "localhost", "root", "password", "mydatabase", 0, NULL, 0) == NULL)
   {
      fprintf(stderr, "%s\n", mysql_error(con)); //Print error message if connection could not be established
      mysql_close(con);
      exit(1);
   }

   //Query the database
   if(mysql_query(con, "SELECT * FROM mytable")) //Retrieving all rows from the table
   {
      fprintf(stderr, "%s\n", mysql_error(con)); //Print error message if query fails
      mysql_close(con);
      exit(1);
   }

   MYSQL_RES *result = mysql_store_result(con); //Store the query result in an object

   if(result == NULL)
   {
      fprintf(stderr, "%s\n", mysql_error(con)); //Print error message if storing failed
      mysql_close(con);
      exit(1);
   }

   int num_fields = mysql_num_fields(result); //Get the number of columns in the result set
   MYSQL_ROW row;

   //Process and print the query result
   while((row = mysql_fetch_row(result)))
   {
      for(int i = 0; i < num_fields; i++)
      {
         printf("%s ", row[i] ? row[i] : "NULL");
      }
      printf("\n");
   }

   mysql_free_result(result); //Free memory allocated for result
   mysql_close(con); //Close the MySQL connection
   return 0;
}