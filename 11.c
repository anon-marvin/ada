#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void bmergesort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        bmergesort(a, left, mid);
        bmergesort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
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
    bmergesort(a, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", time_used);

    return 0;
}