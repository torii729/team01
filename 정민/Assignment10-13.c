#include <stdio.h>

typedef struct point {
    int x;
    int y;
} POINT;

typedef struct rect {
    POINT left_bottom;
    POINT right_top;
} RECT;

void print_rect(RECT r) {
    printf("[RECT 좌하단점: (%d, %d) 우상단점: (%d, %d)]\n",
        r.left_bottom.x, r.left_bottom.y,
        r.right_top.x, r.right_top.y
    );
}


int main(void) {
    RECT my_rect;

    printf("사각형의 좌하단점(x, y)? ");
    if (scanf_s("%d %d", &my_rect.left_bottom.x, &my_rect.left_bottom.y) != 2) {
        printf("입력 오류가 발생했습니다.\n");
        return 1;
    }

    printf("사각형의 우상단점(x, y)? ");
    if (scanf_s("%d %d", &my_rect.right_top.x, &my_rect.right_top.y) != 2) {
        printf("입력 오류가 발생했습니다.\n");
        return 1;
    }

    print_rect(my_rect);

    return 0;
}