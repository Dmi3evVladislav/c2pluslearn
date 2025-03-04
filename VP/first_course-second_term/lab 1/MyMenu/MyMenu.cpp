#include <iostream>
#include "./MyMenu.h"

using namespace std;

namespace KDM {
    // методы класса MenuItem
    MenuItem::MenuItem(string name, Func func) : item_name(name), func(func) {}

    string MenuItem::getName() {
        return item_name;
    }

    void MenuItem::print() {
        cout << item_name;
    }

    int MenuItem::run() {
        return func();
    }

    // методы класса MyMenu
    MyMenu::MyMenu(string title, MenuItem *items, size_t count) : title(title), items(items), count(count) {}

    int MyMenu::getSelect() const {
        return select;
    }

    bool MyMenu::isRun() const {
        return running;
    } // пустой геттер

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
}

