#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void sit();
void sitPrint(int sitTrain[], int size);
void sitInput(int sitTrain[], int size);
void sitCheck(int sitTrain[], int size);

int main()
{
    sit();
    return 0;
}

void sit()
{
    int sitTrain[10] = { 0 };
    int size = sizeof(sitTrain) / sizeof(sitTrain[0]);

    sitInput(sitTrain, size);
}

void sitPrint(int sitTrain[], int size)
{
    printf("현재 좌석 : [ ");

    for (int i = 0; i < size; i++)
    {
        if (sitTrain[i] == 0)
            printf("O ");
        else
            printf("X ");
    }
    printf("]\n");
}

void sitInput(int sitTrain[], int size)
{
    int num = 0;

    while (1)
    {
        int sitReserved[10] = { 0 };
        int reserved = 0;
        int remain = 0;

        sitPrint(sitTrain, size);

        printf("예매할 좌석수? ");
        if (scanf("%d", &num) != 1)
        {
            printf("잘못된 입력입니다.\n");
            return;
        }

        for (int i = 0; i < size; i++)
        {
            if (sitTrain[i] == 0)
            {
                remain++;
            }
        }

        if (remain < num)
        {
            printf("예약 좌석이 부족합니다.\n");
            break;
        }

        for (int i = 0; reserved < num && i < size; i++)
        {
            if (sitTrain[i] == 0)
            {
                sitTrain[i] = 1;
                sitReserved[reserved] = i + 1;
                reserved++;
            }
        }

        for (int j = 0; j < reserved; j++)
            printf("%d ", sitReserved[j]);
        printf("번 좌석을 예매했습니다.\n");

        sitCheck(sitTrain, size);
    }
}

void sitCheck(int sitTrain[], int size)
{
    int all = 1;

    for (int i = 0; i < size; i++)
    {
        if (sitTrain[i] == 0)
        {
            all = 0;
            break;
        }
    }

    if (all == 1)
    {
        printf("모든 좌석 예매 완료.\n");
        exit(0);
    }
}
