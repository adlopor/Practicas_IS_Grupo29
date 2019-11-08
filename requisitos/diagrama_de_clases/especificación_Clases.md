
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




