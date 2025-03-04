#include "MyMenu/MyMenu.h"

#include <iostream>
#include <cmath>
#include <string>

using namespace std;
using namespace KDM;

#pragma region функции
int f1() {
    cout << "Здравствуй, пользователь!" << endl;
    return 1;
}

int f2() {
    cout << "Логарифм 100: \t" << log(100) << endl;
    return 2;
}

int f3() {
    cout << "Хорошего дня!" << endl;
    return 3;
}

int f4() {
    cout << "Корень из 25: \t" << sqrt(25) << endl;
    return 4;
}
int f5() {
    cout << "ЗАПУСКАЕМ ГУСЕЙ РАЗВЕДЧИКОВ" << endl;
    cout << "░░░░░▄▀▀▀▄░░░▄▀▀▀▀▄░░░▄▀▀▀▄░░░░░" << endl;
    cout << "▄███▀░◐░░░▌░▐0░░░░0▌░▐░░░◐░▀██" << endl;
    cout << "░░░░▌░░░░░▐░▌░▐▀▀▌░▐░▌░░░░░▐░░░░" << endl;
    cout << "░░░░▐░░░░░▐░▌░▌▒▒▐░▐░▌░░░░░▌░░░░" << endl;
    return 5;
}

int f0() {
    cout << "Работа программы завершена" << endl;
    return 0;
}

#pragma endregion

const int ITEMS_NUMBER = 6;


int main() {

    MenuItem items[ITEMS_NUMBER] {
        MenuItem{"Поздороваться с пользователем", f1}, 
        MenuItem{"Вычислить логарифм 100", f2}, 
        MenuItem{"Попрощаться с пользователем", f3}, 
        MenuItem{"Вычислить корень из 25", f4}, 
        MenuItem{"Запустить гуся", f5}, 
        MenuItem{"Выход", f0}
        };
    MyMenu menu("Меню", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};

    return 0;
}