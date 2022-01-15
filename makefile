a4: helper.o miscFunctions.o queueFunctions.o testA4.o
	gcc -Wall -std=c99 helper.o miscFunctions.o queueFunctions.o testA4.o -o a4

helper.o: helper.c headerA4.h
	gcc -Wall -std=c99 -c helper.c

miscFunctions.o: miscFunctions.c headerA4.h
	gcc -Wall -std=c99 -c miscFunctions.c

queueFunctions.o: queueFunctions.c headerA4.h
	gcc -Wall -std=c99 -c queueFunctions.c

testA4.o: testA4.c headerA4.h
	gcc -Wall -std=c99 -c testA4.c

clean:
	rm *.o a4
