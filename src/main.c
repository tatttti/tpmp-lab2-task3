/* Author: Tanya Golovkova */

/*
 * Entry point of the program. Demonstrates usage of GROUP module.
 */

#include "group.h"

int
main(void)
{
        GROUP       gr[GROUP_SIZE];
        int         i;
        int         found = 0;

        input_group(gr, GROUP_SIZE);
        sort_by_ses(gr, GROUP_SIZE);

        printf("\nSorted by SES:\n");
        print_group(gr, GROUP_SIZE);

        printf("\nStudents younger than 20 on 1 Dec of last year:\n");

        for (i = 0; i < GROUP_SIZE; i++) {
                if (is_younger_than_20(gr[i], 2025, 12, 1)) {
                        printf("%s\n", gr[i].name);
                        found = 1;
                }
        }

        if (!found)
                printf("No students younger than 20.\n");

        return 0;
}

