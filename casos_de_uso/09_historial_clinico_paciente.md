## Ver el historial clínico del paciente.

**ID:** 09.
**Descripción:** El sistema muestra el historial clínico de un paciente.

**Actores principales:** Administrador.

**Precondiciones:**
* Que el paciente exista en la base de datos.

**Flujo principal:**
1. El administrador desea mostrar el historial clínico de un paciente en la pantalla.
1. El administrador abre el cuadro de diálogo de ver el historial clínico de un paciente.
1. El administrador busca y localiza al paciente cuyos datos se van a modificar (caso de uso <02>).
1. El administrador abre el cuadro de diálogo de consultar el historial clínico de un paciente.
1. El sistema muestra por pantalla los datos personales del paciente (nombre completo, teléfono, dirección postal, fecha de nacimiento y tipo de sanidad contratada), así como las citas previas que ha realizado, con sus correspondientes datos y los tratamientos que han sido recetados.


**Postcondiciones:**
* Ninguna.

**Flujos alternativos:**
5.a. Si el paciente no ha tenido una cita todavía, se mostrará un mensaje aclarándolo.
