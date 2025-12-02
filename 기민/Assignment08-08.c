#include <stdio.h>

void test(void);
void fill_array(int* arr, int size, int value);
void print_array(const int* arr, int size);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    int arr[20];
    int value;
    int ok;

    printf("배열의 원소에 저장할 값? ");
    ok = scanf_s("%d", &value);
    if (ok != 1)
    {
        return;
    }

    fill_array(arr, 20, value);
    print_array(arr, 20);
}

void fill_array(int* arr, int size, int value)
{
    int i;

    for (i = 0; i < size; i++)
    {
        *(arr + i) = value;
    }
}

void print_array(const int* arr, int size)
{
    int i;

    printf("배열: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
