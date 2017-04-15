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

DEFAULT_FLAGS = -fstack-protector-strong
END_FLAGS = -lcriterion -lm

################################################################################
# Unit test executables.
################################################################################

all-tests: utils-tests.o utils.o insertion-tests.o insertion.o bubble-tests.o bubble.o merge-tests.o merge.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -o build/all-tests build/utils.o build/utils-tests.o build/insertion.o build/insertion-tests.o build/bubble-tests.o build/bubble.o build/merge-tests.o build/merge.o -lcriterion -lm

utils-tests: utils-tests.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -o build/utils-tests build/utils.o build/utils-tests.o -lcriterion -lm

insertion-tests: insertion-tests.o insertion.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -o build/insertion-tests build/insertion-tests.o build/insertion.o build/utils.o -lcriterion -lm

bubble-tests: bubble-tests.o bubble.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -o build/bubble-tests build/bubble-tests.o build/bubble.o build/utils.o -lcriterion -lm

merge-tests: merge-tests.o merge.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/merge-tests build/merge-tests.o build/merge.o build/utils.o -lcriterion -lm

heapsort-tests: heapsort-tests.o heapsort.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/heapsort-tests build/heapsort-tests.o build/heapsort.o build/utils.o $(END_FLAGS)

################################################################################
# These are the object files for the actual algorithms and functions in this
# repository.
################################################################################
utils.o: src/utils.c src/utils.h
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -c src/utils.c -o build/utils.o

insertion.o: src/insertion.c src/insertion.h src/utils.h
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -c src/insertion.c -o build/insertion.o

bubble.o: src/bubble.c src/bubble.h src/utils.h
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -c src/bubble.c -o build/bubble.o

merge.o: src/merge.c src/merge.h src/utils.h
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/merge.c -o build/merge.o

heapsort.o: src/heapsort.c src/heapsort.h src/utils.h
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/heapsort.c -o build/heapsort.o

################################################################################
# Individual object files for per-module unittests.
################################################################################

utils-tests.o: src/tests/utils-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -c src/tests/utils-tests.c -o build/utils-tests.o

insertion-tests.o: src/tests/insertion-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -c src/tests/insertion-tests.c -o build/insertion-tests.o

bubble-tests.o: src/tests/bubble-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)-fstack-protector-strong -c src/tests/bubble-tests.c -o build/bubble-tests.o

merge-tests.o: src/tests/merge-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/tests/merge-tests.c -o build/merge-tests.o

heapsort-tests.o: src/tests/heapsort-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/tests/heapsort-tests.c -o build/heapsort-tests.o
