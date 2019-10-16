## Añadir un tratamiento nuevo para un paciente.

**ID:** 12.
**Descripción:** Se introducen los datos del nuevo tratamiento para el paciente y el sistema lo almacena.

**Actores principales:** Administrador.

**Precondiciones:**
* Qué el paciente pertenezca a la base de datos.
* Qué el no haya un tratamiento igual previo para el paciente.

**Flujo principal:**
1. El administrador desea ingresar en el sistema un nuevo tratamiento para un paciente determinado.
1. El administrador abre el cuadro de diálogo de añadir nuevo tratamiento.
1. El administrador busca y localiza al paciente cuyos datos se van a modificar (caso de uso <02>).
1. El administrador introduce los datos del nuevo tratamiento que se le quiere asignar al paciente.
1. El sistema comprueba que no exista ya otro tratamiento igual.
1. El sistema almacena la información del nuevo tratamiento en la base de datos.
1. El sistema muestra por pantalla, que el paciente tiene un nuevo tratamiento. 

**Postcondiciones:**
* Se muestran al administrador si la operación llevada a cabo ha tenido éxito o no.

**Flujos alternativos:**
4.a. Si no existe el paciente, se muestra un mensaje de error.
6.a. Si ya existe dicho tratamiento, se muestra un mensaje de error.
