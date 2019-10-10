## Cancelar cita.

**ID:** 08.
**Descripción:** El sistema cancela una cita existente.

**Actores principales:** Administrador.

**Precondiciones:**
* Que la cita exista en la base de datos.

**Flujo principal:**
1. El administrador desea cancelar una cita de la base de datos del sistema.
1. El administrador abre el cuadro de diálogo de cancelar una cita de la base de datos.
1. El administrador busca la cita que quiere cancelar.
1. El sistema muestra por pantalla los datos personales de la cita: Fecha, hora y nombre completo del paciente.
1. El administrador confirma en el cuadro de diálogo entrante que quiere eliminar la cita.
1. El sistema borra de la base de datos del propio sistema la cita. 
**Postcondiciones:**
* Que se haya efectuado el cambio correctamente.
* Que no se encuentre la cita en la base de datos.

**Flujos alternativos:**
4.a. Si el administrador cancela la eliminación de dicha cita de la base de datos, se vuelve al menú principal.
