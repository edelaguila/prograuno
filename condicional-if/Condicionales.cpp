#include <iostream>

using namespace std;

int main()
{
    int Math = 0;
    int Biology = 0;

    cin >> Math;
    cin >> Biology;

    cout << Math > Biology << endl;
    cout << Math < Biology << endl;
    cout << Math >= Biology << endl;
    cout << Math <= Biology << endl;
    cout << Math == Biology << endl;
    cout << Math != Biology << endl;

    if(Math > 6)
    {
        cout << "el alumno esta aprobado";
    }else if(Math == 10)
    {
        cout << "el alumno es increible!";
    }else
    {
        cout << "el alumno esta reprobado";
    }

    switch(Biology)
    {
    case 10:
        cout << "perfecto!!!" << endl;
        break;

    case 1:
        cout << "perfecto!!!" << endl;
        break;

    case 0:
        cout << "oh no! la calificacion minima!";
        break;

    default:
        cout << ":D" << endl;
        break
    }


    return 0;
}
