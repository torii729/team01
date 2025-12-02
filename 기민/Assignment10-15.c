#include <stdio.h>

typedef struct
{
    int x;
    int y;
} POINT;

void test(void);
void swap_point(POINT* a, POINT* b);
void selection_sort(POINT arr[], int n);
void print_points(POINT arr[], int n);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    POINT arr[10] =
    {
        { 7, 4 }, { 12, 93 }, { 22, 31 }, { 1, 20 }, { 34, 53 },
        { 41, 2 }, { 32, 9 }, { 21, 31 }, { 8, 2 }, { 3, 5 }
    };

    printf("<정렬 전>\n");
    print_points(arr, 10);

    selection_sort(arr, 10);

    printf("<정렬 후>\n");
    print_points(arr, 10);
}

void swap_point(POINT* a, POINT* b)
{
    POINT temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(POINT arr[], int n)
{
    int i;
    int j;
    int min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < n; j++)
        {
            if (arr[j].x < arr[min_idx].x)
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            swap_point(&arr[i], &arr[min_idx]);
        }
    }
}

void print_points(POINT arr[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("(%d, %d) ", arr[i].x, arr[i].y);
    }
    printf("\n");
}
