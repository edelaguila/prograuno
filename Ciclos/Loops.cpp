#include <iostream>

using namespace std;

int main()
{
 /*   int Counter = 0;

    while(Counter < 100)
    {
        Counter = Counter + 1;
        cout << Counter << endl;

    }

*/
/*
    bool isHappy = true;
    char input = ' ';

    while(isHappy == true)
    {
        cout << ":D" << endl;
        cout << "Sigues feliz? (T/F)";
        cin >> input;

        if(input == 'F')
            isHappy = false;
    }
*/
/*
    bool isHappy = false;
    char input  = ' ';

    do
    {
        cout << ":D" << endl;
        cout << "Sigues feliz? (T/F)";
        cin >> input;

        if(input == 'F')
            isHappy = false;

    } while(isHappy == true);

*/
 /*   for(int i = 0; i < 10 ; i++)
    {
        cout << i << " ";
        if( i % 2 == 0)
        {
            cout << ":D numero par" << endl;
        }else
        {
             cout << "D: numero impar" << endl;
        }
    }
    */

    float Grades[5] = { 3.14f, 7.12f, 10.0f, 0.98f, -1.34f};

    for(int j = 0; j < 5 ; j++)
    {
        cout << Grades[j] << endl;
    }



     return 0;
}
