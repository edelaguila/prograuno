#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Creación de Archivo
    ofstream myfile ("GameData.txt");
    string NewName;
    cout << "Ingrese su nombre: " << endl;
    cin >> NewName;
    if (myfile.is_open())
    {
        myfile << "Nombre:" << endl;
        myfile << NewName << endl;
        myfile << "Alumno de Programación III" << endl;
        myfile.close();
    }
    else
        cout << "Unable to open file";
    //Lectura de archivo
    string line;
    string PlayerName;
    int lineCount = 0;
    ifstream myfileRead ("GameData.txt");

      if (myfileRead.is_open())
      {
        while ( getline (myfileRead,line) )
        {
            //cout << line << endl;
          //  cout << line<< endl;
          if(lineCount == 2)
            {
                PlayerName = line;
            }

            lineCount++;
        }
        myfileRead.close();
      }else
      {
          cout << "Unable to open file";
      }
      cout << "lectura el archivo " << endl;
      cout << PlayerName;
     return 0;
}
