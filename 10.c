#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place the pivot element in its correct position
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;       // Index of the smaller element

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i; // Increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1; // Return the partitioning index
}

// Recursive Quick sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1);        // Recursively sort the left sub-array
        quickSort(arr, pi + 1, high);       // Recursively sort the right sub-array
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
    quickSort(a, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", time_used);

    return 0;
}
