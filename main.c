// game created by LuminousKadupul 

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

int main() {
    // настройка окна
    system("title InfiniteSpheres");
    system("mode con:cols=31 lines=13");

    // данные для взаимодействия
    char location[10][21];
    short i;
    short x = 10, y = 5;
    char key;
    short ox, oy;
    short ax = 5, ay = 3;
    long counter = 0;

    // рандомизация
    srand(time(NULL));

    // начало
    system("cls");
    printf("Turn on the English keyboard\nlayout.\n");
    printf("\nControl\nE - exit the game\nWASD - movement");
    printf("\n\n\n\n\n\n\nby LuminousKadupul");
    sleep(5);
    system("cls");

    // игра
    do {
        system("cls");

        // границы карты
        sprintf(location[0], "####################");
        for(i = 1; i < 9; i++) {
            sprintf(location[i], "#                  #");
        }
        sprintf(location[9], "####################");

        // объекты
        location[y][x] = '@';
        location[ay][ax] = 'o';

        // отображение карты и интерфейса
        for(i = 0; i < 10; i++) {
            printf("%s\n", location[i]);
        }
        printf("\nCollected spheres: %d\n", counter);

        // управление
        ox = x;
        oy = y;
        key = getch();
        if(key == 'w') y--;
        if(key == 's') y++;
        if(key == 'a') x--;
        if(key == 'd') x++;
        if(location[y][x] == '#') {
            x = ox;
            y = oy;
        }
        // сферы
        if(x == ax && y == ay) {
            counter++;
            ax = rand() * 1.0 / RAND_MAX * 18 + 1;
            ay = rand() * 1.0 / RAND_MAX * 8 + 1;
        }
    } while(key != 'e');

    return 0;
}