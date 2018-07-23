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

DEFAULT_FLAGS = -fstack-protector-strong -Wall -Wextra
END_FLAGS = -lcriterion -lm

################################################################################
# Unit test executables.
################################################################################

all-tests: utils-tests.o utils.o insertion-tests.o insertion.o bubble-tests.o bubble.o merge-tests.o merge.o heapsort-tests.o heapsort.o
	cd build && \
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o $@ $^ $(END_FLAGS)

utils-tests: utils-tests.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/utils-tests build/utils.o build/utils-tests.o $(END_FLAGS)

%-tests: %-tests.o %.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/$@ build/$*-tests.o build/$*.o build/utils.o $(END_FLAGS)

################################################################################
# These are the object files for the actual algorithms and functions in this
# repository.
################################################################################

%.o: src/%.c src/%.h
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/$*.c -o build/$@

################################################################################
# Individual object files for per-module unittests.
################################################################################

%-tests.o: src/tests/%-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c $^ -o build/$@
