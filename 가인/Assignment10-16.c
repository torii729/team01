#include <stdio.h>
#include <string.h>

typedef enum
{
    BALLAD,
    DANCE,
    HIPHOP,
    ROCK,
    POP
} GENRE;

typedef struct
{
    char title[50];
    char artist[50];
    GENRE genre;
    int playTime;
} SONG;

const char* getGenreName(GENRE g)
{
    switch (g)
    {
    case BALLAD:
        return "ballad";
    case DANCE:
        return "dance";
    case HIPHOP:
        return "hiphop";
    case ROCK:
        return "rock";
    case POP:
        return "pop";
    default:
        return "unknown";
    }
}

int main()
{
    SONG songs[] = {
        {"별 보러 가자", "박보검", BALLAD, 316},
        {"아이유 - Love Poem", "아이유", BALLAD, 242},
        {"Next Level", "aespa", DANCE, 221},
        {"그날들", "장범준", BALLAD, 298},
        {"Dynamite", "BTS", POP, 199},
        {"ON", "BTS", HIPHOP, 300},
    };

    int size = sizeof(songs) / sizeof(songs[0]);

    printf("제목                   아티스트              장르            재생시간\n");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < size; i++)
    {
        printf("%-20s %-20s %-10s %d초\n",
            songs[i].title,
            songs[i].artist,
            getGenreName(songs[i].genre),
            songs[i].playTime
        );
    }

    return 0;
}
