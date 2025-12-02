#include <stdio.h>
#include <string.h>
#include <ctype.h>

void test(void);
int chain_ok(char a[], char b[]);
void to_lower(char s[]);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    char a[101] = "";
    char b[101];
    int count;
    int ok;

    count = 0;

    while (1)
    {
        printf("word? ");
        ok = scanf_s("%100s", b, sizeof(b));
        if (ok != 1)
        {
            return;
        }

        if (strlen(b) < 3)
        {
            printf("too short, try again\n");
            continue;
        }

        to_lower(b);

        if (count == 0)
        {
            strcpy_s(a, sizeof(a), b);
            count++;
            continue;
        }

        if (chain_ok(a, b))
        {
            strcpy_s(a, sizeof(a), b);
            count++;
        }
        else
        {
            printf("WRONG WORD!!! YOU FAILED!!!\n");
            printf("count: %d\n", count);
            break;
        }
    }
}

int chain_ok(char a[], char b[])
{
    char last;
    char first;

    last = a[strlen(a) - 1];
    first = b[0];

    if (last == first)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void to_lower(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        s[i] = tolower(s[i]);
    }
}
