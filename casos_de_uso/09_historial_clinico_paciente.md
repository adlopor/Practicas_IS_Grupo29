## Ver el historial clínico del paciente.

**ID:** 09.
**Descripción:** El sistema muestra el historial clínico de un paciente.

**Actores principales:** Administrador.

**Precondiciones:**
* Que el paciente exista en la base de datos.

**Flujo principal:**
1. El administrador desea mostrar el historial clínico de un paciente en la pantalla.
1. El administrador abre el cuadro de diálogo de ver el historial clínico de un paciente.
1. El administrador introduce el nombre completo del paciente para identificarlo.
1. El sistema comprueba que el paciente existe.
1. El sistema muestra por pantalla el nombre completo del paciente así como las citas previas que ha realizado, con sus correspondientes datos.

**Postcondiciones:**
* Ninguna.

**Flujos alternativos:**
4.a. Si el paciente no ha asistido anteriormente, se mostrará un mensaje aclarándolo.
