#include <iostream>
#include <cstring>

#include <locale>


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
        double avgGrade {0};
};

Student students[30];
int studentsNum {0};
char groups[30][15] {""};

void CloseProgramm();
void PrintMenu();
void MenuWork();
void TablePrintHead();
void UserInput(char string[]);
void TablePrintStudent(char fname[], char sname[], char tname[], char gname[], int jyear, int grades[4], int number, double avg);
void BestStudent();
void CheckGroups();
void copyStudent(Student& dest, const Student& src);
void filterStudentsByGroup(const Student students[], int studentsCount, Student filteredStudents[], int maxFilteredCount, const char* targetGroup);
void SortMenuWork();
int getSortMethod(int sortType);
void sortStudents(Student* students, int n, int sortType, int sortMethod);

int main() {
    // std::locale::global(std::locale(""));
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
    cout << "\033[1m4) /best\033[0m - Show first and second student name with best avg. grade" << endl;
    cout << "\033[1m5) /exit\033[0m - Exit programm" << endl;
}

void PrintSortMenu () {
    cout << "\n\033[1;36mSort menu:\033[0m\n" << endl;
    cout << "\033[1m7) /cltab\033[0m - Close all students table" << endl;
    cout << "\033[1m8) /sbfn\033[0m - Sort students by first name" << endl;
    cout << "\033[1m9) /sbsn\033[0m - Sort students by second name" << endl;
    cout << "\033[1m10) /sbtn\033[0m - Sort students by third name" << endl;
    cout << "\033[1m11) /sbgn\033[0m - Sort students by group name" << endl;
    cout << "\033[1m12) /sbjy\033[0m - Sort students by join year" << endl;
    cout << "\033[1m13) /sbgfs\033[0m - Sort students by grades for 4 subjects" << endl;
}

void CreateUser(){

    //TODO: проверки на дату поступления, на вводимые данные и тд и тп

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
        student.avgGrade += (atoi(token))/4.;
        count++;
        token = strtok(nullptr, " ");
    }
    cout << "\033[2J\033[1;1H";
    cout << "\nIs data right (\033[1;32my\033[0m/\e[1;31mn\e[0m)?\n" << endl;

    TablePrintHead();
    TablePrintStudent(student.firstName, student.secondName, student.thirdname, student.group, student.joinYear, student.grades, 1, student.avgGrade);

   //163

    char usAnsw[4] = "";
    bool isReady {false};
    while (!isReady) {
        cin >> usAnsw;
        if (strcmp(usAnsw, "y") == 0 || strcmp(usAnsw, "н") == 0){
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
            students[studentsNum].avgGrade = student.avgGrade;
            studentsNum +=1 ;

            cout << "\n\033[1;32mUser added\033[0m\n" << endl;
            MenuWork();
            isReady = true;
        }
        else if (strcmp(usAnsw, "n") == 0 || strcmp(usAnsw, "т") == 0) {
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
        TablePrintStudent(students[i].firstName, students[i].secondName, students[i].thirdname, students[i].group, students[i].joinYear, students[i].grades, i+1, students[i].avgGrade);
     }
    SortMenuWork();
    cout << endl;
}



void MenuWork() {
    PrintMenu();
    char string[MAX_LENGTH] = "";
    UserInput(string);
    if (strcmp(string, "/exit") == 0 or strcmp(string, "5") == 0) {
        CloseProgramm();
    }
    else if (strcmp(string, "/showall") == 0 or strcmp(string, "0") == 0) {
        ShowAllUsers();
    }
    else if (strcmp(string, "/add") == 0 or strcmp(string, "1") == 0) {
        CreateUser();
    }
    else if (strcmp(string, "/edit") == 0 or strcmp(string, "2") == 0) {
        cout << "In dev" << endl;
    }
    else if (strcmp(string, "/delete") == 0 or strcmp(string, "3") == 0) {
        cout << "In dev" << endl;
    }
    else if (strcmp(string, "/best") == 0 or strcmp(string, "4") == 0) {
        BestStudent();
    }
    else {
        cout << "Command is not found" << endl;
    }
    
}

