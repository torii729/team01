#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ARR_SIZE 5

void product_dis();

int main(void)
{
    product_dis();
    return 0;
}

void product_dis()
{
    int i, discount_rate;
    int arr[ARR_SIZE];
    int arr_dis[ARR_SIZE];

    printf("상품가 5개를 입력하세요:\n");

    for (i = 0; i < ARR_SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("할인율(%%)? ");
    scanf("%d", &discount_rate);

    for (i = 0; i < ARR_SIZE; i++)
    {
        arr_dis[i] = (arr[i] / 100) * (100 - discount_rate);
    }

    for (i = 0; i < ARR_SIZE; i++)
    {
        printf("가격:%7d --> 할인가:%7d\n", arr[i], arr_dis[i]);
    }
}
