#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_NAME_LENGTH = 50;

struct Instrument {
    char name[MAX_NAME_LENGTH];
    int day;
    int month;
    int year;
};

void createFile() {
    ofstream file("instruments.txt");
    if (!file) {
        cout << "Error creating file!" << endl;
        return;
    }

    file << "Hammer 15 3 2010" << endl;
    file << "Screwdriver 10 6 2012" << endl;
    file << "Drill 20 9 2015" << endl;
    file << "Pliers 5 12 2018" << endl;
    file << "Wrench 25 2 2020" << endl;
    file << "TapeMeasure 12 4 2011" << endl;
    file << "ScrewGun 8 7 2013" << endl;
    file << "Saw 18 10 2016" << endl;
    file << "File 3 1 2019" << endl;
    file << "DrillMachine 22 5 2021" << endl;

    file.close();
    cout << "File successfully created!" << endl;
}

void viewFile() {
    ifstream file("instruments.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Instrument instrument;
    cout << "File content:" << endl;
    while (file >> instrument.name >> instrument.day >> instrument.month >> instrument.year) {
        cout << "Instrument: " << instrument.name << ", Manufacturing Date: "
                  << instrument.day << "." << instrument.month << "." << instrument.year << endl;
    }

    file.close();
}

void addToBeginning() {
    Instrument newInstrument;
    cout << "Enter the instrument name: ";
    cin.getline(newInstrument.name, MAX_NAME_LENGTH);
    cout << "Enter the manufacturing date (dd mm yyyy): ";
    cin >> newInstrument.day >> newInstrument.month >> newInstrument.year;
    cin.ignore();

    fstream file("instruments.txt", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    file.seekg(0, ios::end);
    streampos fileSize = file.tellg(); 
    char* buffer = new char[fileSize];
    file.seekg(0, ios::beg); 
    file.read(buffer, fileSize); 

    file.seekp(0, ios::beg); 
    file << newInstrument.name << " " << newInstrument.day << " "
         << newInstrument.month << " " << newInstrument.year << endl;
    file.write(buffer, fileSize); 

    delete[] buffer;
    file.close();
    cout << "Information successfully added to the beginning of the file!" << endl;
}

void addToEnd() {
    Instrument newInstrument;
    cout << "Enter the instrument name: ";
    cin.getline(newInstrument.name, MAX_NAME_LENGTH);
    cout << "Enter the manufacturing date (dd mm yyyy): ";
    cin >> newInstrument.day >> newInstrument.month >> newInstrument.year;
    cin.ignore();

    ofstream file("instruments.txt", ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    file << newInstrument.name << " " << newInstrument.day << " "
         << newInstrument.month << " " << newInstrument.year << endl;

    file.close();
    cout << "Information successfully added to the end of the file!" << endl;
}

void findOldestInstrument() {
    ifstream file("instruments.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    Instrument oldestInstrument;
    bool first = true;

    Instrument instrument;
    while (file >> instrument.name >> instrument.day >> instrument.month >> instrument.year) {
        if (first || (instrument.year < oldestInstrument.year) ||
            (instrument.year == oldestInstrument.year && instrument.month < oldestInstrument.month) ||
            (instrument.year == oldestInstrument.year && instrument.month == oldestInstrument.month && instrument.day < oldestInstrument.day)) {
            oldestInstrument = instrument;
            first = false;
        }
    }

    file.close();

    if (!first) {
        cout << "Instrument with the longest usage time: " << oldestInstrument.name
             << ", Manufacturing Date: " << oldestInstrument.day << "." << oldestInstrument.month << "." << oldestInstrument.year << endl;
    } else {
        cout << "File is empty!" << endl;
    }
}

void correctOldestInstrument() {
    ifstream originalFile("instruments.txt");
    ofstream tempFile("temp.txt");

    if (!originalFile || !tempFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    Instrument oldestInstrument;
    bool first = true;
    bool found = false;

    Instrument instrument;
    while (originalFile >> instrument.name >> instrument.day >> instrument.month >> instrument.year) {
        if (first || (instrument.year < oldestInstrument.year) ||
            (instrument.year == oldestInstrument.year && instrument.month < oldestInstrument.month) ||
            (instrument.year == oldestInstrument.year && instrument.month == oldestInstrument.month && instrument.day < oldestInstrument.day)) {
            oldestInstrument = instrument;
            first = false;
        }
    }

    originalFile.clear();
    originalFile.seekg(0, ios::beg);

    while (originalFile >> instrument.name >> instrument.day >> instrument.month >> instrument.year) {
        if (strcmp(instrument.name, oldestInstrument.name) == 0 &&
            instrument.day == oldestInstrument.day &&
            instrument.month == oldestInstrument.month &&
            instrument.year == oldestInstrument.year) {
            cout << "Enter the new manufacturing date for the instrument " << instrument.name << " (dd mm yyyy): ";
            cin >> instrument.day >> instrument.month >> instrument.year;
            cin.ignore();
            found = true;
        }
        tempFile << instrument.name << " " << instrument.day << " "
                 << instrument.month << " " << instrument.year << endl;
    }

    originalFile.close();
    tempFile.close();

    if (!found) {
        cout << "Instrument not found!" << endl;
        remove("temp.txt");
    } else {
        remove("instruments.txt");
        rename("temp.txt", "instruments.txt");
        cout << "Record successfully corrected!" << endl;
    }
}

void showMenu() {
    cout << "Menu:" << endl;
    cout << "1. Create file" << endl;
    cout << "2. View file" << endl;
    cout << "3. Add record to the beginning of the file" << endl;
    cout << "4. Add record to the end of the file" << endl;
    cout << "5. Find the instrument with the longest usage time" << endl;
    cout << "6. Correct the record of the oldest instrument" << endl;
    cout << "7. Exit" << endl;
    cout << "Choose an action: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                viewFile();
                break;
            case 3:
                addToBeginning();
                break;
            case 4:
                addToEnd();
                break;
            case 5:
                findOldestInstrument();
                break;
            case 6:
                correctOldestInstrument();
                break;
            case 7:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}