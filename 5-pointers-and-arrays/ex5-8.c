// There is no error checking in day_of_the_year or month_day. Remedy this
// defect.

#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
  int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  if (month < 1 || month > 12)
  {
    printf("error: month must be between 1 and 12\n");
    return -1;
  }
  if (day < 1 || day > daytab[leap][month])
  {
    printf("error: day must be between 1 and %d\n", daytab[leap][month]);
    return -1;
  }

  int i;

  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

/* month_day: set month, day from day of year*/
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  if (yearday < 1 || yearday > 365 + leap)
    printf("error: yearday must be between 1 and %d\n", 365 + leap);
  
  int i;

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

int main()
{
  printf("ans: 60, res: %d\n", day_of_year(-2023, 3, 1));
  printf("ans: 61, res: %d\n", day_of_year(-2024, 3, 1));

  int month, day;
  month_day(2023, 60, &month, &day);
  printf("ans: 1/3, res: %d/%d\n", day, month);
  month_day(2024, 61, &month, &day);
  printf("ans: 1/3, res: %d/%d\n", day, month);
  return 0;
}