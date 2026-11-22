#include <stdio.h>

#define MAX 1000

void copy_array(int source[], int destination[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        destination[i] = source[i];
}

void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

void bubble_sort(int a[], int n, long *comparisons, long *swaps)
{
    int i, j, temp;
    int changed;

    *comparisons = 0;
    *swaps = 0;

    for (i = 0; i < n - 1; i++)
    {
        changed = 0;

        for (j = 0; j < n - 1 - i; j++)
        {
            (*comparisons)++;

            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                (*swaps)++;
                changed = 1;
            }
        }

        if (changed == 0)
            break;
    }
}

void selection_sort(int a[], int n, long *comparisons, long *swaps)
{
    int i, j, min, temp;

    *comparisons = 0;
    *swaps = 0;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            (*comparisons)++;

            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;

            (*swaps)++;
        }
    }
}

void insertion_sort(int a[], int n, long *comparisons, long *shifts)
{
    int i, j, key;

    *comparisons = 0;
    *shifts = 0;

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0)
        {
            (*comparisons)++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                (*shifts)++;
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }
}

int main(void)
{
    int original[MAX];
    int a[MAX];
    int b[MAX];
    int c[MAX];

    int n, i;
    long comparisons, operations;

    printf("Enter number of elements (maximum %d): ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid size.\n");
        return 1;
    }

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &original[i]);

    copy_array(original, a, n);
    copy_array(original, b, n);
    copy_array(original, c, n);

    bubble_sort(a, n, &comparisons, &operations);

    printf("\nBubble Sort:\n");
    display(a, n);
    printf("Comparisons = %ld, Swaps = %ld\n",
           comparisons, operations);

    selection_sort(b, n, &comparisons, &operations);

    printf("\nSelection Sort:\n");
    display(b, n);
    printf("Comparisons = %ld, Swaps = %ld\n",
           comparisons, operations);

    insertion_sort(c, n, &comparisons, &operations);

    printf("\nInsertion Sort:\n");
    display(c, n);
    printf("Comparisons = %ld, Shifts = %ld\n",
           comparisons, operations);

    return 0;
}
