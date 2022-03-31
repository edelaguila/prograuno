// Fig. 14.15: fig14_15.cpp
// Este programa lee un archivo de acceso aleatorio en forma secuencial, actualiza
// los datos previamente escritos en el archivo, crea datos para colocarlos
// en el archivo y elimina los datos que estaban previamente en el archivo.
#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
#include "datosCliente.h"  // definición de la clase DatosCliente

int escribirOpcion();
void imprimirRegistro( fstream& );
void actualizarRegistro( fstream& );
void nuevoRegistro( fstream& );
void eliminarRegistro( fstream& );
void mostrarLinea( ostream&, const DatosCliente & );
int obtenerCuenta( const char * const );
void crearArchivoCredito();
void consultarRegistro( fstream& );
void mostrarLineaPantalla( const DatosCliente &);

enum Opciones { IMPRIMIR = 1, ACTUALIZAR, NUEVO, ELIMINAR, CONSULTAR, FIN };

int main()
{

   // abrir el archivo en modo de lectura y escritura
   fstream creditoEntradaSalida( "credito.dat", ios::in | ios::out | ios::binary);

   // salir del programa si fstream no puede abrir el archivo
   if ( !creditoEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      crearArchivoCredito();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

   } // fin de instrucción if

   int opcion;

   // permitir al usuario que especifique la acción
   while ( ( opcion = escribirOpcion() ) != FIN ) {

      switch ( opcion ) {

         // crear el archivo de texto a partir del archivo de registros
         case IMPRIMIR:
            imprimirRegistro( creditoEntradaSalida );
            break;

         // actualizar registro
         case ACTUALIZAR:
            actualizarRegistro( creditoEntradaSalida );
            break;

         // crear registro
         case NUEVO:
            nuevoRegistro( creditoEntradaSalida );
            break;

         // eliminar registro existente
         case ELIMINAR:
            eliminarRegistro( creditoEntradaSalida );
            break;
         // consultar registros existentes por pantalla
         case CONSULTAR:
            consultarRegistro( creditoEntradaSalida );
            break;
         // mostrar error si el usuario no selecciona una opción válida
         default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } // fin de instrucción switch

      creditoEntradaSalida.clear(); // reinicializar indicador de fin de archivo

   } // fin de instrucción while

   return 0;

} // fin de main

// permitir al usuario que introduzca la opción del menú
int escribirOpcion()
{
   // mostrar opciones disponibles
   cout << "\nEscriba su opcion" << endl
        << "1 - guardar un archivo de texto de las cuentas con formato" << endl
        << "    llamado \"imprimir.txt\" para imprimirlo" << endl
        << "2 - actualizar una cuenta" << endl
        << "3 - agregar una nueva cuenta" << endl
        << "4 - eliminar una cuenta" << endl
        << "5 - consultar por pantalla" << endl
        << "6 - finalizar el programa\n? ";

   int opcionMenu;
   cin >> opcionMenu; // recibir opción del usuario

   return opcionMenu;

} // fin de la función escribirOpcion

// crear archivo de texto con formato para imprimirlo
void imprimirRegistro( fstream &leerDeArchivo )
{
   // crear archivo de texto
   ofstream archivoImprimirSalida( "imprimir.txt", ios::out );

   // salir del programa si ofstream no puede crear el archivo
   if ( !archivoImprimirSalida ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   archivoImprimirSalida << left << setw( 10 ) << "Cuenta" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" << right
       << setw( 10 ) << "Saldo" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   DatosCliente cliente;
   leerDeArchivo.read( reinterpret_cast< char * >( &cliente ),
      sizeof( DatosCliente ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( cliente.obtenerNumeroCuenta() != 0 )
         mostrarLinea( archivoImprimirSalida, cliente );

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &cliente ),
         sizeof( DatosCliente ) );

   } // fin de instrucción while

} // fin de la función imprimirRegistro

