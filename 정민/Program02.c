#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void print_geometric_sequence_recursive(int n)
{
    printf("점화식\n");

    int current_term = 1;

    if (n >= 1)
    {
        printf("%d", current_term);
    }

    for (int i = 2; i <= n; i++)
    {
        current_term = current_term * 2;
        printf(" %d", current_term);
    }
    printf("\n");
}

void print_geometric_sequence_general(int n)
{
    printf("일반항\n");

    for (int i = 1; i <= n; i++)
    {
        int term = 1 << (i - 1);
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

    printf("출력할 개수를 입력하세요 > ");
    scanf("%d", &num_of_terms);

    print_geometric_sequence_recursive(num_of_terms);
    print_geometric_sequence_general(num_of_terms);

    return 0;
}
