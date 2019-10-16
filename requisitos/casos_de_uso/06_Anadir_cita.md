## Añadir una cita nueva para un paciente.

**ID:** 06.
**Descripción:** Se introducen los datos de la nueva cita para el paciente y el sistema lo almacena.

**Actores principales:** Administrador.

**Precondiciones:**
* Qué el paciente al que se quiera dar una nueva cita pertenezca a la base de datos.
* Qué el no haya una cita previa pendiente para el paciente.

**Flujo principal:**
1. El administrador desea ingresar en el sistema una nueva cita para un paciente determinado.
1. El administrador abre el cuadro de diálogo de añadir nueva cita.
1. El administrador busca y localiza al paciente cuyos datos se van a modificar (caso de uso <02>).
1. El administrador introduce los datos de la nueva cita que se le quiere asignar al paciente.
1. El sistema comprueba que no exista ya otra cita en la fecha y hora indicados.
1. El sistema almacena la información de la nueva cita en la base de datos.
1. El sistema muestra por pantalla, que el paciente tiene una nueva cita. 

**Postcondiciones:**
* Se muestran al administrador si la operación llevada a cabo ha tenido éxito o no.

**Flujos alternativos:**
4.a. Si no existe el paciente, se muestra un mensaje de error.
6.a. Si ya existe una cita con esa fecha y hora, se muestra un mensaje de error.
