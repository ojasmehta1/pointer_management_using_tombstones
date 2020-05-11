all: A4Test test1 test2 test3 test4 test5 test6 test7 test8 test9 test10

clean:
	rm *.o

A4Test: A4Test.cpp tombstones.h
	g++ -o A4Test.o A4Test.cpp
test1: test1.cpp tombstones.h
	g++ -o test1.o test1.cpp
test2: test2.cpp tombstones.h
	g++ -o test2.o test2.cpp
test3: test3.cpp tombstones.h
	g++ -o test3.o test3.cpp
test4: test4.cpp tombstones.h
	g++ -o test4.o test4.cpp
test5: test5.cpp tombstones.h
	g++ -o test5.o test5.cpp
test6: test6.cpp tombstones.h
	g++ -o test6.o test6.cpp
test7: test7.cpp tombstones.h
	g++ -o test7.o test7.cpp
test8: test8.cpp tombstones.h
	g++ -o test8.o test8.cpp
test9: test9.cpp tombstones.h
	g++ -o test9.o test9.cpp
test10: test10.cpp tombstones.h
	g++ -o test10.o test10.cpp 

