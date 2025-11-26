/*
    학번 : 202511204
    이름 : 강기민
    프로그램 명 : 11. 영어 단어 끝말잇기 게임
    날짜 : 2025.11.26
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 함수 프로토타입 선언
void test(void);
int is_chain_ok(const char* prev, const char* curr);
void to_lower_str(char* s);

/*
    기능명: main. 프로그램 시작점
    내용: 테스트 함수를 호출하여 끝말잇기 게임을 실행한다.
    입력: 없음
    출력: 없음
    오류: 없음
*/
int main(void)
{
    test(); // 끝말잇기 게임 테스트 함수 호출
    return 0;
}

/*
    기능명: test. 테스트 코드
    내용: 사용자가 단어를 반복해서 입력하도록 하고,
          첫 단어 이후부터는 끝말잇기 규칙을 검사한다.
          길이가 3 미만인 단어는 다시 입력받고,
          규칙을 어기면 실패 메시지와 연속 성공 횟수를 출력한 뒤 종료한다.
    입력: "word? " 프롬프트로 단어를 반복 입력받는다.
    출력: 잘못된 단어 입력 시 실패 메시지와 연속 성공 횟수 출력.
    오류: 단어 입력에 실패하면 함수 즉시 종료.
*/
void test(void)
{
    char prev[101] = ""; // 이전에 입력한 단어를 저장할 배열, 처음에는 빈 문자열
    char curr[101]; // 현재 입력받은 단어를 저장할 배열
    int  count; // 규칙을 지키며 연속으로 맞춘 단어 개수
    int  ok; // 입력 성공 여부

    count = 0; // 아직 맞춘 단어가 없으므로 0으로 초기화

    while (1)
    {
        printf("word? ");
        // 최대 100글자까지 단어 입력, 공간 확보를 위해 sizeof 대신 _countof 사용
        ok = scanf_s("%100s", curr, (unsigned)_countof(curr));
        if (ok != 1) // 입력에 실패한 경우
        {
            return; // 더 이상 진행하지 않고 함수 종료
        }

        // 단어 길이가 3 미만이면 게임 규칙상 다시 입력받는다.
        if ((int)strlen(curr) < 3)
        {
            printf("too short, try again\n");
            continue; // 카운트 증가 없이 다음 반복으로 넘어간다.
        }

        // 대소문자 구분 없이 비교하기 위해 현재 단어를 모두 소문자로 변환
        to_lower_str(curr);

        // 첫 번째 단어인 경우에는 이전 단어가 없으므로 규칙 검사 없이 통과
        if (count == 0)
        {
            // prev에 현재 단어를 복사하고 카운트 증가
            strcpy_s(prev, sizeof(prev), curr);
            count++;
            continue;
        }

        // 그 다음부터는 이전 단어와 현재 단어가 끝말잇기 규칙을 만족하는지 검사
        if (is_chain_ok(prev, curr))
        {
            // 규칙을 만족하면 현재 단어를 prev에 저장하고 카운트 증가
            strcpy_s(prev, sizeof(prev), curr);
            count++;
        }
        else
        {
            // 규칙을 지키지 못한 경우 실패 메시지와 연속 성공 횟수 출력 후 종료
            printf("WRONG WORD!!! YOU FAILED!!!\n");
            printf("count: %d\n", count);
            break;
        }
    }
}

/*
    기능명: is_chain_ok. 끝말잇기 규칙 검사
    내용: 이전 단어 prev의 마지막 문자와 현재 단어 curr의 첫 문자가 같은지 검사한다.
          두 문자가 같으면 끝말잇기 규칙을 지킨 것으로 판단한다.
    입력: const char* prev - 이전 단어를 가리키는 포인터
          const char* curr - 현재 단어를 가리키는 포인터
    출력: 규칙이 맞으면 1, 규칙을 어기면 0을 반환한다.
    오류: 없음 (문자열이 정상적으로 끝난다고 가정)
*/
int is_chain_ok(const char* prev, const char* curr)
{
    char last; // 이전 단어의 마지막 문자
    char first; // 현재 단어의 첫 문자

    // prev 길이의 마지막 인덱스에 있는 문자가 마지막 문자
    last = prev[strlen(prev) - 1];
    // curr의 첫 문자는 인덱스 0 위치
    first = curr[0];

    if (last == first)
    {
        // 두 문자가 같으면 규칙을 지킨 것
        return 1;
    }
    else
    {
        // 다르면 규칙을 어긴 것
        return 0;
    }
}

/*
    기능명: to_lower_str. 소문자 변환
    내용: 전달받은 문자열의 모든 문자에 대해 알파벳인 경우 소문자로 바꾼다.
          영문 대소문자를 구분하지 않고 비교하기 위한 전처리용 함수이다.
    입력: char* s  변환할 문자열의 주소
    출력: 없음 (문자열이 직접 변경된다)
    오류: 없음
*/
void to_lower_str(char* s)
{
    int i;

    // 문자열 끝의 널 문자 전까지 반복
    for (i = 0; s[i] != '\0'; i++)
    {
        // tolower는 int를 받고 int를 반환하므로 캐스팅하여 저장
        s[i] = (char)tolower((unsigned char)s[i]);
    }
}
