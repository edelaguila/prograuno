// Fig. 14.10: datosCliente.h
// La definición de la clase DatosCliente utilizada en las figs. 14.12-14.15.
#ifndef DATOSCLIENTE_H
#define DATOSCLIENTE_H

#include <iostream>

using std::string;

class DatosCliente {

public:

   // constructor predeterminado de DatosCliente constructor
   DatosCliente( int = 0, string = "", string = "", double = 0.0 );

   // funciones de acceso para numeroCuenta
   void establecerNumeroCuenta( int );
   int obtenerNumeroCuenta() const;

   // funciones de acceso para apellido
   void establecerApellido( string );
   string obtenerApellido() const;

   // funciones de acceso para primerNombre
   void establecerPrimerNombre( string );
   string obtenerPrimerNombre() const;

   // funciones de acceso para el saldo
   void establecerSaldo( double );
   double obtenerSaldo() const;

private:
   int numeroCuenta;
   char apellido[ 15 ];
   char primerNombre[ 10 ];
   double saldo;

}; // fin de la clase DatosCliente

#endif

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


