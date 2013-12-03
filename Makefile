CXX = g++
CXXFLAGS = -g -Wall -MMD
OBJECTS = effect.o stats.o temporary.o permanent.o effecttest.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY : clean
clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
