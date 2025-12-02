// 등비수열, 점화식 방식과 일반항 방식, 두 가지로 출력해서 비교

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// 이 함수는 1, 2, 4, 8 처럼 두 배가 되면서 나오는 수를 출력함
void print_geometric_sequence_recursive(int n) 
{
    printf("점화식\n");

    int current_term = 1; // 처음 수는 1(초기화)

    if (n >= 1) 
    {
        printf("%d", current_term); // 첫 번째 수를 출력해요
    }

    // 두 번째 수부터는 앞에 나온 수에 2를 곱해요
    for (int i = 2; i <= n; i++) 
    {
        current_term = current_term * 2; // 앞 수의 두 배 만들기
        printf(" %d", current_term);    // 만든 수 출력하기
    }
    printf("\n");
}

// 이 함수는 규칙(2의 제곱)을 이용해서 수를 계산
void print_geometric_sequence_general(int n) 
{
    printf("일반항\n");

    // i번째 수는 2^(i-1)이에요
    for (int i = 1; i <= n; i++)
    {
        int term = 1 << (i - 1); // 2를 여러 번 곱한 값 만들기
        printf("%d", term);      // 만든 수 출력하기

        if (i < n)
        {
            printf(" "); // 띄어쓰기
        }
    }
    printf("\n");
}

int main(void)
{
    int num_of_terms;

    printf("출력할 개수를 입력하세요 > ");
    scanf("%d", &num_of_terms); // 몇 개를 출력할지 숫자를 입력받아요

    print_geometric_sequence_recursive(num_of_terms);
    print_geometric_sequence_general(num_of_terms);

    return 0;
}