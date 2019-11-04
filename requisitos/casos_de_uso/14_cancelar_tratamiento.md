## Cancelar tratamiento.

**ID:** 14.
**Descripción:** El sistema cancela un tratamiento existente.

**Actores principales:** Administrador.

**Precondiciones:**
* Que el tratamiento exista en la base de datos.

**Flujo principal:**
1. El administrador desea cancelar un tratamiento de un paciente.
1. El administrador abre el cuadro de diálogo de cancelar una cita de la base de datos.
1. El administrador busca y localiza al paciente cuyo tratamiento se va a cancelar (caso de uso <02>).
1. El administrador abre el cuadro de diálogo de cancelar tratamiento.
1. El sistema muestra por pantalla los datos personales del tratamiento: nombre del tratamiento, fecha de inicio, fecha de finalización, periodicidad, dosis e historial de tratamientos pasados.
1. El administrador confirma en el cuadro de diálogo entrante que quiere cancelar el tratamiento.
1. El sistema marca como cancelado del propio sistema el tratamiento.

**Postcondiciones:**
* Que se haya efectuado el cambio correctamente.
* Que no se encuentre la cita en la base de datos.

**Flujos alternativos:**
5.a Si no hay un tratamiento en la base de datos, muestra un mensaje de error.
7.a. Si el administrador anula la cancelación de dicho tratamiento, se vuelve al menú principal.
