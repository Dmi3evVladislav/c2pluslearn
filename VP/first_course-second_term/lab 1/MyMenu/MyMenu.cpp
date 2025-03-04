#include <iostream>
#include "./MyMenu.h"

using namespace std;

namespace DVV {
    MenuItem::MenuItem(string name, Func func) : item_name(name), func(func) {} // конструктор MenuItem

    #pragma region методы-MenuItem

    string MenuItem::getName() { // методы 
        return item_name;
    }
    void MenuItem::print() {
        cout << item_name;
    }
    int MenuItem::run() {
        return func();
    }

    #pragma endregion

    MyMenu::MyMenu(string title, MenuItem *items, size_t count) : title(title), items(items), count(count) {} // конструктор MyMenu

    #pragma region методы-MyMenu

    int MyMenu::getSelect() const {
        return select;
    }
    bool MyMenu::isRun() const {
        return running;
    }
    size_t MyMenu::getCount() const {
        return count;
    }
    string MyMenu::getTitle() {
        return title;
    }
    MenuItem *MyMenu::getItems() {
        return items;
    }
    void MyMenu::print() {
        string menutitle = MyMenu::getTitle();
        cout << "\n" << menutitle << endl;
        for (size_t i{}; i < count; ++i) {
            cout << i + 1 << ". ";
            items[i].print();
            cout << endl;
            }
    }
    int MyMenu::runCommand() {
        print();
        cout << "\n   Select >> ";
        cin >> select;
        return items[select - 1].run();
    }

    #pragma endregion
}