void SortMenuWork() {
    if (render) {
        PrintSortMenu();
    char string[MAX_LENGTH] = "";
    UserInput(string);
    int sortMethod {0};
    if (strcmp(string, "/cltab") == 0 or strcmp(string, "7") == 0) {
        cout << "\033[2J\033[1;1H" << endl;
        MenuWork();
    }
    else if (strcmp(string, "/sbfn") == 0 or strcmp(string, "8") == 0) {
        sortMethod = getSortMethod(8);
        sortStudents(students, 30, 8, sortMethod);
    }
    else if (strcmp(string, "/sbsn") == 0 or strcmp(string, "9") == 0) {
        sortMethod = getSortMethod(9);
        sortStudents(students, 30, 9, sortMethod);
        // sort students by second name
    }
    else if (strcmp(string, "/sbtn") == 0 or strcmp(string, "10") == 0) {
        sortMethod = getSortMethod(10);
        sortStudents(students, 30, 10, sortMethod);
        // sort students by third name
    }
    else if (strcmp(string, "/sbgn") == 0 or strcmp(string, "11") == 0) {
        sortMethod = getSortMethod(11);
        sortStudents(students, 30, 11, sortMethod);
        // sort students by group name
    }
    else if (strcmp(string, "/sbjy") == 0 or strcmp(string, "12") == 0) {
        sortMethod = getSortMethod(12);
        sortStudents(students, 30, 12, sortMethod);
        // sort students by join year
    }
    else if (strcmp(string, "/sbgfs") == 0 or strcmp(string, "13") == 0) {
        sortMethod = getSortMethod(13);
        sortStudents(students, 30, 13, sortMethod);
        // sort students by avg grade
    }
    else {
        cout << "Command is not found" << endl;
    }
    ShowAllUsers();
    }
    else {
        cout << "\033[2J\033[1;1H";
        cout << "\n\033[1;36mBye <3\033[0m\n" << endl;
    }
    
}

