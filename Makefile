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

all-tests: utils-tests.o utils.o insertion-tests.o insertion.o bubble-tests.o bubble.o merge-tests.o merge.o heapsort-tests.o heapsort.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/all-tests build/utils.o build/utils-tests.o build/insertion.o build/insertion-tests.o build/bubble-tests.o build/bubble.o build/merge-tests.o build/merge.o build/heapsort-tests.o build/heapsort.o $(END_FLAGS)
#
#%-tests: %-tests.o %.o
#	cd build
#	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o $@ $^ $(END_FLAGS)
#
utils-tests: utils-tests.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/utils-tests build/utils.o build/utils-tests.o $(END_FLAGS)

insertion-tests: insertion-tests.o insertion.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/insertion-tests build/insertion-tests.o build/insertion.o build/utils.o $(END_FLAGS)

bubble-tests: bubble-tests.o bubble.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/bubble-tests build/bubble-tests.o build/bubble.o build/utils.o $(END_FLAGS)

merge-tests: merge-tests.o merge.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/merge-tests build/merge-tests.o build/merge.o build/utils.o $(END_FLAGS)

heapsort-tests: heapsort-tests.o heapsort.o utils.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/heapsort-tests build/heapsort-tests.o build/heapsort.o build/utils.o $(END_FLAGS)

bstree-tests: bstree-tests.o bstree.o
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -o build/bstree-tests build/bstree-tests.o build/bstree.o $(END_FLAGS)

################################################################################
# These are the object files for the actual algorithms and functions in this
# repository.
################################################################################

%.o: src/%.c src/%.h
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/$*.c -o build/$@

################################################################################
# Individual object files for per-module unittests.
################################################################################

utils-tests.o: src/tests/utils-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/tests/utils-tests.c -o build/utils-tests.o

insertion-tests.o: src/tests/insertion-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/tests/insertion-tests.c -o build/insertion-tests.o

bubble-tests.o: src/tests/bubble-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/tests/bubble-tests.c -o build/bubble-tests.o

merge-tests.o: src/tests/merge-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/tests/merge-tests.c -o build/merge-tests.o

heapsort-tests.o: src/tests/heapsort-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/tests/heapsort-tests.c -o build/heapsort-tests.o

bstree-tests.o: src/tests/bstree-tests.c
	gcc $(TEST_FLAGS)$(DEBUG_FLAGS)$(DEFAULT_FLAGS) -c src/tests/bstree-tests.c -o build/bstree-tests.o
