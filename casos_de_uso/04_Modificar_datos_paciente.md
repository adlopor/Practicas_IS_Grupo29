## Modificar los datos personales de un paciente.

**ID:** 04.
**Descripción:** Se modifican los datos personales del paciente.

**Actores principales:** Administrador.

**Precondiciones:**
* Qué el paciente exista en la base de datos del sistema.


**Flujo principal:**
1. El administrador desea modificar a un paciente de la base de datos del sistema.
1. El administrador busca y localiza al paciente cuyos datos se van a modificar (caso de uso <02>).
1. El administrador introduce los nuevos datos del paciente, véase, nombre completo, teléfono de contacto, dirección postal, fecha nacimiento y pertenencia a sanidad pública o privada.
1. El sistema comprueba que el paciente modificado tenga los mismos datos que otro paciente de la base de datos.
1. El sistema muestra por pantalla los nuevos datos del paciente.
1. El administrador, mediante un cuadro de diálogo, le da el visto bueno a la modificación.
1. El sistema almacena la información del paciente en la base de datos.
1. El sistema muestra por pantalla, que el paciente ha sido modificado. 

**Postcondiciones:**
* Que se haya efectuado el cambio correctamente.

 
**Flujos alternativos:**
2.a. Si el paciente no existe, se muestra un mensaje de error.
5.a. Si los datos introducidos no son válidos, se muestra un mensaje de error.
5.b. Si el paciente modificado, coincide con otro paciente en cuánto a datos se refiere, se muestra un mensaje de error.
7.a. Si el administrador no confirma los cambios, los datos del paciente no se modifican.
