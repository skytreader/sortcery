all_tests: src/tests/utils-test.c src/utils.c src/insertion.c src/tests/insertion-test.c
	gcc -fprofile-arcs -ftest-coverage -o build/test build/utils-test.o build/insertion-test.o -lcriterion

utils.o: src/utils.c src/utils.h
	gcc -c src/utils.c -o build/utils.o

insertion.o: src/insertion.c src/insertion.h src/utils.h
	gcc -c src/insertion.c -o build/insertion.o

utils-test.o: src/tests/utils-test.c
	gcc -c src/tests/utils-test.c -o build/utils-test.o

insertion-test.o: src/tests/insertion-test.c
	gcc -c src/tests/insertion-test.c -o build/insertion-test.o

utils-test: utils-test.o utils.o
	gcc -fprofile-arcs -ftest-coverage -o build/utils-test build/utils.o build/utils-test.o -lcriterion

insertion-test: insertion-test.o insertion.o utils.o
	gcc -fprofile-arcs -ftest-coverage -o build/insertion-test build/insertion-test.o build/insertion.o build/utils.o -lcriterion
