#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return (i + 1);
}

int main()
{
    int n;
    printf("Enter a value of n greater than 4000\n");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
    }

    clock_t start, end;
    double time_used;
    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", time_used);

    return 0;
}
