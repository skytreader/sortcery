test: src/tests/utils-test.c src/utils.c
	gcc -o build/test src/tests/utils-test.c src/utils.c -lcriterion

insertion_test: src/utils.c src/insertion.c src/tests/insertion-test.c
	gcc -o build/insertion-test src/utils.c src/insertion.c src/tests/insertion-test.c -lcriterion
