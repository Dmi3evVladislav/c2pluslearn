#include "menu/CMenu.h"
#include "menu/CMenuItem.h"

using namespace std;


#pragma region функции-заглушки
int f1() {
    std::cout << "function f1 is running...\n\n";
    return 1;
}

int f2() {
    std::cout << "function f2 is running...\n\n";
    return 2;
}

int f3() {
    std::cout << "function f3 is running...\n\n";
    return 3;
}
#pragma endregion

const int ITEMS_NUMBER = 3;


int main() {
    CMenuItem items[ITEMS_NUMBER] {CMenuItem{"first item", f1}, CMenuItem{"second item", f2}, CMenuItem{"third item", f3}};
    CMenu menu("My console menu", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};

    return 0;
}