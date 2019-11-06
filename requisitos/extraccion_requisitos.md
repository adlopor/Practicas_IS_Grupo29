## Extracción de requisitos

#### Partes interesadas:

* Desarrollador.
* Administrador.

#### Datos que gestiona el sistema:

* Pacientes:
  * Nombre.
  * Apellidos.
  * Teléfono.
  * Dirección postal.
  * Fecha nacimiento.
  * Sanidad pública o privada.

* Cita:
  * Fecha.
  * Hora.
  * Paciente.
  
* Historial:
  * Paciente.
  * Fecha
  * Motivo de consulta.
  
* Tratamiento:
  * Paciente.
  * Nombre.
  * Fecha de inicio.
  * Fecha de finalización.
  * Periodicidad.
  * Dosis.
  * Historial tratamientos pasados.

	
#### Requisitos funcionales (ordenados por prioridad):
1. Dar de alta un paciente.
1. Buscar paciente.
1. Generar lista de pacientes.
1. Modificar datos paciente.
1. Eliminar paciente.
1. Consultar citas de un paciente.
1. Añadir nueva cita.
1. Modificar cita.
1. Cancelar cita.
1. Ver historial clínico del paciente.
1. Añadir información al historial clínico.
1. Visualizar tratamientos.
1. Añadir tratamiento.
1. Cancelar tratamiento
1. Visualizar citas día actual.




#### Requisitos no funcionales:
* Sistema operativo Linux.
* Interfaz human friendly.
* Lenguaje de implementación: C++.
* Confirmación de elimación paciente.
