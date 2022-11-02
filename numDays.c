#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *   Program name: numDays.c
 *   Compilation: gcc -ansi -o numDays numDays.c
 *   Errors: Program must receive a valid date, and the offset must be less than 300
 */

int main (int argc, char *argv[]) {
   int leapMonthDays[12] = {1, 32, 61, 92, 122, 153, 183, 214, 245, 275, 306, 336};
   int regMonthDays[12] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
   int monthLength[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   int day, month, year, offset, max, dayPlusTime;
   int i = 0;
   bool leap = false;

   if ( argc < 5 ) {
      printf ( "Usage: ./dates mm dd yyyy \n" );
      exit ( 1 );
   }
   day = atoi(argv[1]);
   month = atoi(argv[2]);
   year = atoi(argv[3]);
   offset = atoi(argv[4]);
   if (offset > 300){
      printf("Invalid number of days\n");
      exit(1);
   }

   if (year % 4 == 0){
      leap = true;
      if (year % 100 == 0 && !(year % 400 == 0)){
         leap = false;
      }
   }
   if (!(leap) && (month == 2 && day == 29)) {
      printf("Invalid date\n");
      exit (1);
   }
   if (leap) {
      monthLength[1] = 29;
   }
   max = monthLength[month -1];
   if (month < 1 || month > 12) {
     printf("Invalid date\n");
     exit(1);
   }
   if (day < 1 || day > max) {
      printf("Invalid date\n");
      exit(1);
   }
   if (year < 0){
      printf("Invalid date\n");
      exit(1);
   }
   if (leap){
      dayPlusTime = leapMonthDays[month - 1] + day - 1 + offset;
      if (dayPlusTime > 366){
         year += 1;
         dayPlusTime = dayPlusTime - 366;
         while (dayPlusTime > (regMonthDays[i] + monthLength[i])){
            i++;
         }
         if (dayPlusTime == regMonthDays[i] + monthLength[i]){
         i = i + 1;
         month = i + 1;
         day = dayPlusTime - regMonthDays[i] + 1;
         printf("%d %d %d\n", day, month, year);
         }else {
         month = i + 1;
         day = dayPlusTime - regMonthDays[i] + 1;
         printf("%d %d %d\n", day, month, year);
         }
      } else{
         while (dayPlusTime > (leapMonthDays[i] + monthLength[i])){
            i++;
         }
         if (dayPlusTime == leapMonthDays[i] + monthLength[i]){
         i = i + 1;
         month = i + 1;
         day = dayPlusTime - leapMonthDays[i] + 1;
         printf("%d %d %d\n", day, month, year);
         }else {
         month = i + 1;
         day = dayPlusTime - leapMonthDays[i] + 1;
         printf("%d %d %d\n", day, month, year);
         }
      }
   } else{
      dayPlusTime = regMonthDays[month - 1] + day - 1 + offset;
      if (dayPlusTime > 365){
         year += 1;
         dayPlusTime = dayPlusTime - 365;
         leap = false;
         if (year % 4 == 0){
            leap = true;
            if (year % 100 == 0 && !(year % 400 == 0)){
               leap = false;
            }
         }
         if (leap){
            while (dayPlusTime > (leapMonthDays[i] + monthLength[i])){
               i++;
            }
            if (dayPlusTime == leapMonthDays[i] + monthLength[i]){
               i = i + 1;
               month = i + 1;
               day = dayPlusTime - leapMonthDays[i] + 1;
               printf("%d %d %d\n", day, month, year);
            }else {
               month = i + 1;
               day = dayPlusTime - leapMonthDays[i] + 1;
               printf("%d %d %d\n", day, month, year);
            }
         } else{
            while (dayPlusTime > (regMonthDays[i] + monthLength[i])){
               i++;
            }
            if (dayPlusTime == regMonthDays[i] + monthLength[i]){
               i = i + 1;
               month = i + 1;
               day = dayPlusTime - regMonthDays[i] + 1;
               printf("%d %d %d\n", day, month, year);
            }else {
               month = i + 1;
               day = dayPlusTime - regMonthDays[i] + 1;
               printf("%d %d %d\n", day, month, year);
            }

         }
      } else{
         while (dayPlusTime > (regMonthDays[i] + monthLength[i])){
            i++;
         }
         if (dayPlusTime == regMonthDays[i] + monthLength[i]){
            i = i + 1;
            month = i + 1;
            day = dayPlusTime - regMonthDays[i] + 1;
            printf("%d %d %d\n", day, month, year);
         }else {
            month = i + 1;
            day = dayPlusTime - regMonthDays[i] + 1;
            printf("%d %d %d\n", day, month, year);
         }
      }
   }
   return(0);
}
