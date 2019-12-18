OBJETOS = main.o funcionesAuxiliares.o paciente.o historial.o tratamiento.o cita.o

CPPFLAGS = -c -g -Wall -ansi

INCLUDES = 		main.hpp \
				funcionesAuxiliares.hpp \
				paciente.hpp
				cita.hpp historial.hpp tratamiento.hpp \


objetivo: main.exe

#Opciones para NO depurar
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

#Para general a documentacion
doc: Doxyfile 
		doxygen

main.exe: $(OBJETOS)
				g++ $(OBJETOS) -o main.exe

funcionesAuxiliares.o: funcionesAuxiliares.cpp funcionesAuxiliares.hpp paciente.hpp $(INCLUDES)
							g++ $(CPPFLAGS) funcionesAuxiliares.cpp

paciente.o: 	paciente.cpp paciente.hpp cita.hpp historial.hpp tratamiento.hpp $(INCLUDES)
					g++ $(CPPFLAGS) paciente.cpp

cita.o: cita.cpp cita.hpp
					g++ $(CPPFLAGS) cita.cpp

historial.o: historial.cpp historial.hpp
					g++ $(CPPFLAGS) historial.cpp

tratamiento.o: tratamiento.cpp tratamiento.hpp
					g++ $(CPPFLAGS) tratamiento.cpp

clean:
	rm -rf *~ $(OBJETOS)

