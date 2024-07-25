#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void selsort(int a[], int n)
{
    int i, j, pos, temp;
    for (i = 0; i < n - 1; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[pos])
            {
                pos = j;
            }
        }
        temp = a[pos];
        a[pos] = a[i];
        a[i] = temp;
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

    clock_t start,
        end;
    double time_used;
    start = clock();
    selsort(a, n);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f", time_used);
}