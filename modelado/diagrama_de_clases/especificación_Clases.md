
| Clase: Paciente |
| -- |
| Descripción | 
| Esta  clase  contendrá  las  funciones  del paciente. Entre ellas se encuentra la de cargar un paciente en el sistema y la de borrar paciente. |  
| Datos | 
| -nombre (string): Nombre del paciente dentro del sistema |
| -apellidos (string) : Apellidos del paciente dentro del sistema |
| -teléfono (string) : Teléfono del paciente |
| -dirección postal (string) : Dirección postal del paciente a la que se le mandarán las citas |
| -fecha de nacimiento (string) : Fecha de nacimiento del paciente |
| -tarjeta sanitaria (boolean) : Adoptará valor true si el paciente viene de la seguridad pública y false si viene de la privada |
| Métodos | 
| +cargarPaciente : Función mediante la cual se buscará a un paciente dentro de la base de datos del sistema |
| +guardarPaciente : Función mediante la cual se añadirán y guardarán los datos y actualizaciones de la información de un paciente dentro del sistema |
| +borrarPaciente : Función mediante la cual se busca a un paciente dentro de la base de datos del sistema y se elimina |
| +buscarPaciente : Función mediante la cual se busca a un paciente dentro de la base de datos del sistema.
| +cargarCita : Función mediante la cuál se buscará la cita de un paciente dentro de la base de datos del sistema |
| +guardarCita : Función mediante la cual se añadirán y guardarán los datos y actualizaciones de la cita de un paciente dentro del sistema |
| +borrarCita :  Función mediante la cual se buscará una cita concreta mediante la fecha y se anulará. |
| +buscarCita : Función mediante la cual se busca una cita dentro de la base de datos del sistema.
| +cargarHistorial : Función mediante la cuál se buscará el historial médico de un paciente dentro de la base de datos del sistema |
| +guardarHistorial : Función mediante la cual se añadirá y guardará información en el  historial médico de uno de los pacientes dentro del sistema. |
| +borrarHistorial : Función mediante la cual se buscará el historial médico de uno de los pacientes contenidos en la base de datos del sistema y se eliminará.|
| +cargarTratamiento : Función mediante la cual se buscará un tratamiento dentro de la base de datos del sistema |
| +guardarTratamiento : Función mediante la cual se añadirán nuevos tratamientos y se guardarán las actualizaciones que los tratamientos de un paciente dentro del sistema sufran |
| +borrarTratamiento : Función mediante la cual se buscará uno de los tratamientos de la base de datos del sistema y se eliminará. |
| +buscarTratamiento : Función mediante la cual se busca un tratamiento dentro de la base de datos del sistema.






| Clase: Cita |
| -- |
| Descripción | 
| Esta  clase  contendrá  las  funciones e información referentes a las citas de los distintos pacientes. |  
| Datos | 
| -fecha(string ) : Indica la fecha en la que la cita tendrá lugar |
| -hora (string) : Indica la hora en la que la cita tendrá lugar |




| Clase: Registro de historial |
| -- |
| Descripción | 
| Esta  clase  contendrá  las  funciones e información referentes al historial clínico de los distintos pacientes. |  
| Datos | 
| -motivo de consulta (string ) : Indica el motivo por el que el paciente ha acudido a la clínica |
| -fecha (string) : Indica la hora en la que la consulta ha tenido lugar |





| Clase: Tratamiento |
| -- |
| Descripción | 
| Esta  clase  contendrá  las  funciones e información referente a los distintos tratamientos asignados a los pacientes dentro del sistema. |  
| Datos | 
| -nombre (string): Nombre del tratamiento |
| -fecha de inicio (string) : fecha en la que el paciente comienza a tomar el tratamiento |
| -fecha de fin (string) : fecha en la que el paciente termina de tomar el tratamiento |
| -periocidad (string) : Indica cada cuanto tiempo el paciente debe tomar el tratamiento asignado |
| -dosis(string) : Indica la dosis del tratamieto asignado que el paciente debe de tomar |





