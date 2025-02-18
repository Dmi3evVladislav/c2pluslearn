#include <iostream>
using namespace std;
struct Date {
    int day;
    int month;
    int year;
};
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int daysInMonth(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
            break;
        case 4: case 6: case 9: case 11:
            return 30;
            break;
        case 2: {
            bool ily = isLeapYear(year);
            return ily ? 29 : 28;
            break;
        }
        default:
            return 0;
            break;
    }
}
Date addDays(Date date, int N) {
    for (int i = 0; i < N; ++i) {
        date.day++;
        int dIM = daysInMonth(date.month, date.year);
        if (date.day > dIM) {
            date.day = 1;
            date.month++;
            if (date.month > 12) {
                date.month = 1;
                date.year++;
            }
        }
    }
    return date;
}
void printDate(Date date) {
    cout << date.day << "." << date.month << "." << date.year << endl;
}

int main() {
    Date date;
    int N;
    cin >> date.day;
    cin >> date.month;
    cin >> date.year;
    cout << "Input num of days, to push date: ";
    cin >> N;
    Date newDate = addDays(date, N);
    cout << "Date after " << N << " days: ";
    printDate(newDate);

    return 0;
}