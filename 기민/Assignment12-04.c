#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LOGIN 10
#define MAX_LEN 20

typedef struct LOGIN
{
    char id[MAX_LEN];
    char password[MAX_LEN];
} LOGIN;

void test(void);
void load_file(char filename[], LOGIN logins[], int* pCount);
int  find_index(LOGIN logins[], int count, char id[]);
int  check_password(LOGIN login, char password[]);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    LOGIN logins[MAX_LOGIN];
    int count = 0;
    char id[MAX_LEN];
    char password[MAX_LEN];
    int index;

    load_file("password.txt", logins, &count);

    if (count == 0)
    {
        printf("로그인 정보를 읽지 못했습니다.\n");
        return;
    }

    printf("ID? ");
    if (scanf_s("%19s", id, MAX_LEN) != 1)
    {
        printf("ID를 읽을 수 없습니다.\n");
        return;
    }

    index = find_index(logins, count, id);

    if (index == -1)
    {
        printf("아이디를 찾을 수 없습니다.\n");
        return;
    }

    printf("Password? ");
    if (scanf_s("%19s", password, MAX_LEN) != 1)
    {
        printf("Password를 읽을 수 없습니다.\n");
        return;
    }

    if (check_password(logins[index], password))
    {
        printf("로그인 성공\n");
    }
    else
    {
        printf("로그인 실패\n");
    }
}

void load_file(char filename[], LOGIN logins[], int* pCount)
{
    FILE* fp;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        *pCount = 0;
        return;
    }

    while (i < MAX_LOGIN &&
        fscanf_s(fp, "%19s %19s",
            logins[i].id, MAX_LEN,
            logins[i].password, MAX_LEN) == 2)
    {
        i++;
    }

    *pCount = i;

    fclose(fp);
}

int find_index(LOGIN logins[], int count, char id[])
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(logins[i].id, id) == 0)
        {
            return i;
        }
    }

    return -1;
}

int check_password(LOGIN login, char password[])
{
    if (strcmp(login.password, password) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
