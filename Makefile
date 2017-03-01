test: src/tests/utils-test.c src/utils.c
	gcc -o build/test src/tests/utils-test.c src/utils.c -lcriterion
