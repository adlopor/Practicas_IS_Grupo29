## Consultar las citas de un paciente.

**ID:** 06.
**Descripción:** El sistema muestra las citas de un paciente.

**Actores principales:** Administrador.

**Precondiciones:**
* Que el paciente exista en la base de datos.

**Flujo principal:**
1. El administrador desea mostrar las citas de un paciente en la pantalla.
1. El administrador abre el cuadro de diálogo de ver el historial de citas de un paciente.
1. El administrador busca y localiza al paciente cuyos datos se van a modificar (caso de uso <02>).
1. El administrador abre el cuadro de diálogo de consultar historial de citas de un paciente.
1. El sistema muestra por pantalla los datos personales del paciente (nombre completo, teléfono, dirección postal, fecha de nacimiento y tipo de sanidad contratada) junto con todas las citas de este.

**Postcondiciones:**
* Ninguna.

**Flujos alternativos:**
5.a. Si el paciente no ha tenido una cita todavía, se mostrará un mensaje aclarándolo.