void sortStudents(Student* students, int n, int sortType, int sortMethod) {
    int stNum {0};
    for(int z = 0; z < n; z++){
        if(strlen(students[z].firstName) != 0) {
            stNum += 1;
        }
    }
    bool ascending {false};
    if (sortMethod == 1 ) {
        ascending = true;
    }
    else {
        ascending = false;
    }
    for (int i = 0; i < stNum - 1; i++) {
        for (int j = 0; j < stNum - i - 1; j++) {
            bool swapNeeded = false;
            switch (sortType) {
                case 8: // Сортировка по Ф
                    swapNeeded = ascending ? strcmp(students[j].firstName, students[j + 1].firstName) > 0 : strcmp(students[j].firstName, students[j + 1].firstName) < 0;
                    break;
                case 9: // Сортировка по И
                    swapNeeded = ascending ? strcmp(students[j].secondName, students[j + 1].secondName) > 0 : strcmp(students[j].secondName, students[j + 1].secondName) < 0;
                    break;
                case 10: // Сортировка по О
                    swapNeeded = ascending ? strcmp(students[j].thirdname, students[j + 1].thirdname) > 0 : strcmp(students[j].thirdname, students[j + 1].thirdname) < 0;
                    break;
                case 11: // Сортировка по группе
                    swapNeeded = ascending ? strcmp(students[j].group, students[j + 1].group) > 0 : strcmp(students[j].group, students[j + 1].group) < 0;
                    break;
                case 12: // Сортировка по году поступления
                    swapNeeded = !ascending ? students[j].joinYear > students[j + 1].joinYear : students[j].joinYear < students[j + 1].joinYear;
                    break;
                case 13: // Сортировка по среднему баллу
                    swapNeeded = !ascending ? students[j].avgGrade > students[j + 1].avgGrade : students[j].avgGrade < students[j + 1].avgGrade;
                    break;
                default:
                    cout << "Неизвестный тип сортировки" << endl;
                    return;
            }
            if (swapNeeded) {
                // Обмен местами двух студентов
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int getSortMethod(int sortType) {
    switch (sortType)
    {
    case 8:
    case 9:
    case 10:
    case 11:
        cout << "\033[1mSort from? ('-t' - from top to bottom, '-b' - from bottom to top):\033[0m " ;
        break;
    case 12: 
        cout << "\033[1mSort from? ('-t' - from newer year to older , '-b' - from older year to newer):\033[0m " ;
        break;
    case 13:
        cout << "\033[1mSort from? ('-t' - from the best to bad, '-b' - from bad to the best):\033[0m " ;
        break;
    default:
        break;
    }
    char arrg[MAX_LENGTH] = "";
    UserInput(arrg);
    if (strcmp(arrg, "-t") == 0) {
        return 1;
    }
    else if (strcmp(arrg, "-b") == 0){
        return 2;
    }
    else {
        return 1;
    }



}

void TablePrintHead() {
    for (int i = 0; i < 164; ++i) {
        cout << "\033[2m-\033[0m";
    }
    cout << endl;
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
    cout << "\033[2m|\033[0m";
    for (int i = 0; i < 17; ++i) {
        cout << " ";
    }
    cout << "Join Year ";
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

void TablePrintStudent(char fname[], char sname[], char tname[], char gname[], int jyear, int grades[4], int number, double avg) {
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
    cout << "\033[2m|\033[0m";
    for (int i = 0; i < 26-4; ++i) {
        cout << " ";
    }
    cout << jyear << " ";
    cout << "\033[2m|\033[0m";

    //19-7
    cout << "      "; //6
    for (int i = 0; i < 4; ++i) {
        cout << grades[i] << " ";
    }
    cout << avg;
    cout << endl;
}

void BestStudent() {
    int bestStNum {0};
    double bestAvg {0.0};
    int acceptGroups {0};
    int selectedGroup {0};
    Student studentsInGroup[30];
    for (int i = 0; i < 30; ++i){
        if (students[i].avgGrade < bestAvg) continue;
        bestAvg = students[i].avgGrade;
        bestStNum = i;
    }
    if (bestAvg == 0.0) {
        cout << "\033[2J\033[1;1H";
        cout << "Student's table is empty" << endl;
    }
    else {
        cout << "\033[2J\033[1;1H";
        cout << "Best student in table: ";
        cout << "\n" << students[bestStNum-1].firstName << " " << students[bestStNum-1].secondName << " | " << bestAvg << "\n" <<  endl;
        cout << "Select group:" << endl;
        CheckGroups();
        for (int i = 0; i < 30; ++i) {
            if(strlen(groups[i]) != 0){
                cout << "\033[1m" << i + 1 << ") " << groups[i] << "\033[0m" << endl;
                acceptGroups += 1;
            } 
        }
        cin >> selectedGroup;

        if(selectedGroup > acceptGroups || selectedGroup <= 0) {
            cout << "Group doesn't exist" << endl;
        }
        else {
            filterStudentsByGroup(students, 30, studentsInGroup, 40, groups[selectedGroup-1]);
            bestAvg = 0.0;
            bestStNum = 0;
            for(int i = 0; i < 30; ++i) {
                if(strlen(studentsInGroup[i].firstName) != 0){
                    if (studentsInGroup[i].avgGrade < bestAvg) continue;
                    bestAvg = studentsInGroup[i].avgGrade;
                    bestStNum = i;
                }
            }
            cout << "\033[2J\033[1;1H";
            cout << "\nBest student in a group " << groups[selectedGroup-1] << ": " << studentsInGroup[bestStNum].firstName << " " << studentsInGroup[bestStNum].secondName << " | " << bestAvg << "\n" << endl; 
        }
    }
}

void CheckGroups() {
    for (int i = 0; i < 30; ++i){
        char studGroup[15] = "";
        strcpy(studGroup, students[i].group);
        for(int j = 0; j < 30; ++j){
            if (strcmp(studGroup, groups[j]) == 0) {
                break;
            }
            else if (strlen(groups[j]) == 0 && strlen(studGroup) != 0){
                strcpy(groups[j], studGroup);
                break;
            }
        }
    }
}

void copyStudent(Student& dest, const Student& src) {
    strcpy(dest.firstName, src.firstName);
    strcpy(dest.secondName, src.secondName);
    dest.avgGrade = (src.grades[0] + src.grades[1] + src.grades[2] + src.grades[3]) / 4.;
    strcpy(dest.group, src.group);
}

void filterStudentsByGroup(const Student students[], int studentsCount, Student filteredStudents[], int maxFilteredCount, const char* targetGroup) {
    int filteredCount = 0;

    for (int i = 0; i < studentsCount; ++i) {
        if (strcmp(students[i].group, targetGroup) == 0) {
            if (filteredCount < maxFilteredCount) {
                copyStudent(filteredStudents[filteredCount], students[i]);
                ++filteredCount;
            } else {
                cout << "Filtered students array capacity exceeded!" << endl;
                break;
            }
        }
    }
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