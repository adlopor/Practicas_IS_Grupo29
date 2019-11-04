## Visualizar Tratamiento de un Paciente

**ID:** 12.
**Descripción:** Se visualiza el tratamiento de un paciente.

**Actores principales:** Administrador.

**Precondiciones:**
* Qué el paciente exista en la base de datos del sistema.


**Flujo principal:**
1. El administrador desea visualizar el tratamiento de un paciente de la base de datos del sistema.
1. El administrador busca y localiza al paciente cuyos tratamiento se va a visualizar (caso de uso <02>).
1. El sistema muestra por pantalla el tratamiento del paciente. 

**Postcondiciones:**
* Ninguno.

 
**Flujos alternativos:**
2.a. Si el paciente no existe, se muestra un mensaje de error.
