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
#define MAX_LEN   20 // 아이디와 패스워드 문자열의 최대 길이

// 로그인 정보를 저장하는 구조체
typedef struct LOGIN
{
    char id[MAX_LEN]; // 사용자 아이디
    char password[MAX_LEN]; // 사용자 패스워드
} LOGIN;

// 함수 프로토타입 선언
void test(void);
void load_logins_from_file(const char* filename, LOGIN logins[], int* pCount);
int  find_login_index(const LOGIN logins[], int count, const char* id);
int  check_password(const LOGIN* login, const char* password);


/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 로그인 기능을 실행한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
int main(void)
{
    // 로그인 기능 테스트 함수 호출
    test();
    return 0;
}

/*
    기능명: test. 테스트 코드
    내용: 텍스트 파일에서 로그인 정보를 읽어 온 뒤,
          사용자에게 ID와 Password를 입력받아 로그인 결과를 출력한다.
    입력: 콘솔에서 ID와 Password 문자열을 입력받는다.
    출력: 로그인 성공 여부를 콘솔에 출력한다.
    오류: 파일 읽기 실패나 입력 실패 시 오류 메시지를 출력한다.
*/
void test(void)
{
    LOGIN logins[MAX_LOGIN]; // 파일에서 읽어 온 로그인 정보를 저장할 배열
    int count = 0; // 실제로 읽어 온 로그인 정보의 개수
    char id[MAX_LEN]; // 사용자로부터 입력받을 아이디
    char password[MAX_LEN]; // 사용자로부터 입력받을 패스워드
    int index; // 아이디가 있는 위치의 인덱스

    // password.txt 파일에서 로그인 정보를 읽어 온다.
    load_logins_from_file("password.txt", logins, &count);

    // 파일에서 아무 것도 읽지 못한 경우 예외 처리
    if (count == 0)
    {
        printf("로그인 정보를 읽지 못했습니다.\n");
        return;
    }

    // 아이디 입력 요청
    printf("ID? ");
    // 문자열 입력이 1개도 제대로 읽히지 않은 경우 입력 오류 처리
    if (scanf_s("%s", id, (unsigned int)sizeof(id)) != 1)
    {
        printf("ID를 읽을 수 없습니다.\n");
        return;
    }

    // 로그인 정보 배열에서 입력받은 아이디가 있는지 검색
    index = find_login_index(logins, count, id);

    // 아이디를 찾지 못한 경우
    if (index == -1)
    {
        printf("아이디를 찾을 수 없습니다.\n");
        return;
    }

    // 패스워드 입력 요청
    printf("Password? ");
    // 패스워드 입력 실패 시 예외 처리
    if (scanf_s("%s", password, (unsigned int)sizeof(password)) != 1)
    {
        printf("Password를 읽을 수 없습니다.\n");
        return;
    }

    // 찾은 로그인 정보와 입력받은 패스워드를 비교
    if (check_password(&logins[index], password))
    {
        // 패스워드가 일치하는 경우
        printf("로그인 성공\n");
    }
    else
    {
        // 패스워드가 일치하지 않는 경우
        printf("로그인 실패\n");
    }
}

/*
    기능명: load_logins_from_file. 로그인 정보 읽기
    내용: 지정한 텍스트 파일을 열어 아이디와 패스워드를
          LOGIN 구조체 배열에 최대 10개까지 저장한다.
    입력: 파일 이름 문자열, LOGIN 배열, 실제로 읽은 개수를 돌려줄 정수 포인터.
    출력: 배열에 로그인 정보가 채워지고, 읽은 개수가 pCount에 저장된다.
    오류: 파일을 열 수 없으면 개수를 0으로 설정하고 오류 메시지를 출력한다.
*/
void load_logins_from_file(const char* filename, LOGIN logins[], int* pCount)
{
    FILE* fp;
    int i = 0; // 현재까지 읽은 로그인 정보의 개수 인덱스

    // 텍스트 파일을 읽기 모드로 연다.
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        // 파일 포인터가 NULL이면 파일 열기 실패
        printf("파일을 열 수 없습니다.\n");
        *pCount = 0; // 아무 것도 읽지 못했음을 표시
        return;
    }

    // 아이디와 패스워드를 한 쌍씩 읽어서 배열에 저장
    // fscanf_s가 두 개의 문자열을 모두 성공적으로 읽었을 때만 i를 증가
    while (i < MAX_LOGIN &&
        fscanf_s(fp, "%s %s",
            logins[i].id, (unsigned int)sizeof(logins[i].id),
            logins[i].password, (unsigned int)sizeof(logins[i].password)) == 2)
    {
        // 한 줄의 "아이디 패스워드" 읽기 성공
        i++;
    }

    // 실제로 읽은 로그인 정보의 개수를 호출한 쪽에 전달
    *pCount = i;

    // 파일 닫기
    fclose(fp);
}

/*
    기능명: find_login_index. 아이디 검색
    내용: LOGIN 구조체 배열에서 주어진 아이디와 일치하는 요소의 인덱스를 찾는다.
    입력: LOGIN 배열, 배열에 저장된 개수, 찾고자 하는 아이디 문자열.
    출력: 찾은 경우 해당 인덱스(0 이상), 찾지 못한 경우 -1을 반환한다.
    오류: 없음
*/
int find_login_index(const LOGIN logins[], int count, const char* id)
{
    int i;
    // 0번 인덱스부터 차례대로 선형 탐색
    for (i = 0; i < count; i++)
    {
        // 현재 원소의 id와 찾고자 하는 id가 같은지 비교
        if (strcmp(logins[i].id, id) == 0)
        {
            // 동일한 아이디를 찾으면 해당 인덱스를 반환
            return i;
        }
    }
    // 끝까지 탐색했지만 찾지 못한 경우 -1 반환
    return -1;
}

/*
    기능명: check_password. 패스워드 비교
    내용: 하나의 LOGIN 구조체에 저장된 패스워드와 입력된 패스워드가 같은지 비교한다.
    입력: LOGIN 구조체 포인터, 입력된 패스워드 문자열.
    출력: 같으면 1, 다르면 0을 반환한다.
    오류: 없음
*/
int check_password(const LOGIN* login, const char* password)
{
    // 구조체 안의 password와 입력된 password가 같은지 문자열 비교
    if (strcmp(login->password, password) == 0)
    {
        // 같으면 참 의미의 1 반환
        return 1;
    }
    else
    {
        // 다르면 거짓 의미의 0 반환
        return 0;
    }
}
