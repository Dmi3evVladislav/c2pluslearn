#include <iostream>

using i = int; //Определяем псевдоним для типов (typedef)

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
    age = 19;
    
    std::cout << "Возраст: " << age << " lol: " << lol << std::endl; //вывод в консоль

    lol = 2.18;

    std::cout << "Возраст: " << age << " lol: " << lol << " " << sizeof(age) << std::endl; //sizeof - размер

    std::cout << "Введите вес: ";
    std::cin >> weight;
    std::cout << "Ваш вес: " << weight << std::endl;

    std::cout << "Введите два целых числа через пробел" << std::endl;
    i a;
    i b; 
    /*
        ++ Инкремент (база), причем префикс ++x сразу меняет и юзает эти данные,
        а постфикс x++ сначала юзает данные (при выводе, присвоении и тд) и только потом меняет

        Приоритеты опираций как в JS и Python, скобки роляют
    */ 
    std::cin >> a >> b;
    std::cout << "Сумма: " << a+b << std::endl;
    
    return 0; //Завершаем выполнение функции и возвращаем 0
}