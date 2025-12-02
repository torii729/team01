#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fill_2d_array(int* p, int row, int value);
void input_num();

int main(void)
{
    input_num();
    return 0;
}

void fill_2d_array(int* p, int row, int value)
{
    int i, j;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < 5; j++, p++)
        {
            *p = value;
        }
    }
}

void input_num()
{
    int arr[4][5];
    int value, i, j;
    int (*p)[5] = arr;

    printf("배열의 원소에 저장할 값? ");
    scanf("%d", &value);

    fill_2d_array(*p, 4, value);

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
