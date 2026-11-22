#include <stdio.h>

#define DISTRICTS 38
#define MONTHS 12

int main(void)
{
    double rain[DISTRICTS][MONTHS];
    double total[DISTRICTS] = {0};
    double monthly[MONTHS] = {0};

    int i, j;
    int wetDistrict = 0, wetMonth = 0;

    double maximum = 0;
    double stateTotal = 0;
    double stateAverage;

    /* Generate rainfall data for 38 districts and 12 months */
    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            rain[i][j] = (i + 1) * 2 + (j + 1) * 5;
        }
    }

    /* Calculate district totals and monthly totals */
    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            total[i] += rain[i][j];
            monthly[j] += rain[i][j];

            if (rain[i][j] > maximum)
            {
                maximum = rain[i][j];
                wetDistrict = i;
                wetMonth = j;
            }
        }

        stateTotal += total[i];
    }

    stateAverage = stateTotal / DISTRICTS;

    printf("ANNUAL RAINFALL OF EACH DISTRICT\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        printf("District %d: %.2f mm\n",
               i + 1, total[i]);
    }

    printf("\nMONTHLY AVERAGE RAINFALL\n");

    for (j = 0; j < MONTHS; j++)
    {
        printf("Month %d: %.2f mm\n",
               j + 1, monthly[j] / DISTRICTS);
    }

    printf("\nWETTEST DISTRICT-MONTH\n");
    printf("District: %d\n", wetDistrict + 1);
    printf("Month: %d\n", wetMonth + 1);
    printf("Rainfall: %.2f mm\n", maximum);

    printf("\nSTATE AVERAGE ANNUAL RAINFALL: %.2f mm\n",
           stateAverage);

    printf("\nDISTRICTS BELOW 60%% OF STATE AVERAGE\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        if (total[i] < 0.60 * stateAverage)
        {
            printf("District %d: %.2f mm\n",
                   i + 1, total[i]);
        }
    }

    return 0;
}