// actualizar el saldo en el registro
void actualizarRegistro( fstream &actualizarArchivo )
{
   // obtener el número de cuenta a actualizar
   int numeroCuenta = obtenerCuenta( "Escriba la cuenta que desea actualizar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   actualizarArchivo.seekg(
      ( numeroCuenta - 1 ) * sizeof( DatosCliente ) );

   // leer el primer registro del archivo
   DatosCliente cliente;
   actualizarArchivo.read( reinterpret_cast< char * >( &cliente ),
      sizeof( DatosCliente ) );

   // actualizar el registro
   if ( cliente.obtenerNumeroCuenta() != 0 ) {
      mostrarLinea( cout, cliente );

      // solicitar al usuario que especifique la transacción
      cout << "\nEscriba cargo (+) o abono (-): ";
      double transaccion; // cargo o abono
      cin >> transaccion;

      // actualizar el saldo del registro
      double saldoAnterior = cliente.obtenerSaldo();
      cliente.establecerSaldo( saldoAnterior + transaccion );
      mostrarLinea( cout, cliente );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      actualizarArchivo.seekp(
         ( numeroCuenta - 1 ) * sizeof( DatosCliente ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      actualizarArchivo.write(
         reinterpret_cast< const char * >( &cliente ),
         sizeof( DatosCliente ) );

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "La cuenta #" << numeroCuenta
         << " no tiene informacion." << endl;

} // fin de la función actualizarRegistro

// crear e insertar registro
void nuevoRegistro( fstream &insertarEnArchivo )
{
   // obtener el número de cuenta a crear
   int numeroCuenta = obtenerCuenta( "Escriba el nuevo numero de cuenta" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   insertarEnArchivo.seekg(
      ( numeroCuenta - 1 ) * sizeof( DatosCliente ) );

   // leer el registro del archivo
   DatosCliente cliente;
   insertarEnArchivo.read( reinterpret_cast< char * >( &cliente ),
      sizeof( DatosCliente ) );

   // crear el registro, si éste no existe ya
   if ( cliente.obtenerNumeroCuenta() == 0 ) {

      char apellido[ 15 ];
      char primerNombre[ 10 ];
      double saldo;

      // el usuario introduce el apellido, primer nombre y saldo
      cout << "Escriba el apellido : " << endl;
      cin >> setw( 15 ) >> apellido;
      cout << "Escriba el nombre: " << endl;
      cin >> setw( 10 ) >> primerNombre;
      cout << "Escriba el saldo: " << endl;
      cin >> saldo;

      // usar valores para llenar los valores de la cuenta
      cliente.establecerApellido( apellido );
      cliente.establecerPrimerNombre( primerNombre );
      cliente.establecerSaldo( saldo );
      cliente.establecerNumeroCuenta( numeroCuenta );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      insertarEnArchivo.seekp( ( numeroCuenta - 1 ) *
         sizeof( DatosCliente ) );

      // insertar el registro en el archivo
      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &cliente ),
         sizeof( DatosCliente ) );

   } // fin de instrucción if

   // mostrar error si la cuenta ya existe
   else
      cerr << "La cuenta #" << numeroCuenta
           << " ya contiene informacion." << endl;

} // fin de la función nuevoRegistro

// eliminar un registro existente
void eliminarRegistro( fstream &eliminarDeArchivo )
{
   // obtener número de cuenta a eliminar
   int numeroCuenta = obtenerCuenta( "Escriba la cuenta a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   eliminarDeArchivo.seekg(
      ( numeroCuenta - 1 ) * sizeof( DatosCliente ) );

   // leer el registro del archivo
   DatosCliente cliente;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &cliente ),
      sizeof( DatosCliente ) );

   // eliminar el registro, si es que existe en el archivo
   if ( cliente.obtenerNumeroCuenta() != 0 ) {
      DatosCliente clienteEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      eliminarDeArchivo.seekp( ( numeroCuenta - 1 ) *
         sizeof( DatosCliente ) );

      // reemplazar el registro existente con un registro en blanco
      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( DatosCliente ) );

      cout << "Cuenta #" << numeroCuenta << " eliminada.\n";

   } // fin de instrucción if

   // mostrar error si el registro no existe
   else
      cerr << "La cuenta #" << numeroCuenta << " esta vacia.\n";

} // fin de eliminarRegistro
void consultarRegistro( fstream &leerDeArchivo )
{

   cout << left << setw( 10 ) << "Cuenta" << setw( 16 )
       << "Apellido" << setw( 14 ) << "Primer nombre" << right
       << setw( 10 ) << "Saldo" << endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   leerDeArchivo.seekg( 0 );

   // leer el primer registro del archivo de registros
   DatosCliente cliente;
   leerDeArchivo.read( reinterpret_cast< char * >( &cliente ),
      sizeof( DatosCliente ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !leerDeArchivo.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( cliente.obtenerNumeroCuenta() != 0 )
         mostrarLineaPantalla(cliente);

      // leer siguiente registro del archivo de registros
      leerDeArchivo.read( reinterpret_cast< char * >( &cliente ),
         sizeof( DatosCliente ) );

   } // fin de instrucción while

} // fin de la función consultarRegistro

// mostrar registro individual
void mostrarLinea( ostream &salida, const DatosCliente &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroCuenta()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSaldo() << endl;

} // fin de la función mostrarLinea
void mostrarLineaPantalla( const DatosCliente &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroCuenta()
          << setw( 16 ) << registro.obtenerApellido().data()
          << setw( 14 ) << registro.obtenerPrimerNombre().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSaldo() << endl;

} // fin de la función mostrarLineaPantalla

// obtener el valor del número de cuenta del usuario
int obtenerCuenta( const char * const indicador )
{
   int numeroCuenta;

   // obtener el valor del número de cuenta
   do {
      cout << indicador << " (1 - 100): ";
      cin >> numeroCuenta;

   } while ( numeroCuenta < 1 || numeroCuenta > 100 );

   return numeroCuenta;

} // fin de la función obtenerCuenta
void crearArchivoCredito()
{
    ofstream creditoSalida( "credito.dat", ios::out | ios::binary );
   // salir del programa si ofstream no pudo abrir el archivo
   if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   // crear DatosCliente sin información
   DatosCliente clienteEnBlanco;

   // escribir 100 registros en blanco en el archivo
   for ( int i = 0; i < 100; i++ )
      creditoSalida.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( DatosCliente ) );
}

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
