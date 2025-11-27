/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 4. 아이디와 패스워드가 저장된 텍스트 파일을 크기가 10인 LOGIN 구조체 배열로 읽어 온 다음,
        입력 받은 아이디와 패스워드가 일치하면 "로그인 성공" 아니면 "로그인 실패"라고 출력하는 프로그램을 작성하시오.
    날짜 : 2025.11.26
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_LOGIN 10 // LOGIN 구조체 배열의 최대 원소 수
#define MAX_LEN 20 // 아이디와 패스워드 문자열의 최대 길이

// 로그인 정보를 저장하는 구조체
typedef struct LOGIN
{
    char id[MAX_LEN]; // 사용자 아이디
    char password[MAX_LEN]; // 사용자 패스워드
} LOGIN;

// 함수 프로토타입 선언
void test(void);
void load_file(char filename[], LOGIN logins[], int* pCount); // 파일에서 읽어 온 개수를 pCount가 가리키는 변수에 넣는다
int  find_index(LOGIN logins[], int count, char id[]); // 아이디가 몇 번째에 있는지 찾는다
int  check_password(LOGIN login, char password[]); // login 안의 비밀번호와 입력된 비밀번호가 같은지 확인한다

/*
    기능명: main. 프로그램 시작점
    내용: test 함수를 호출해서 로그인 기능을 실행한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
int main(void)
{
    test(); // 로그인 기능 테스트 함수 호출
    return 0;
}

/*
    기능명: test. 테스트 코드
    내용: 텍스트 파일에서 로그인 정보를 읽어 온 뒤
          사용자에게 ID와 Password를 입력받아서 로그인 결과를 출력한다.
    입력: 콘솔에서 ID와 Password를 입력받는다.
    출력: 로그인 성공인지 실패인지 출력한다.
    오류: 파일 읽기 실패나 입력 실패 시 안내 메시지를 출력하고 종료한다.
*/
void test(void)
{
    LOGIN logins[MAX_LOGIN]; // 파일에서 읽어 온 로그인 정보를 저장할 배열
    int count = 0; // 실제로 읽어 온 로그인 정보 개수. load_logins_from_file 안에서 값이 바뀐다
    char id[MAX_LEN]; // 사용자로부터 입력받을 아이디
    char password[MAX_LEN]; // 사용자로부터 입력받을 패스워드
    int index; // 아이디가 있는 위치의 인덱스

    // password.txt 파일에서 로그인 정보를 읽어 온다. 읽은 개수는 count에 채워진다
    load_file("password.txt", logins, &count);

    // 파일에서 아무 것도 읽지 못한 경우 (count가 0으로 남아 있을 때)
    if (count == 0)
    {
        printf("로그인 정보를 읽지 못했습니다.\n");
        return;
    }

    // 아이디 입력 요청
    printf("ID? ");
    // 문자열을 하나도 못 읽으면 입력 오류
    if (scanf_s("%19s", id, MAX_LEN) != 1)
    {
        printf("ID를 읽을 수 없습니다.\n");
        return;
    }

    // 로그인 정보 배열에서 입력받은 아이디가 있는지 검색
    index = find_index(logins, count, id);

    // 아이디를 찾지 못한 경우
    if (index == -1)
    {
        printf("아이디를 찾을 수 없습니다.\n");
        return;
    }

    // 패스워드 입력 요청
    printf("Password? ");
    // 패스워드를 하나도 못 읽으면 입력 오류
    if (scanf_s("%19s", password, MAX_LEN) != 1)
    {
        printf("Password를 읽을 수 없습니다.\n");
        return;
    }

    // 찾은 로그인 정보와 입력받은 패스워드를 비교
    if (check_password(logins[index], password))
    {
        printf("로그인 성공\n");
    }
    else
    {
        printf("로그인 실패\n");
    }
}

/*
    기능명: load_file. 로그인 정보 읽기
    내용: 지정한 텍스트 파일을 열어서
          아이디와 패스워드를 LOGIN 구조체 배열에 최대 10개까지 저장한다.
          몇 개를 읽었는지는 pCount가 가리키는 변수에 넣어 준다.
    입력: 파일 이름, LOGIN 배열, 읽은 개수를 넣어 줄 변수의 주소
    출력: logins 배열이 채워지고, pCount가 가리키는 변수에 개수가 저장된다.
    오류: 파일을 못 열면 pCount가 가리키는 변수에 0을 넣고 오류 메시지를 출력한다.
*/
void load_file(char filename[], LOGIN logins[], int* pCount)
{
    FILE* fp;
    int i = 0; // 지금까지 읽은 로그인 정보 개수

    // 텍스트 파일을 읽기 모드로 연다
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        *pCount = 0; // 호출한 쪽의 count 변수에 0을 넣어서 "하나도 못 읽었다"는 것을 알린다
        return;
    }

    // 아이디와 패스워드를 한 쌍씩 읽어서 배열에 저장
    while (i < MAX_LOGIN &&
        fscanf_s(fp, "%19s %19s",
            logins[i].id, MAX_LEN,
            logins[i].password, MAX_LEN) == 2)
    {
        i++; // 한 줄 읽을 때마다 개수 증가
    }

    // 실제로 읽은 개수를 호출한 쪽의 count 변수에 넣어 준다
    *pCount = i;

    fclose(fp); // 파일 닫기
}

/*
    기능명: find_index. 아이디 검색
    내용: LOGIN 배열에서 주어진 아이디와 같은 아이디를 찾아 인덱스를 돌려준다.
    입력: LOGIN 배열, 배열에 저장된 개수, 찾고 싶은 아이디
    출력: 찾으면 그 인덱스, 못 찾으면 -1을 반환한다.
    오류: 없음
*/
int find_index(LOGIN logins[], int count, char id[])
{
    int i;
    // 0번부터 순서대로 검색
    for (i = 0; i < count; i++)
    {
        if (strcmp(logins[i].id, id) == 0) // 아이디가 같으면
        {
            return i; // 그 인덱스를 바로 반환
        }
    }
    // 끝까지 봤는데도 없으면 -1
    return -1;
}

/*
    기능명: check_password. 패스워드 비교
    내용: LOGIN 하나에 들어 있는 패스워드와
          사용자가 입력한 패스워드가 같은지 확인한다.
    입력: LOGIN 구조체 하나, 입력된 패스워드 문자열
    출력: 같으면 1, 다르면 0을 반환한다.
    오류: 없음
*/
int check_password(LOGIN login, char password[])
{
    if (strcmp(login.password, password) == 0) // 두 문자열이 같으면
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
