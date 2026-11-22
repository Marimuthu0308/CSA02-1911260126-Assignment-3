#include <stdio.h>
#include <string.h>

int main(void)
{
    char names[5][30] = {
        "Karthik",
        "Marimuthu",
        "Arun",
        "Bala",
        "Marimuthu"
    };

    char searchName[] = "Marimuthu";
    char temp[30];

    int i, j;
    int low, high, mid;
    int found = -1;

    /* Sort names alphabetically */
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4 - i; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    printf("SORTED NAME DIRECTORY\n");

    for (i = 0; i < 5; i++)
    {
        printf("%s\n", names[i]);
    }

    /* Binary search */
    low = 0;
    high = 4;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (strcmp(names[mid], searchName) == 0)
        {
            found = mid;
            break;
        }
        else if (strcmp(names[mid], searchName) < 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("\nSEARCHING FOR: %s\n", searchName);

    if (found != -1)
        printf("Name found at index %d\n", found);
    else
        printf("Name not found\n");

    /* Display duplicate names */
    printf("\nDUPLICATE NAMES\n");

    for (i = 1; i < 5; i++)
    {
        if (strcmp(names[i], names[i - 1]) == 0)
        {
            printf("%s\n", names[i]);
        }
    }

    return 0;
}
