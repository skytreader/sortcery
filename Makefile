TEST_FLAGS = -fprofile-arcs -ftest-coverage

all-tests: utils-test.o utils.o insertion-test.o insertion.o
	gcc $(TEST_FLAGS) -o build/all-tests build/utils.o build/utils-test.o build/insertion.o build/insertion-test.o -lcriterion

utils.o: src/utils.c src/utils.h
	gcc $(TEST_FLAGS) -c src/utils.c -o build/utils.o

insertion.o: src/insertion.c src/insertion.h src/utils.h
	gcc $(TEST_FLAGS) -c src/insertion.c -o build/insertion.o

utils-test.o: src/tests/utils-test.c
	gcc $(TEST_FLAGS) -c src/tests/utils-test.c -o build/utils-test.o

insertion-test.o: src/tests/insertion-test.c
	gcc $(TEST_FLAGS) -c src/tests/insertion-test.c -o build/insertion-test.o

utils-test: utils-test.o utils.o
	gcc $(TEST_FLAGS) -o build/utils-test build/utils.o build/utils-test.o -lcriterion

insertion-test: insertion-test.o insertion.o utils.o
	gcc $(TEST_FLAGS) -o build/insertion-test build/insertion-test.o build/insertion.o build/utils.o -lcriterion
