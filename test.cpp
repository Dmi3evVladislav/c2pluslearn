#include <iostream>

using i = int; //Определяем псевдоним для типов (typedef)
using std::cout;
using std::wcout;
using std::cin;
using std::endl;


i age {18};
float lol;    //int lol; int lol {}; int lol {0};

const i cn {2416};

i weight;

// void clog(data) 
// {
//     std::cout << data;
// }


int main() //Определяем функцию
{
    setlocale(LC_ALL, "");
    age = 19;
    
    cout << "Возраст: " << age << " lol: " << lol << endl; //вывод в консоль

    lol = 2.18;
    
    cout << "Возраст: " << age << " lol: " << lol << " " << sizeof(age) << endl; //sizeof - размер

    cout << "Введите вес: ";
    cin >> weight;
    cout << "Ваш вес: " << weight << endl;

    cout << "Введите два целых числа через пробел" << endl;
    i a;
    i b; 
    /*
        ++ Инкремент (база), причем префикс ++x сразу меняет и юзает эти данные,
        а постфикс x++ сначала юзает данные (при выводе, присвоении и тд) и только потом меняет

        Приоритеты опираций как в JS и Python, скобки роляют
    */ 
    cin >> a >> b;
    cout << "Сумма: " << a+b << endl;

    
    return 0; //Завершаем выполнение функции и возвращаем 0
}