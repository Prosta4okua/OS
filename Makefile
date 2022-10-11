# all: compile_task0 run_task0 clean_task0

all: compile_task4 run_task4 clean_task4

compile_task4: task4.c
	@echo "\n~~~~~\nCompiling task4...\n"
	@cc task4.c -o task4 -lm

run_task4: task4
	@echo "\n~~~~~\nRunning task4...\n~~~~~\n"
	@./task4

clean_task4: task4
	@echo "\n~~~~~\nClearing redundant files...\n"
	@rm task4
	@echo "End of task4\n~~~~~\n"

compile_task0: task0.c
	@echo "\n~~~~~\nCompiling task0...\n"
	@gcc task0.c -o task0.out -lm

run_task0: task0.out
	@echo "\n~~~~~\nRunning task0...\n~~~~~\n"
	@./task0.out

clean_task0: task0.out
	@echo "\n~~~~~\nClearing redundant files...\n"
	@rm task0.out
	@echo "End of task0\n~~~~~\n"
