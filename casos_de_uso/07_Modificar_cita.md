## Modificar cita.

**ID:** 07.
**Descripción:** El sistema modifica una cita existente.

**Actores principales:** Administrador.

**Precondiciones:**
* Que la cita exista en la base de datos.

**Flujo principal:**
1. El administrador desea modificar una cita de la base de datos del sistema.
1. El administrador abre el cuadro de diálogo de modificar los datos de una cita.
1. El administrador busca la cita que quiere modificar.
1. El administrador introduce los nuevos datos de la cita, véase: Nombre completo del paciente, fecha y hora.
1. El sistema comprueba que la cita modificada no tenga la misma fecha que otra cita de la base de datos.
1. El sistema muestra por pantalla los nuevos datos de la cita.
1. El administrador, mediante un cuadro de diálogo, le da el visto bueno a la modificación.
1. El sistema almacena la información de la cita en la base de datos.
1. El sistema muestra por pantalla, que la cita ha sido modificado. 

**Postcondiciones:**
* Se muestran al administrador si la operación llevada a cabo ha tenido éxito o no.

**Flujos alternativos:**
5.a. Si no modifica ningún campo, se mostrará una advertencia.
5.b. Si los datos introducidos no son válidos, se muestra un mensaje de error.
