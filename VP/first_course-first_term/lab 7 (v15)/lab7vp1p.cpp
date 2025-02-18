#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_LG = 150;
const int MAX_CARS = 100;

struct Car {
    char brand[MAX_LG];
    int year;
    char color[MAX_LG];
    char number[MAX_LG];
};

void addCarFromConsole(Car& car) {
    cout << "Enter car brand: ";
    cin.getline(car.brand, MAX_LG);

    cout << "Enter year of manufacture: ";
    cin >> car.year;
    cin.ignore();

    cout << "Enter car color: ";
    cin.getline(car.color, MAX_LG);

    cout << "Enter car number: ";
    cin.getline(car.number, MAX_LG);
}

void writeCarsToFile(const Car cars[], int count, const char* filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        outFile << cars[i].brand << "\n";
        outFile << cars[i].year << "\n";
        outFile << cars[i].color << "\n";
        outFile << cars[i].number << "\n";
    }

    outFile.close();
    cout << "Data successfully written to file " << filename << endl;
}

void readCarsFromFile(Car cars[], int& count, const char* filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    count = 0;
    while (count < MAX_CARS && inFile.peek() != EOF) {
        inFile.getline(cars[count].brand, MAX_LG);
        inFile >> cars[count].year;
        inFile.ignore();
        inFile.getline(cars[count].color, MAX_LG);
        inFile.getline(cars[count].number, MAX_LG);
        count++;
    }

    inFile.close();
    cout << "Data successfully read from file " << filename << endl;
}

void printCars(const Car cars[], int count) {
    cout << "Car list:" << endl;
    for (int i = 0; i < count; ++i) {
        cout << "Car " << i + 1 << ":" << endl;
        cout << "  Brand: " << cars[i].brand << endl;
        cout << "  Year of manufacture: " << cars[i].year << endl;
        cout << "  Color: " << cars[i].color << endl;
        cout << "  Number: " << cars[i].number << endl;
    }
}

int main() {
    const char* filename = "cars.txt";
    Car cars[MAX_CARS];
    int count = 0;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add a car" << endl;
        cout << "2. Write data to file" << endl;
        cout << "3. Read data from file" << endl;
        cout << "4. Print data to console" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose an action: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                if (count < MAX_CARS) {
                    addCarFromConsole(cars[count]);
                    count++;
                    cout << "Car added!" << endl;
                } else {
                    cout << "Maximum number of cars reached!" << endl;
                }
                break;
            case 2:
                writeCarsToFile(cars, count, filename);
                break;
            case 3:
                readCarsFromFile(cars, count, filename);
                break;
            case 4:
                printCars(cars, count);
                break;
            case 0:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}