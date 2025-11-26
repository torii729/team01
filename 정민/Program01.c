#include <stdio.h>

// 이 함수는 1, 3, 5, 7처럼
// 앞의 수에 2를 더해서 만드는 수를 출력해요
void print_arithmetic_sequence_recursive(int n) {
    printf("점화식\n");
    int current_term = 1; // 처음 수는 1

    // n이 1 이상이면 첫 번째 수를 출력해요
    if (n >= 1)
    {
        printf("%d", current_term);
    }

    // 두 번째 수부터는 앞의 수에 2를 더해서 만들고 출력하는 프로그램
    for (int i = 2; i <= n; i++)
    {
        current_term = current_term + 2;
        printf(" %d", current_term);
    }
    printf("\n");
}

// 1, 3, 5처럼 바로 계산해서 출력해요
void print_arithmetic_sequence_general(int n) {
    printf("일반항\n");
    int term;

    // i번째 수는 (2 * i - 1)이라는 규칙을 써요
    for (int i = 1; i <= n; i++)
    {
        term = 2 * i - 1;  // 규칙으로 숫자 만들기
        printf("%d", term); // 만든 숫자 출력

        if (i < n)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void) {
    int num_of_terms;

    printf("출력 항의 개수 입력 후 Enter>");//몇개으 숫자를 출력 받을지 입력받음


    // 숫자를 제대로 입력했는지 확인하고 아니면 오류 메세지 출력함.
    if (scanf_s("%d", &num_of_terms) != 1) {
        printf("잘못된 입력입니다.\n");
        return 1; // 프로그램 끝내기
    }

    // 두 배가 아닌, 2씩 더해서 만드는 방식으로 출력하는 함수
    print_arithmetic_sequence_recursive(num_of_terms);

    // 규칙으로 바로 계산해서 출력하는 함수
    print_arithmetic_sequence_general(num_of_terms);

    return 0; // 프로그램 끝!
}