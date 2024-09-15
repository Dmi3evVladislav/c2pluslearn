#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::wcout;


int main() {
    setlocale(LC_ALL, "");

    const int origPasw {2416};
    const int &pasw {origPasw}; //Ссылка

    
    int password;

    wcout << L"Введите пароль:" << endl;

    cin >> password;

    // условия if, else if, else

    if(password == pasw) {
        wcout << L"Доступ разрешен" << endl;
    }
    else if (password == 2406) {
        wcout << L"Почти правильно" << endl;
    }
    else {
        wcout << L"Доступ запрещен" << endl;
    }

    //switch-case

    switch (password) {
        case 2416: wcout << L"Доступ разрешен" << endl; break;
        case 2406: wcout << L"Почти правильно" << endl; break;
        default: wcout << L"Доступ запрещен" << endl; break;
    }

    int password2;
    bool alowed {false};

    wcout << L"Введите пароль:" << endl;

    //Цикл while

    while(!alowed){
        cin >> password2;
        if(password2 != pasw) {
            wcout << L"Доступ запрещен. Попробуйте снова:" << endl;
        }
        else {
            wcout << L"Доступ разрешен" << endl;
            alowed = true;
        }
    }

    //Цикл for

    for(int i {0}; i < 3; i++) {
        wcout << L"aboba" << endl;
    }

    //Цикл for-each

    for (int n : {0, 1, 2, 3, 5})
    {
        if(n == 1) continue;
        if(n == 3) break;
        cout << n << endl;
    }

    int numbers[6] {1, 2, 3, 4, 5};
    for (auto& n : numbers) {
        n = n * n;
    }
    for (auto n : numbers) {
        cout << n << "\t";
    }
    cout << endl;
    

    return 0;
}