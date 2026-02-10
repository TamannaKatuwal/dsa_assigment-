#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long cmpCount = 0;     // count total comparisons present
long long moveCount = 0;    // count swaps or shifts given

/* reseting the counting values */
void clearCount()
{
    cmpCount = 0;
    moveCount = 0;
}

/* display array elements */
void showList(int list[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", list[i]);
    printf("\n");
}

/* bubble sorting */
/* bubble sorting */
void bubbleAlgo(int list[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            cmpCount++;
            if (list[j] > list[j + 1])
            {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
                moveCount++;
            }
        }
    }
}
/* selection sorting */
void selectAlgo(int list[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallPos = i;
        for (int j = i + 1; j < size; j++)
        {
            cmpCount++;
            if (list[j] < list[smallPos])
                smallPos = j;
        }

        if (smallPos != i)
        {
            int temp = list[i];
            list[i] = list[smallPos];
            list[smallPos] = temp;
            moveCount++;
        }
    }
}

/* insertion sort method */
void insertAlgo(int list[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int val = list[i];
        int j = i - 1;

        while (j >= 0 && list[j] > val)
        {
            cmpCount++;
            list[j + 1] = list[j];
            j--;
            moveCount++;   // shifting counted as we move
        }
        cmpCount++;   // last failed compare
        list[j + 1] = val;
    }
}

/* merging any two parts of array */
void mergeParts(int list[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = list[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = list[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        cmpCount++;
        if (L[i] <= R[j])
            list[k++] = L[i++];
        else
            list[k++] = R[j++];
        moveCount++;
    }

    while (i < n1)
    {
        list[k++] = L[i++];
        moveCount++;
    }

    while (j < n2)
    {
        list[k++] = R[j++];
        moveCount++;
    }
}

/* merge sorting */
void mergeAlgo(int list[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeAlgo(list, left, mid);
        mergeAlgo(list, mid + 1, right);
        mergeParts(list, left, mid, right);
    }
}

int main()
{
    int n, opt;
    srand(time(NULL));   // random seed

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *nums = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        nums[i] = (rand() % 1000) + 1;

    printf("\nOriginal list:\n");
    showList(nums, n);

    printf("\nChoose sorting technique:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter choice: ");
    scanf("%d", &opt);

    clearCount();

    switch (opt)
    {
        case 1: bubbleAlgo(nums, n); break;
        case 2: selectAlgo(nums, n); break;
        case 3: insertAlgo(nums, n); break;
        case 4: mergeAlgo(nums, 0, n - 1); break;
        default:
            printf("Wrong option selected\n");
            free(nums);
            return 0;
    }

    printf("\nSorted list:\n");
    showList(nums, n);

    printf("\nTotal comparisons: %lld", cmpCount);
    printf("\nTotal swaps or moves: %lld\n", moveCount);

    free(nums);
    return 0;
}

