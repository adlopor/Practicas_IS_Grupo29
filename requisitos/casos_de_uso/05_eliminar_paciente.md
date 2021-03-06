## Eliminar a un paciente.

**ID:** 05.
**Descripción:** Se elimina a un paciente de la base de datos.

**Actores principales:** Administrador.

**Precondiciones:**
* Qué el paciente exista en la base de datos del sistema.


**Flujo principal:**
1. El administrador desea eliminar a un paciente de la base de datos del sistema.
1. El administrador abre el cuadro de diálogo de eliminar a un paciente de la base de datos.
1. El administrador busca y localiza al paciente cuyos datos de van a eliminar (caso de uso <02>).
1. El administrador confirma en el cuadro de diálogo entrante de qué quiere eliminar.
1. El sistema borra de la base de datos del propio sistema al paciente. 

**Postcondiciones:**
* Que se haya efectuado el cambio correctamente.
* Que no se encuentre el paciente en la base de datos.
 
**Flujos alternativos:**
4.a. Si el paciente no existe, se muestra un mensaje de error.
5.a. Si el administrador cancela la eliminación de dicho paciente de la base de datos, se vuelve al menú principal.
