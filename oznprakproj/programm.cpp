#include <iostream>
#include <cstring>
#include <string>

const int MAX_LENGTH = 100;

using namespace std;

bool render {true};
int programmState {0};

struct Student
    {
        char firstName[26] = "";
        char secondName[26] = "";
        char thirdname[26] = "";
        int joinYear {2024};
        char group[26] = "";
        int grades[4];
};

Student students[30];
int studentsNum {0};

void CloseProgramm();
void PrintMenu();
void MenuWork();
void TablePrintHead();
void UserInput(char string[]);
void TablePrintStudent(char fname[], char sname[], char tname[], char gname[], int jyear, int grades[4], int number);

int main() {
    cout << "\033[2J\033[1;1H";
    cout << "\n\033[1;36mHello!\033[0m\n" << endl;
    programmState = 1;



    do {
        // switch (programmState)
        // {
        // case 1:
        //     MenuWork();
        //     break;
        // case 4:
        //     CloseProgramm();
        //     break;
        // default:
        //     break;
        //
    
        MenuWork();
    } while (render);
    

    return 0;
}



void CloseProgramm () {
    cout << "\033[2J\033[1;1H";
    cout << "\n\033[1;36mBye <3\033[0m\n" << endl;
    render = false;
}

void PrintMenu() {
    cout << "\e[1;31mMenu: \e[0m" << endl;
    cout << "\033[1m0) /showall\033[0m - Show all students" << endl;
    cout << "\033[1m1) /add\033[0m - Add new student" << endl;
    cout << "\033[1m2) /edit\033[0m - Edit student entry" << endl;
    cout << "\033[1m3) /delete\033[0m - Delete student entry" << endl;
    cout << "\033[1m4) /exit\033[0m - Exit programm" << endl;
}

void CreateUser(){
    cout << "\033[2J\033[1;1H";
    cout << "\n\033[2mClose app: Ctrl + C\033[0m\n" << endl;
    
    Student student;

    cout << "\033[1mFirst Name:\033[0m ";
    UserInput(student.firstName);
    
    cout << "\033[1mSecond Name:\033[0m ";
    UserInput(student.secondName);
    
    cout << "\033[1mThird Name:\033[0m ";
    UserInput(student.thirdname);
    
    cout << "\033[1mGroup Name:\033[0m ";
    UserInput(student.group);
    
    cout << "\033[1mJoin Year:\033[0m ";
    cin >> student.joinYear;
    
    cout << "\033[1mGrades for 4 subjects (separated by a space):\033[0m ";
    char studGR[20] = "";
    UserInput(studGR);
    int count = 0;
    char* token = strtok(studGR, " ");
    while (token != nullptr && count < 4) {
        student.grades[count] = atoi(token);
        count++;
        token = strtok(nullptr, " ");
    }
    cout << "\033[2J\033[1;1H";
    cout << "\nIs data right (\033[1;32my\033[0m/\e[1;31mn\e[0m)?\n" << endl;

    TablePrintHead();
    TablePrintStudent(student.firstName, student.secondName, student.thirdname, student.group, student.joinYear, student.grades, 1);

   //163

    char usAnsw[4] = "";
    bool isReady {false};
    while (!isReady) {
        cin >> usAnsw;
        if (strcmp(usAnsw, "y") == 0){
            cout << "\033[2J\033[1;1H";

            strcpy(students[studentsNum].firstName, student.firstName);
            strcpy(students[studentsNum].secondName, student.secondName);
            strcpy(students[studentsNum].thirdname, student.thirdname);
            strcpy(students[studentsNum].group, student.group);
            students[studentsNum].joinYear = student.joinYear;
            students[studentsNum].grades[0] = student.grades[0]; // Скорее всего не то
            students[studentsNum].grades[1] = student.grades[1];
            students[studentsNum].grades[2] = student.grades[2];
            students[studentsNum].grades[3] = student.grades[3];
            studentsNum +=1 ;

            cout << "\n\033[1;32mUser added\033[0m\n" << endl;
            MenuWork();
            isReady = true;
        }
        else if (strcmp(usAnsw, "n") == 0) {
            cout << "\033[2J\033[1;1H";
            cout << "\n\033[1;33mData cleared. Try again\033[0m\n" << endl;
            MenuWork();
            isReady = true;
        }
    }
    
}

void ShowAllUsers() {
    cout << "\033[2J\033[1;1H";
    cout << endl;
    TablePrintHead();
     for (int i = 0; i < 30; ++i) {
        if (strlen(students[i].firstName) == 0 || strlen(students[i].secondName) == 0 || strlen(students[i].thirdname) == 0  || strlen(students[i].group) == 0) break;
        TablePrintStudent(students[i].firstName, students[i].secondName, students[i].thirdname, students[i].group, students[i].joinYear, students[i].grades, i+1);
     }
     cout << endl;
}



void MenuWork() {
    PrintMenu();
    char string[MAX_LENGTH] = "";
    UserInput(string);
    if (strcmp(string, "/exit") == 0 or strcmp(string, "4") == 0) {
        CloseProgramm();
    }
    else if (strcmp(string, "/add") == 0 or strcmp(string, "1") == 0) {
        CreateUser();
    }
    else if (strcmp(string, "/showall") == 0 or strcmp(string, "0") == 0) {
        ShowAllUsers();
    }
}

void TablePrintHead() {
    cout << " No \033[2m|\033[0m First Name";
    for (int i = 0; i < 16; ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m Second Name";
    for (int i = 0; i < 15; ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m Third Name";
    for (int i = 0; i < 16; ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m Group Name";
    for (int i = 0; i < 16; ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m Join Year";
    for (int i = 0; i < 17; ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m Grades for 4 subj";
    for (int i = 0; i < 9; ++i) {
        cout << " ";
    }
    cout << endl;
    for (int i = 0; i < 164; ++i) {
        cout << "\033[2m-\033[0m";
    }
    cout << endl;
}

void TablePrintStudent(char fname[], char sname[], char tname[], char gname[], int jyear, int grades[4], int number) {
    if (number / 10 == 0) {
        cout << " " << number << "  ";
    }
    else {
        cout << " " << number << " ";
    }

    cout << "\033[2m|\033[0m " << fname;
    for (int i = 0; i < 26-strlen(fname); ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m " << sname;
    for (int i = 0; i < 26-strlen(sname); ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m " << tname;
    for (int i = 0; i < 26-strlen(tname); ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m " << gname;
    for (int i = 0; i < 26-strlen(gname); ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m " << jyear;
    for (int i = 0; i < 26-4; ++i) {
        cout << " ";
    }
    cout << "\033[2m|\033[0m ";
    for (int i = 0; i < 4; ++i) {
        cout << grades[i] << " ";
    }
    cout << endl;
}

void UserInput(char string[]) {
    bool empti {true};
    char input[MAX_LENGTH] = "";
    while (empti) {
        cin.getline(input, MAX_LENGTH);
        if (strlen(input) == 0){
            continue;
        }
        else {
            empti = false;
        }
    }
    strcpy(string, input);
}