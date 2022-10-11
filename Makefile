all: compilation run clean

compilation: main.c
	@echo "\n~~~~~\nStage 1. Compiling main.c to main...\n"
	@cc main.c -o main -lm
	@echo "End of stage 1\n~~~~~\n"

run: main
	@echo "\n~~~~~\nStage 2. Running the program...\n"
	@./main $a $b $c
	@echo "\nThe program has been executed. End of stage 2\n~~~~~\n"

clean:
	@echo "\n~~~~~\nStage 3. Clearing redundant files...\n"
	@rm ./main
	@echo "End of stage 3\n~~~~~\n"
