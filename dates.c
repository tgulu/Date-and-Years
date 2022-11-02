#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *   Program name: dates.c
 *   Function: to print out date given on command line
 *   Compilation: gcc -ansi -o dates dates.c
 */

int main ( int argc, char *argv[] ) {

   /* Names of the months */
   char *monthName[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

   /* The number of days in each month */
   int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   int dd = 0;
   int mm = 0;
   int yyyy = 0;
   bool IsLeapYear = false;

   /* Check if the date is properly input */
   if ( argc == 3 ) {
      printf ( "Usage: ./dates dd mm yyyy \n" );
      exit ( 1 );
      } 

   else {
      dd = atoi ( argv[1] );
      mm = atoi ( argv[2] );
      yyyy = atoi ( argv[3] );
      }

   /* Check if year inputted is a leap year:
    * - Must be divisible by 4
    * - Cannot be divisible by 100 unless it is divisible by 400
    */

   if ( yyyy % 400 == 0 || ( yyyy % 4 == 0 && yyyy % 100 != 0 ) ) {
      IsLeapYear = true;
      monthLength[1] = 29; /* Change February's month length */
      }

   if ( yyyy%4!=0 ) {
      IsLeapYear = false;
      }

   if ( 1 > mm || mm > 12 ) {
      printf ( "Error - the month entered (%02d) is not in the proper range (1-12)\n", mm );
      exit (2);
      }

   if ( 1 > dd || dd > monthLength[mm-1] ) {
      printf ( "Error - you entered %02d for the day and that is not in the range (1-%02d)\n", dd, monthLength[mm-1] );
      exit (3);
      }


   /* Remember that arrays like monthName and monthLength start their index at 0 and not 1. */
   /* The first entry in the array is monthName[0], monthLength[0] */

   printf ( "The date is %s %02d, %04d\n", monthName[mm-1], dd, yyyy );
   printf ( "In %s there are %d days\n", monthName[mm-1], monthLength[mm-1] );

   if (IsLeapYear) {
      printf ( "%04d is a leap year\n", yyyy);
      }
   else {
      printf ( "%04d is not a leap year\n", yyyy);
      }
   return ( 0 );
}
