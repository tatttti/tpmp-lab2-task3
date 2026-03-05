/* Author: Tanya Golovkova */

/*
 * This file contains implementations of functions declared in group.h.
 * It includes input, sorting by SES, age calculation and printing utilities.
 */

#include "group.h"
#include <string.h>

/* Local function declarations */
static float  average_ses(
                GROUP   s
        );

/*
 * Calculates average SES value.
 */
static float
average_ses(GROUP s)
{
        int         sum = 0;
        int         i;

        for (i = 0; i < SES_COUNT; i++)
                sum += s.ses[i];

        return (float)sum / SES_COUNT;
}

/*
 * Reads GROUP array from keyboard.
 */
void
input_group(GROUP arr[], int count)
{
        int         i;
        int         j;

        for (i = 0; i < count; i++) {
                printf("Enter name: ");
                scanf("%s", arr[i].name);

                printf("Enter birth date (Y M D): ");
                scanf("%d %d %d",
                        &arr[i].dat.year,
                        &arr[i].dat.month,
                        &arr[i].dat.day);

                printf("Enter %d SES values:\n", SES_COUNT);
                for (j = 0; j < SES_COUNT; j++)
                        scanf("%d", &arr[i].ses[j]);
        }
}

/*
 * Sorts GROUP array by SES average (ascending).
 */
void
sort_by_ses(GROUP arr[], int count)
{
        int         i;
        int         j;
        GROUP       tmp;

        for (i = 0; i < count - 1; i++) {
                for (j = i + 1; j < count; j++) {
                        if (average_ses(arr[j]) <
                            average_ses(arr[i])) {

                                tmp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = tmp;
                        }
                }
        }
}

/*
 * Returns 1 if student is 20 or younger on given date.
 */
int
is_younger_than_20(GROUP s, int year, int month, int day)
{
        int         age = year - s.dat.year;

        if (month < s.dat.month ||
            (month == s.dat.month && day < s.dat.day))
                age--;

        return age <= 20;
}

/*
 * Prints GROUP array.
 */
void
print_group(GROUP arr[], int count)
{
        int         i;

        for (i = 0; i < count; i++) {
                printf("%s %d-%02d-%02d avg=%.2f\n",
                        arr[i].name,
                        arr[i].dat.year,
                        arr[i].dat.month,
                        arr[i].dat.day,
                        average_ses(arr[i]));
        }
}

