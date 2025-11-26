/*
   문제: 열 크기가 5인 2차원 int 배열의 모든 원소를 특정 값으로 채우는 fill_2d_array 함수를 작성하시오.
        함수의 매개변수로 배열 전체에 대한 포인터와 배열의 행 크기를 전달한다.
        열 크기가 5, 행 크기가 4인 2차원 배열을 입력받은 값으로 채우고 출력하는 프로그램을 작성하시오.
   출력 예시: 배열의 원소에 저장할 값? 5
            5 5 5 5 5
            5 5 5 5 5
            5 5 5 5 5
            5 5 5 5 5
*/
#define _CRT_SECURE_NO_WARNINGS   // scanf 보안 경고를 무시하기 위한 매크로 정의
#include <stdio.h>               // 표준 입출력 함수 사용을 위한 헤더

void fill_2d_array(int* p, int row, int value);      // 함수들의 전방 선언
void input_num();

int main(void)
{
    input_num();                 // input_num 함수 호출 (사용자 입력 → 배열 채우기 → 출력)

    return 0;                    // 프로그램 정상 종료
}

// 2차원 배열을 1차원 포인터로 받아서 모든 원소를 동일한 값으로 채우는 함수
void fill_2d_array(int* p, int row, int value)
{
    int i, j;                    // 반복문용 변수 선언

    for (i = 0; i < row; i++)    // row(4행)만큼 반복
    {
        for (j = 0; j < 5; j++, p++)
            // 2차원 배열을 1차원처럼 포인터로 접근
            // j < 5 → 열 개수 고정 (5열)
            // p++ → 다음 int 원소로 포인터 이동
        {
            *p = value;          // 현재 원소에 value 저장
        }
    }
}

void input_num()
{
    int arr[4][5];              // 4행 5열의 2차원 배열 선언
    int value, i, j;            // 입력값과 반복문 변수 선언
    int (*p)[5] = arr;          // p는 '5개짜리 int 배열'을 가리키는 포인터
    // 즉, arr의 첫 번째 행 주소를 가리킴

    printf("배열의 원소에 저장할 값? ");
    scanf("%d", &value);        // 사용자에게 저장할 값을 입력받음

    fill_2d_array(*p, 4, value);
    // *p는 arr[0]과 동일 → int* 타입
    // 행 개수: 4행
    // value: 입력값
    // 2차원 배열 전체를 value로 채움

    // 채워진 배열 출력
    for (i = 0; i < 4; i++)     // 4행 반복
    {
        for (j = 0; j < 5; j++) // 5열 반복
        {
            printf("%d ", arr[i][j]); // 현재 원소 출력
        }
        printf("\n");           // 한 행 출력 후 줄바꿈
    }
}