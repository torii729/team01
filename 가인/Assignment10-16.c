/*
    음원 사이트에 등록된 노래 정보를 관리하기 위한 프로그램을 작성하시오.
    노래마다 곡명, 가수, 장르, 재생시간을 저장할 수 있게 SONG 구조체를 정의한다.
    장르는 열거체와 열거 상수를 이용해서 나타내시오. SONG 구조체 배열을 선언하고 적절히 초기화한 다음 전체 노래 목록을 장르별로
    출력하는 프로그램을 작성하시오.
*/

#include <stdio.h> // printf 같은 입출력 함수 사용을 위해 포함
#include <string.h> // 문자열 관련 함수 사용을 위해 포함 (여기서는 예비용)

typedef enum 
{
    BALLAD, // 열거형 GENRE의 값: 발라드
    DANCE, // 댄스
    HIPHOP, // 힙합
    ROCK, // 록
    POP // 팝
} GENRE; // 음악 장르를 표현하는 열거형 타입 정의

// SONG 구조체 선언: 하나의 노래 정보를 묶어서 저장
typedef struct 
{
    char title[50]; // 곡 제목 문자열
    char artist[50]; // 가수 이름 문자열
    GENRE genre; // 열거형 타입으로 장르 저장
    int playTime; // 재생 시간(초 단위)
} SONG;

// 열거형 값을 다시 문자(문자열)로 바꿔주는 함수
const char* getGenreName(GENRE g) 
{
    switch (g) // g 값에 따라 실행될 코드 선택
    {                   
    case BALLAD:
        return "ballad"; // 발라드일 때 문자열 반환
    case DANCE: 
        return "dance";
    case HIPHOP:
        return "hiphop";
    case ROCK:
        return "rock";
    case POP:
        return "pop";
    default: 
        return "unknown"; // 예외 처리
    }
}

int main()
{
    // 구조체 배열로 여러 곡 정보를 한번에 저장
    SONG songs[] = {
        {"별 보러 가자", "박보검", BALLAD, 316}, // 구조체 1개 초기화
        {"아이유 - Love Poem", "아이유", BALLAD, 242}, // 구조체 2
        {"Next Level", "aespa", DANCE, 221}, // 구조체 3
        {"그날들", "장범준", BALLAD, 298}, // 구조체 4
        {"Dynamite", "BTS", POP, 199}, // 구조체 5
        {"ON", "BTS", HIPHOP, 300}, // 구조체 6
    };

    int size = sizeof(songs) / sizeof(songs[0]); // 배열 요소 개수 구하기

    // 표의 헤더(제목 줄) 출력
    printf("제목                   아티스트              장르            재생시간\n");
    printf("---------------------------------------------------------------------\n");

    // 배열에 있는 모든 곡 정보를 반복문으로 출력
    for (int i = 0; i < size; i++)
    {
        printf("%-20s %-20s %-10s %d초\n", // 정렬 형식 지정 (%-20s 등)
            songs[i].title, // 곡 제목 출력
            songs[i].artist, // 아티스트 이름 출력
            getGenreName(songs[i].genre), // 장르(문자열 형태) 출력
            songs[i].playTime // 재생시간 출력
        );
    }

    return 0;   // 프로그램 정상 종료
}