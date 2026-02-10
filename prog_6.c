#include <stdio.h>

/* swap two numbers using pointer */
void swapNum(int *x, int *y)
{
    int tmp = *x;   
    *x = *y;
    *y = tmp;
}

/* make max heap from index pos */
void fixMaxHeap(int data[], int size, int pos)
{
    int big = pos;
    int lchild = 2 * pos + 1;
    int rchild = 2 * pos + 2;

    if (lchild < size && data[lchild] > data[big])
        big = lchild;

    if (rchild < size && data[rchild] > data[big])
        big = rchild;

    if (big != pos)
    {
        swapNum(&data[pos], &data[big]);
        fixMaxHeap(data, size, big);   // call again for affected part
    }
}

/* build max heap from array */
void createMaxHeap(int data[], int size)
{
    int i;
    int start = (size / 2) - 1;   // last non leaf node

    for (i = start; i >= 0; i--)
        fixMaxHeap(data, size, i);
}

/* make min heap from index pos */
void fixMinHeap(int data[], int size, int pos)
{
    int small = pos;
    int lchild = 2 * pos + 1;
    int rchild = 2 * pos + 2;

    if (lchild < size && data[lchild] < data[small])
        small = lchild;

    if (rchild < size && data[rchild] < data[small])
        small = rchild;

    if (small != pos)
    {
        swapNum(&data[pos], &data[small]);
        fixMinHeap(data, size, small);
    }
}

/* build min heap from array */
void createMinHeap(int data[], int size)
{
    int i;
    int start = (size / 2) - 1;

    for (i = start; i >= 0; i--)
        fixMinHeap(data, size, i);
}

/* print array elements */
void showArray(int data[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", data[i]);
    printf("\n");
}

int main()
{
    int n, i;
    int maxArr[100];
    int minArr[100];

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1)
        return 1;   // simple error check

    printf("Enter %d values: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &maxArr[i]);
        minArr[i] = maxArr[i];   // copy array for min heap
    }

    printf("\nOriginal array:\n");
    showArray(maxArr, n);

    createMaxHeap(maxArr, n);
    printf("\nMax heap array:\n");
    showArray(maxArr, n);

    createMinHeap(minArr, n);
    printf("\nMin heap array:\n");
    showArray(minArr, n);

    return 0;
}
