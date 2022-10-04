COMPILER = gcc
C_FLAGS = -Wall -Wextra -std=c99


SDATA:String.o ReadStudentData.o
	$(COMPILER) $(C_FLAGS) -o SDATA String.o ReadStudentData.o -lm
LOADT: String.o Point2D.o Evaluate.o loadRoutesTest.o
	$(COMPILER) $(C_FLAGS) -o LOADT String.o Point2D.o Evaluate.o loadRoutesTest.o -lm
DRIVER: String.o Point2D.o Evaluate.o DriverClass.o
	$(COMPILER) $(C_FLAGS) -o DRIVER String.o Point2D.o Evaluate.o DriverClass.o -lm

String.o : String.c
	$(COMPILER) $(C_FLAGS) -c -g String.c
Evaluate.o : Evaluate.c
	$(COMPILER) $(C_FLAGS) -c -g Evaluate.c
Point2D.o: Point2D.c
	$(COMPILER) $(C_FLAGS) -c -g Point2D.c
DriverClass.o: DriverClass.c
	$(COMPILER) $(C_FLAGS) -c -g DriverClass.c
loadRoutesTest.o: loadRoutesTest.c
	$(COMPILER) $(C_FLAGS) -c -g loadRoutesTest.c
ReadStudentData.o: ReadStudentData.c
	$(COMPILER) $(C_FLAGS) -c -g ReadStudentData.c

clear:
	rm -f *.o
