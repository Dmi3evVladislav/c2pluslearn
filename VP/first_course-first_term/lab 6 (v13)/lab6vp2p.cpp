#include <iostream>
#include <cmath>
using namespace std;
struct Elevator {
    int floor;
    bool isOccupied;
    bool isMovingUp;
};
void INPUT(int& N, Elevator elevators[3], int& personFloor) {
    cout << "Floors in flat: ";
    cin >> N;

    cout << "Elev. start position (floor, occupied/empti, moving direction):" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Elevator " << i + 1 << " (floor, occupied? (1/0), direction? (1 - up, 0 - down)): ";
        cin >> elevators[i].floor >> elevators[i].isOccupied >> elevators[i].isMovingUp;
    }

    cout << "Floor, the pers is located: ";
    cin >> personFloor;
}

void OUTPUT(const Elevator elevators[3], int personFloor) {
    cout << "Current config:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Elevator " << i + 1 << ": floor " << elevators[i].floor
             << ", " << (elevators[i].isOccupied ? "occupied" : "empty")
             << ", " << (elevators[i].isMovingUp ? "moving up" : "moving down") << endl;
    }
    cout << "Person located o floor: " << personFloor << endl;
}

int CHOOSE_LIFT(const Elevator elevators[3], int personFloor) {
    int closestFreeLift = -1;
    int minDistanceFree = 1000000;

    int closestOccupiedLift = -1;
    int minDistanceOccupied = 1000000;

    for (int i = 0; i < 3; ++i) {
        int distance = abs(elevators[i].floor - personFloor);

        if (!elevators[i].isOccupied) {
            if (distance < minDistanceFree) {
                minDistanceFree = distance;
                closestFreeLift = i;
            }
        } else {
            if (elevators[i].isMovingUp == (personFloor > elevators[i].floor) && distance < minDistanceOccupied) {
                minDistanceOccupied = distance;
                closestOccupiedLift = i;
            }
        }
    }

    if (closestFreeLift != -1) {
        return closestFreeLift;
    } else {
        return closestOccupiedLift;
    }
}

int main() {
    int N;
    Elevator elevators[3];
    int personFloor;

    INPUT(N, elevators, personFloor);

    OUTPUT(elevators, personFloor);

    int chosenLift = CHOOSE_LIFT(elevators, personFloor);

    if (chosenLift != -1) {
        cout << "Elevator will be called: " << chosenLift + 1 << endl;
    } else {
        cout << "This is no elevator." << endl;
    }

    return 0;
}