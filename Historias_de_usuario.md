**ID**: 01
**Nombre**: Dar de alta a un paciente en el sistema

**Prioridad** (de 1 a 10): 1
**Puntos estimado**: 3
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *poder dar de alta a un paciente* para *tenerlo dentro del sistema y poder guardar información personal y clínica sobre ese paciente*

#### Validación

* Se debe poder dar de alta a cualquier paciente que no esté dentro del sistema
* Se debe introducir la información personal de cada paciente para poder darlo de alta
* Es necesario utilizar el nombre completo
* Una vez dado de alta el paciente ha de aparecer en la base de datos
* Se debe poder concertar una cita para el paciente dado de alta
* Se debe poder incorporar un historial médico
* Se debe poder incorporar información sobre tratamientos para el paciente




**ID**: 02
**Nombre**: Buscar usuario por nombre completo

**Prioridad** (de 1 a 10): 2
**Puntos estimado**: 3
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *localizar a un paciente* para *consultar su información personal e historial médico*

#### Validación

* Se debe poder localizar cualquier paciente
* Los resultados de la búsqueda han de ofrecer un solo resultado
* Es necesario utilizar el nombre completo
* Se deben mostrar todos los datos del paciente
* Se debe mostrar el historial médico del paciente
* Se deben mostrar los tratamientos que el paciente ha recibido





**ID**: 03
**Nombre**: Generar una lista de los pacientes dentro del sistema

**Prioridad** (de 1 a 10): 3
**Puntos estimado**: 1
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *poder generar una lista de pacientes* para *ver los pacientes que hay dentro del sistema*

#### Validación

* Deben aparecer todos los pacientes del sistema
* Se debe mostrar su nombre completo


**ID**: 04
**Nombre**: Modificar datos del paciente

**Prioridad** (de 1 a 10): 4
**Puntos estimado**: 2
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *poder modificar los datos de los pacientes* para *tener la información actualizada*

#### Validación

* Se deben poder actualizar los datos de cualquier paciente que esté dado de alta en el sistema
* Se deben eliminar los datos absoletos de cada paciente
* La nueva información sobre el paciente ha de quedar guardada correctamente dentro del sistema




**ID**: 05
**Nombre**: Eliminar paciente dentro del sistema

**Prioridad** (de 1 a 10): 5
**Puntos estimado**: 1
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *poder eliminar a un paciente * para *tener un sistema actualizado*

#### Validación

* Se debe poder eliminar cualquier paciente del que no se haya hecho ningún seguimiento en dos años.
* Se debe eliminar cualquier registro personal del usuario, incluido el historial clínico.
* Se debe eliminar el paciente de la base de datos.




**ID**: 06
**Nombre**: Añadir cita

**Prioridad** (de 1 a 10): 6
**Puntos estimado**: 3
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *poder añadir una cita* para *poder dar hora de consulta a un paciente*

#### Validación

* Se debe poder añadir una cita para cualquier paciente dado de alta dentro del sistema.
* Se debe establecer una fecha
* Se debe establecer una hora
* Debe aparecer el nombre completo del paciente
* Se debe comprobar que no hay una cita establecida con anterioridad que tenga la fecha y hora deseadas para poder añadir la nueva cita



**ID**: 07
**Nombre**: Modificar cita

**Prioridad** (de 1 a 10): 7
**Puntos estimado**: 2
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *poder modificar una cita* para *poder cambiar la fecha y/o hora de la misma*

#### Validación

* Se debe haber añadido esa cita con anterioridad para poder modificarla 
* Se debe poder modificar la fecha
* Se debe poder modificar la hora
* Se deben guardar los cambios dentro del sistema



**ID**: 08
**Nombre**: Cancelar cita

**Prioridad** (de 1 a 10): 8
**Puntos estimado**: 1
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *poder cancelar una cita* para *aquellos pacientes que no puedan asistir*

#### Validación

* Se debe poder eliminar cualquier cita añadida con anterioridad que aún no haya pasado
* Se debe eliminar totalmente del sistema



**ID**: 09
**Nombre**: Ver historial clínico del paciente

**Prioridad** (de 1 a 10): 9
**Puntos estimado**: 1
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *poder ver el historial del paciente* para *poder conocer sus enfermedades*

#### Validación

* Se debe poder ver el historial clínico de cualquier paciente dado de alta 


**ID**: 10
**Nombre**: Visualizar citas del día actual

**Prioridad** (de 1 a 10): 10
**Puntos estimado**: 2
**Iteración**: 1

**Responsable**: Grupo 29

#### Descripción

Como *administrador* quiero *poder visualizar las citas del día actual* para *conocer que pacientes vendrán a consulta ese día*

#### Validación

* Se deben visualizar todas las citas para el día actual
* Se debe visualizar el nombre completo del paciente
* Se debe visualizar la hora
* Se debe comprobar que no aparezcan las citas canceladas


