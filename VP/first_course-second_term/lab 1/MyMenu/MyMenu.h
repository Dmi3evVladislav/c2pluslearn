#ifndef MYMENU_H
#define MYMENU_H

#pragma once

#include <cstddef>
#include <string>

using namespace std;

namespace KDM {
    // класс для пункта меню
    class MenuItem {
    public:
        typedef int(*Func)();
        MenuItem(string, Func);
        Func func{};
        string item_name{};
        string getName();
        void print();
        int run();
    };
    
    // класс меню
    class MyMenu {
    public:
        MyMenu(string, MenuItem *, size_t); //конструктор
        
        int getSelect() const;
        bool isRun() const;
        string getTitle();
        size_t getCount() const;
        MenuItem *getItems();
        void print();
        int runCommand();

    private:
        int select{-1};
        size_t count{};
        bool running{};
        string title{};
        MenuItem *items{};
    };
}

#endif // MYMENU_H