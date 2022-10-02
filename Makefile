all: compilation run clean

compilation:  task4.c# task0.c
	@echo "\n~~~~~\nStage 1. Compiling main.c to main...\n"
#	@cc task0.c -o task0 -lm
	@cc task4.c -o task4 -lm
	@echo "End of stage 1\n~~~~~\n"

run: task4 #task0
	@echo "\n~~~~~\nStage 2. Running the program...\n"
	@echo "Running task0...\n"
#	@./task0
	@echo "\n~~~~~\nEnd task0. Running task4...\n~~~~~\n"
	@./task4
	@echo "End task4."
	@echo "\nThe program has been executed. End of stage 2\n~~~~~\n"

clean:
	@echo "\n~~~~~\nStage 3. Clearing redundant files...\n"
	@rm task4 #task0
	@echo "End of stage 3\n~~~~~\n"
