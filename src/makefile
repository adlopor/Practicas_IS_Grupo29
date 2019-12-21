OBJETOS = historial.o tratamiento.o cita.o paciente.o funcionesAuxiliares.o main.o

CPPFLAGS = -c -g -Wall -ansi

INCLUDES = 	funcionesAuxiliares.hpp \
					paciente.hpp \
						cita.hpp \
						historial.hpp \
						tratamiento.hpp \


objetivo: main.exe

#Opciones para NO depurar
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

#Para general a documentacion
doc: Doxyfile 
		doxygen

main.exe: $(OBJETOS)
																	g++ $(OBJETOS) -o main.exe

main.o: main.cpp $(INCLUDES)
																	g++ $(CPPFLAGS) main.cpp
								
funcionesAuxiliares.o: funcionesAuxiliares.cpp funcionesAuxiliares.hpp paciente.hpp
																	g++ $(CPPFLAGS) funcionesAuxiliares.cpp

paciente.o: 	paciente.cpp paciente.hpp cita.hpp historial.hpp tratamiento.hpp
																	g++ $(CPPFLAGS) paciente.cpp

cita.o: cita.cpp cita.hpp
																	g++ $(CPPFLAGS) cita.cpp

historial.o: historial.cpp historial.hpp
																	g++ $(CPPFLAGS) historial.cpp

tratamiento.o: tratamiento.cpp tratamiento.hpp
																	g++ $(CPPFLAGS) tratamiento.cpp

clean:
	rm -rf *~ $(OBJETOS)

