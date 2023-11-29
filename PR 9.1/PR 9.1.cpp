#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <Windows.h>

using namespace std;

enum Specialty { ComputerScience, Physics, Mathematics };

struct Student {
    string surname;
    int course;
    Specialty specialty;
    int physics;
    int math;
    int informatics;
};

Specialty getRandomSpecialty() {
    return static_cast<Specialty>(rand() % 3);
}

string getRandomSurname() {
    string surnames[] = { "Іванов", "Ільницький", "Шевченко", "Мельник", "Яворський" };
    return surnames[rand() % 5];
}

int getRandomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void createStudents(Student* students, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        students[i].surname = getRandomSurname();
        students[i].course = getRandomInt(1, 4);
        students[i].specialty = getRandomSpecialty();
        students[i].physics = getRandomInt(3, 5);
        students[i].math = getRandomInt(3, 5);
        students[i].informatics = getRandomInt(3, 5);
    }
}

int calculateExcellentStudents(Student* students, int numStudents) {
    int count = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].physics == 5 && students[i].math == 5 && students[i].informatics == 5) {
            ++count;
        }
    }
    return count;
}

double calculatePhysicsGradePercentage(Student* students, int numStudents, int grade) {
    int count = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].physics == grade) {
            ++count;
        }
    }
    return (static_cast<double>(count) / numStudents) * 100.0;
}

void displayStudents(Student* students, int numStudents) {
    cout << "=========================================================================\n";
    cout << "№\tПрізвище\t\tКурс\tСпеціальність\tФізика\tМатематика\tІнформатика\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << i + 1 << "\t" << std::setw(15) << students[i].surname << "\t" << std::setw(5) << students[i].course << "\t";
        switch (students[i].specialty) {
        case ComputerScience:
            cout << std::setw(15) << "ComputerScience";
            break;
        case Physics:
            cout << std::setw(15) << "Physics";
            break;
        case Mathematics:
            cout << std::setw(15) << "Mathematics";
            break;
        }
        cout << "\t" << std::setw(10) << students[i].physics << "\t" << std::setw(10) << students[i].math << "\t" << std::setw(10) << students[i].informatics << "\n";
    }
} 

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned>(time(0)));

    int numberOfStudents;
    cout << "Number of students: ";
    cin >> numberOfStudents;

    Student* students = new Student[numberOfStudents];
    createStudents(students, numberOfStudents);

    int excellentStudents = calculateExcellentStudents(students, numberOfStudents);
    double physicsGradePercentage = calculatePhysicsGradePercentage(students, numberOfStudents, 5);

    cout << "Кількість студентів, які вчаться на \"відмінно\": " << excellentStudents << std::endl;
    cout << "Відсоток студентів, які отримали з фізики оцінку \"5\": " << std::fixed << std::setprecision(2) << physicsGradePercentage << "%" << std::endl;
    displayStudents(students, numberOfStudents);

    delete[] students;

    return 0;
}
