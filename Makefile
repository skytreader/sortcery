all_tests: src/tests/utils-test.c src/utils.c src/insertion.c src/tests/insertion-test.c
	gcc -c

utils.o: src/utils.c src/utils.h
	gcc -c src/utils.c -o build/utils.o

insertion.o: src/insertion.c src/insertion.h src/utils.h
	gcc -c insertion.c -o build/insertion.o

utils-test.o: src/tests/utils-test.c
	gcc -c src/tests/utils-test.c -o build/utils-test.o

utils-test: utils-test.o
	gcc -fprofile-arcs -ftest-coverage -o build/utils-test build/utils.o build/utils-test.o -lcriterion

insertion_test: src/utils.c src/insertion.c src/tests/insertion-test.c
	gcc -o build/insertion-test src/utils.c src/insertion.c src/tests/insertion-test.c -lcriterion
