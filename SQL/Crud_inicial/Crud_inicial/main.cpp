#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <stdio.h>

using namespace std;
MYSQL *conn;
MYSQL_ROW row;
MYSQL_RES *res;

bool conexion();
void agregarRegistros();
void editarRegistros();
void buscarRegistros();
void verRegistros();

int main()
{

    bool mantieneCiclo=true;
    int respuesta;
    bool Conectar;
    Conectar=conexion();

    while(mantieneCiclo){
        cout << "Menu General Inventario" << endl;
        cout << endl << endl << "---------------" << endl << endl << "1. Agregar registro" << endl << "2. Editar registro" << endl << "3. Buscar" << endl << "4. Ver registros" << endl << "5. Salir del sistema" << endl << endl << endl << "---------------" << endl;
        cout << endl << "Respuesta : ";
        cin >> respuesta;
        switch(respuesta){
        case 1:
            agregarRegistros();
            break;
        case 2:
            editarRegistros();
            break;
        case 3:
            buscarRegistros();
            break;
        case 4:
            verRegistros();
            break;
        case 5:
            mantieneCiclo=false;
            break;
        }
    }
    return 0;
}

bool conexion()
{
    conn = mysql_init(0);
    conn = mysql_real_connect(conn,"localhost","UsuPrueba","123456","didactica",0,NULL,0);
    if(conn){
        system("color a");
        cout<<"Coneccion con la Base de Datos exitosa!!!" << endl;
        return true;

    }else{
         system("color c");
        cout<<"Coneccion con la Base de Datos fallo" << endl;
        return false;
    }
}

void agregarRegistros(){
    string dummy;
    if(conn){
        int qstate = 0, cantidad;
        string nombre, posicion;

        cout << "ingrese nombre : ";
        cin >> nombre;

        cout << "ingrese posicion : ";
        cin >> posicion;

        cout << "ingrese cantidad : ";
        cin >> cantidad;

        stringstream ss;
        ss << "INSERT INTO tbl_inventario(nombre, posicion, cantidad) VALUES('" << nombre << "','" << posicion << "'," << cantidad <<")";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Registro insertado..." << endl;
            cout << "Presione B para regresar";
            cin >> dummy;
        }else{
            cout << "Error en la insercion" << mysql_error(conn) << endl;
            cout << "Presione B para regresar";
            cin >> dummy;
        }
    }else{
        cout << "Error en coneccion" << endl;
        cout << "Presione B para regresar";
        cin >> dummy;
    }

    system("pause");
    system("cls");

}

void editarRegistros(){
    string dummy;
    if(conn){
        int qstate = 0;
        string nombre;
        int cantidad;
        cout << "ingrese nombre : ";
        cin >> nombre;
        cout << "ingrese cantidad : ";
        cin >> cantidad;

        stringstream ss;
        ss << "UPDATE tbl_inventario SET cantidad = cantidad + " << cantidad << " WHERE nombre = '" << nombre << "'";

        string query = ss.str();

        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "Registro actualizado..." << endl;
            cout << "Presione B para regresar";
            cin >> dummy;
        }else{
            cout << "Error en insercion" << mysql_error(conn) << endl;
            cout << "Presione B para regresar";
            cin >> dummy;
        }
    }else{
        cout << "Error en coneccion" << endl;
        cout << "Presione B para regresar";
        cin >> dummy;
    }

    system("pause");
    system("cls");

}

void buscarRegistros(){
    string dummy;
    if(conn){

    string nombre;
    int id;
    cout << "ingrese codigo : ";
    cin >> id;
    if(conn){
        stringstream ss;
        ss << "SELECT id, nombre, posicion, cantidad FROM tbl_inventario WHERE id = '" << id << "'";

        string query = ss.str();

        const char* q = query.c_str();

        int qstate = mysql_query(conn, q);

        if(!qstate){
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] << endl << endl;
             }
        }
    }
    }

    cout << "Presione B para regresar";
    cin >> dummy;

    system("pause");
    system("cls");
}

void verRegistros(){
    string dummy;
    if(conn){
        int qstate = mysql_query(conn, "SELECT id, nombre, posicion, cantidad FROM tbl_inventario");

        if(!qstate){
            res = mysql_store_result(conn);
            while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[1] <<"\t | \t" << row[2] <<"\t | \t" << row[3] << endl << endl;
             }
        }
    }

    cout << "Presione B para regresar";
    cin >> dummy;

    system("pause");
    system("cls");
}
