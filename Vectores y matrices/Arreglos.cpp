#include <iostream>

using namespace std;

void PrintCell(float Cells[], int index)
{
    cout << Cells[index] << endl;
}

void PrintMessage(string message)
{
    cout << message << endl;
}

int main()
{
    float Grades[3];
    bool Enemies[2] = { false, true };
    string Names[5] = { "Roberto", "Lucia", "Alejandro", "Ana", "Luis"};

    Grades[2] = 3.1416f;
    PrintCell(Grades, 2);
    PrintCell(Grades, 1);
    PrintCell(Grades, 0);

    cin >> Grades[0];
    PrintCell(Grades, 0);

    PrintMessage(Names[1]);

    return 0;
}
