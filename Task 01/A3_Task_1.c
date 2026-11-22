#include <stdio.h>

int steps;

/* Binary search in ascending order */
int binary_search(const int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;

    steps = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        steps++;

        if (a[mid] == key)
            return mid;

        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main(void)
{
    int accession[] = {
        1021, 1048, 1103, 1190, 1222,
        1305, 1377, 1402, 1460, 1533
    };

    int keys[] = {1021, 1305, 1533, 1400};
    int n = sizeof(accession) / sizeof(accession[0]);
    int k;
    int pos;

    for (k = 0; k < 4; k++)
    {
        pos = binary_search(accession, n, keys[k]);

        printf("Book %d -> index %d, comparisons = %d\n",
               keys[k], pos, steps);
    }

    return 0;
}
