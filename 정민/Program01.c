#include <stdio.h>

void print_arithmetic_sequence_recursive(int n)
{
    printf("점화식\n");
    int current_term = 1;

    if (n >= 1)
    {
        printf("%d", current_term);
    }

    for (int i = 2; i <= n; i++)
    {
        current_term = current_term + 2;
        printf(" %d", current_term);
    }
    printf("\n");
}

void print_arithmetic_sequence_general(int n) 
{
    printf("일반항\n");
    int term;

    for (int i = 1; i <= n; i++)
    {
        term = 2 * i - 1;
        printf("%d", term);

        if (i < n)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void)
{
    int num_of_terms;

    printf("출력 항의 개수 입력 후 Enter>");

    if (scanf_s("%d", &num_of_terms) != 1) 
    {
        printf("잘못된 입력입니다.\n");
        return 1;
    }

    print_arithmetic_sequence_recursive(num_of_terms);
    print_arithmetic_sequence_general(num_of_terms);

    return 0;