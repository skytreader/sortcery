# vim: set noexpandtab:

TEST =
TEST_FLAGS = 

ifeq ($(TEST), y)
    TEST_FLAGS = -fprofile-arcs -ftest-coverage
endif

################################################################################
# Unit test executables.
################################################################################

all-tests: utils-test.o utils.o insertion-test.o insertion.o
	gcc $(TEST_FLAGS) -o build/all-tests build/utils.o build/utils-test.o build/insertion.o build/insertion-test.o -lcriterion

utils-test: utils-test.o utils.o
	gcc $(TEST_FLAGS) -o build/utils-test build/utils.o build/utils-test.o -lcriterion

insertion-test: insertion-test.o insertion.o utils.o
	gcc $(TEST_FLAGS) -o build/insertion-test build/insertion-test.o build/insertion.o build/utils.o -lcriterion

bubble-tests: bubble-tests.o bubble.o utils.o
	gcc $(TEST_FLAGS) -o build/bubble-tests build/bubble-tests.o build/bubble.o build/utils.o -lcriterion

################################################################################
# These are the object files for the actual algorithms and functions in this
# repository.
################################################################################
utils.o: src/utils.c src/utils.h
	gcc $(TEST_FLAGS) -c src/utils.c -o build/utils.o

insertion.o: src/insertion.c src/insertion.h src/utils.h
	gcc $(TEST_FLAGS) -c src/insertion.c -o build/insertion.o

bubble.o: src/bubble.c src/bubble.h src/utils.h
	gcc $(TEST_FLAGS) -c src/bubble.c -o build/bubble.o

################################################################################
# Individual object files for per-module unittests.
################################################################################

utils-test.o: src/tests/utils-test.c
	gcc $(TEST_FLAGS) -c src/tests/utils-test.c -o build/utils-test.o

insertion-test.o: src/tests/insertion-test.c
	gcc $(TEST_FLAGS) -c src/tests/insertion-test.c -o build/insertion-test.o

bubble-tests.o: src/tests/bubble-tests.c
	gcc $(TEST_FLAGS) -c src/tests/bubble-tests.c -o build/bubble-tests.o
