/*
    인터넷 사이트에 로그인할 때 사용되는 아이디와 패스워드를 관리하기 위한 LOCIN 구조체를 정의하시오 아이디와 패스워드는 각각 최대 20글자까지 입력할 수 있다.
    LOGIN 구조체 변수를 선언한 다음 아이디와 패스워드를 입력받아 저장하고 출력하는 프로그램을 작성하시오. 패스워드를 출력할 때는 패스워드의 내용 은보이지 않도록 패스워드글자 수만큼 *을 대신 출력하시오
*/

#include <stdio.h>
#include <string.h>

#define MAX 21 

typedef struct {
    char id[MAX];
    char pw[MAX];
} LOGIN;

int main() {
    LOGIN user;

    printf("ID? ");
    scanf_s("%20s", user.id, 21);

    printf("Password? ");
    scanf_s("%20s", user.pw, 21);
    printf("\nID: %s\n", user.id);

    printf("PW: ");
    for (int i = 0; user.pw[i] != '\0'; i++) {
        printf("*");
    }
    printf("\n");

    return 0;
}