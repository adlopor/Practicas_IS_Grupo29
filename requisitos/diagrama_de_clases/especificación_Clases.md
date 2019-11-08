
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
| +cargarPaciente : Función mediante la cual se dará de alta a un paciente dentro del sistema |
| +guardarPaciente : Función mediante la cual se guardarán datos y actualizaciones de la información de un paciente dentro del sistema |
| +borrarPaciente : Función mediante la cual se borrará a un paciente dentro del sistema después de un período largo de inactividad |






| Clase: Cita |
| -- |
| Descripción | 
| Esta  clase  contendrá  las  funciones e información referentes a las citas de los distintos pacientes. |  
| Datos | 
| -fecha(string ) : Indica la fecha en la que la cita tendrá lugar |
| -hora (string) : Indica la hora en la que la cita tendrá lugar |
| Métodos | 
| +cargarCita : Función mediante la cuál se introducirá la cita de un paciente dentro del sistema |
| +guardarCita : Función mediante la cual se guardarán los datos y actualizaciones de la cita de un paciente dentro del sistema |
| +borrarCita :  Función mediante la cual se anulará la cita de un paciente |



| Clase: Registro de historial |
| -- |
| Descripción | 
| Esta  clase  contendrá  las  funciones e información referentes al historial clínico de los distintos pacientes. |  
| Datos | 
| -motivo de consulta (string ) : Indica el motivo por el que el paciente ha acudido a la clínica |
| -fecha (string) : Indica la hora en la que la consulta ha tenido lugar |
| Métodos | 
| +cargarHistorial : Función mediante la cuál se crea el historial médico de un paciente tras su primera visita a la clínica. |
| +guardarHistorial : Función mediante la cual se guardarán los datos y actualizaciones del historial médico de un paciente dentro del sistema. |
| +borrarHistorial :  Función mediante la cual se eliminará el historial médico de un paciente tras un largo periodo de inactividad. |




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
| Métodos | 
| +cargarTratamiento : Función mediante la cual se añade un nuevo tratamiento a uno de los pacientes dentro del sistema |
| +guardarTratamiento : Función mediante la cual se guardarán los datos y actualizaciones que los tratamientos de un paciente dentro del sistema sufran |
| +borrarTratamiento : Función mediante la cual se borrará uno de los tratamientos asignados a un paciente |




