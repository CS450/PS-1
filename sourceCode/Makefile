all:p1.x p2.x p3.x p4.x p3assembly.s

p1.x: p1.c
	gcc p1.c -o p1.x
p2.x: p2.c
	gcc p2.c -o p2.x
p3.x: p3.cpp
	g++ -std=c++11 p3.cpp -o p3.x
p3assembly.s: p3.cpp
	g++ -std=c++11 -S -o p3.s p3.cpp
p4.x: p4.cpp
	g++ -std=c++11 p4.cpp -o p4.x

clean: 
	rm -f *.o *~ *.x p3assembly.s p3.s 

