# vim: set noexpandtab:

TEST =
TEST_FLAGS = 

DEBUG = 
DEBUG_FLAGS = 

ifeq ($(TEST), y)
    TEST_FLAGS = -fprofile-arcs -ftest-coverage
endif

ifeq ($(DEBUG), y)
    DEBUG_FLAGS = -g 
endif

################################################################################
# Unit test executables.
################################################################################

all-tests: utils-tests.o utils.o insertion-tests.o insertion.o bubble-tests.o bubble.o
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-o build/all-tests build/utils.o build/utils-tests.o build/insertion.o build/insertion-tests.o build/bubble-tests.o build/bubble.o -lcriterion

utils-tests: utils-tests.o utils.o
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-o build/utils-tests build/utils.o build/utils-tests.o -lcriterion

insertion-tests: insertion-tests.o insertion.o utils.o
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-o build/insertion-tests build/insertion-tests.o build/insertion.o build/utils.o -lcriterion

bubble-tests: bubble-tests.o bubble.o utils.o
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-o build/bubble-tests build/bubble-tests.o build/bubble.o build/utils.o -lcriterion

################################################################################
# These are the object files for the actual algorithms and functions in this
# repository.
################################################################################
utils.o: src/utils.c src/utils.h
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-c src/utils.c -o build/utils.o

insertion.o: src/insertion.c src/insertion.h src/utils.h
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-c src/insertion.c -o build/insertion.o

bubble.o: src/bubble.c src/bubble.h src/utils.h
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-c src/bubble.c -o build/bubble.o

################################################################################
# Individual object files for per-module unittests.
################################################################################

utils-tests.o: src/tests/utils-tests.c
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-c src/tests/utils-tests.c -o build/utils-tests.o

insertion-tests.o: src/tests/insertion-tests.c
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-c src/tests/insertion-tests.c -o build/insertion-tests.o

bubble-tests.o: src/tests/bubble-tests.c
	gcc $(TEST_FLAGS) $(DEBUG_FLAGS)-c src/tests/bubble-tests.c -o build/bubble-tests.o
