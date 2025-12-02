#include <stdio.h>
#include <ctype.h>
#include <string.h>

void input_str(void);
int strcmp_ic(const char* lhs, const char* rhs);
void print_result(int result, const char* s1, const char* s2);

int main(void)
{
    input_str();
    return 0;
}

void input_str(void)
{
    char str1[100];
    char str2[100];
    char* pos;

    printf("첫 번째 문자열? ");
    fgets(str1, sizeof(str1), stdin);

    pos = strchr(str1, '\n');
    if (pos) *pos = '\0';

    printf("두 번째 문자열? ");
    fgets(str2, sizeof(str2), stdin);

    pos = strchr(str2, '\n');
    if (pos) *pos = '\0';

    int result = strcmp_ic(str1, str2);

    print_result(result, str1, str2);
}

int strcmp_ic(const char* lhs, const char* rhs)
{
    while (*lhs && *rhs)
    {
        char c1 = tolower((unsigned char)*lhs);
        char c2 = tolower((unsigned char)*rhs);

        if (c1 != c2)
        {
            return c1 - c2;
        }

        lhs++;
        rhs++;
    }

    if (*lhs == '\0' && *rhs == '\0')
        return 0;
    else if (*lhs == '\0')
        return -1;
    else
        return 1;
}

void print_result(int result, const char* s1, const char* s2)
{
    if (result == 0)
        printf("%s와 %s가 같습니다.\n", s1, s2);
    else if (result > 0)
        printf("%s가 %s보다 큽니다.\n", s1, s2);
    else
        printf("%s가 %s보다 작습니다.\n", s1, s2);
}
