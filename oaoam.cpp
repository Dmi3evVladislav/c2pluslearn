#include <iostream>

using std::cout;
using std::cin;
using std::endl;


int main() {

    const int origPasw {2416};
    const int &pasw {origPasw}; //Ссылка

    
    int password;

    cout << "Введите пароль:" << endl;

    cin >> password;

    // условия if, else if, else

    if(password == pasw) {
        cout << "Доступ разрешен" << endl;
    }
    else if (password == 2406) {
        cout << "Почти правильно" << endl;
    }
    else {
        cout << "Доступ запрещен" << endl;
    }

    //switch-case

    switch (password) {
        case 2416: cout << "Доступ разрешен" << endl; break;
        case 2406: cout << "Почти правильно" << endl; break;
        default: cout << "Доступ запрещен" << endl; break;
    }

    int password2;
    bool alowed {false};

    cout << "Введите пароль:" << endl;

    //Цикл while

    while(!alowed){
        cin >> password2;
        if(password2 != pasw) {
            cout << "Доступ запрещен. Попробуйте снова:" << endl;
        }
        else {
            cout << "Доступ разрешен" << endl;
            alowed = true;
        }
    }

    //Цикл for

    for(int i {0}; i < 3; i++) {
        cout << "aboba" << endl;
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