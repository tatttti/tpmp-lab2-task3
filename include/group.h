/* Author: Tanya Golovkova */

#ifndef GROUP_H
#define GROUP_H

/*
 * This header defines the GROUP structure and public functions
 * for input, sorting by SES, age filtering and printing.
 */

#include <stdio.h>
#include <time.h>

/* Module-wide constants */
#define NAME_LEN            50
#define SES_COUNT           3
#define GROUP_SIZE          10

/* Type definitions */
typedef struct {
        int         year;
        int         month;
        int         day;
} Date;

typedef struct {
        char        name[NAME_LEN];
        Date        dat;
        int         ses[SES_COUNT];
} GROUP;

/* Public function declarations */
void    input_group(
                GROUP   arr[],
                int     count
        );

void    sort_by_ses(
                GROUP   arr[],
                int     count
        );

int     is_younger_than_20(
                GROUP   s,
                int     year,
                int     month,
                int     day
        );

void    print_group(
                GROUP   arr[],
                int     count
        );

#endif /* GROUP_H */

