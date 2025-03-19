#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

void Heapify(int A[], int top, int last)
{
    int key = A[top];
    int j = 2 * top + 1;
    while (j <= last)
    {
        if (j < last && A[j] < A[j + 1])
            j = j + 1;
        if (A[top] >= A[j])
            break;
        int temp = A[top];
        A[top] = A[j];
        A[j] = temp;
        top = j;
        j = 2 * top + 1;
    }
}

void BuildHeap(int A[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(A, i, n - 1);
}

void HeapSort(int A[], int n)
{
    int top = 0;
    BuildHeap(A, n);
    printf("Initial heap = ");
    display(A, n);
    for (int last = n - 1; last >= 1; last--)
    {
        int temp = A[top];
        A[top] = A[last];
        A[last] = temp;
        printf("\nAfter iteration %d: ", n - last);
        display(A, n);
        Heapify(A, top, last - 1);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
        A[i] = rand() % 100;
    printf("Generated array: ");
    display(A, n);
    HeapSort(A, n);
    printf("\nThe sorted elements are: ");
    display(A, n);
    return 0;
}
