## Buscar a un paciente en el sistema.

**ID:** 02.
**Descripción:** Se introduce uno de los datos personales de un paciente y se busca su ficha en la base de datos.

**Actores principales:** Administrador.

**Precondiciones:**
* Qué el paciente ya exista en la base de datos del sistema.

**Flujo principal:**
1. El administrador desea buscar a un paciente en el sistema.
1. El administrador abre el cuadro de diálogo de buscar a un paciente.
1. El administrador introduce uno de los datos del paciente.
1. El sistema busca al paciente en la base de datos.
1. El sistema muestra la información del paciente.
1. El sistema muestra un cuadro de acción, en el que están las opciones; ver el historial clínico del paciente, añadir una nueva cita, modificar una cita, cancelar una cita y volver al menú inicial. 

**Postcondiciones:**
* Ninguna.

**Flujos alternativos:**
5.a. Si no existe el paciente, se muestra un mensaje de error.
