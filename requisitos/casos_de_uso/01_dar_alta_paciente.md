## Dar de alta a un paciente en el sistema.

**ID:** 01.
**Descripción:** Se introducen los datos del paciente y el sistema lo almacena.

**Actores principales:** Administrador.

**Precondiciones:**
* Qué el paciente no exista en la base de datos del sistema.

**Flujo principal:**
1. El administrador desea ingresar en el sistema a un nuevo paciente.
1. El administrador abre el cuadro de diálogo de dar de alta a un nuevo paciente.
1. El administrador introduce los datos del paciente, véase, nombre completo, teléfono de contacto, dirección postal, fecha nacimiento y pertenencia a sanidad pública o privada.
1. El sistema comprueba que el paciente no exista en la base de datos.
1. El sistema almacena la información del paciente en la base de datos.
1. El sistema muestra por pantalla, que el paciente ha sido dado de alta en la base de datos. 

**Postcondiciones:**
* Se muestran al administrador si la operación llevada a cabo ha tenido éxito o no.

**Flujos alternativos:**
5.a. Si ya existe el paciente, se muestra un mensaje de error.
5.b. Si los datos introducidos no son válidos, se muestra un mensaje de error.
