//#include<locale.h>	// for Ukrainian language // doesn't work
#include<math.h>	// for rand() function
#include<stdio.h>	// for output to the terminal
#include<stdlib.h>	// to prevert warnings


/* How much is added or removed money  */ 
const int INITIAL_MONEY 	= 5000;
const int VERY_SIMPLE_WIN	= 100;
const int SIMPLE_WIN 		= 200;
const int HARD_WIN 		= 600;
const int IMPOSSIBLE_WIN	= INITIAL_MONEY;
const int COST_PER_GAME		= 500;
const int LOSE			= COST_PER_GAME * 3;

/* Combinations */
const int hard[] 	= {0, 111, 222, 333, 444, 555};
const int simple_win[] 	= {55, 77};
const int very_simple_win[] 	= {5, 7};
	
const int wins[]		= {777};
const int lose[]	= {666};

void start_info();
void print_menu();
int get_random_number();
void check_input();
int check_comb(int );
int get_size(int*[] );
void win();
void looser();


int main() {
	int ballance = INITIAL_MONEY;
	int menubar;
	
	start_info();

	while (ballance > 0) {
		print_menu();	
		scanf("%d", &menubar);
		switch(menubar) {
			case 1:
				printf("\n---\n%d₴ has been lifted from your account\n---\n", COST_PER_GAME);
				ballance -= COST_PER_GAME;;
				int nums[3];
				
				nums[0] = get_random_number();
				nums[1] = get_random_number();
				nums[2] = get_random_number();

				int comb = nums[0] * 100 + nums[1] * 10 + nums[2];
				check_comb(comb);
				int game = check_comb(comb);
				
				ballance += game;

				printf("Your combination: %d\n", comb);
				printf("Your balance: %d (+%d)", ballance, game);

				if (game == IMPOSSIBLE_WIN)
					win();
				if (ballance <= COST_PER_GAME)
					looser();		

				break;
			case 2:
				printf("Your current balance: %d", ballance);
				break;
			default:
				printf("\n\nWrite again!\n\n");

		}

	}

}

void start_info() {
	printf("---\nWelcome to our Slot Mashine\nthe most honest mashine in the whole world\n---\n");
	printf("Made by Sydorenko Danylo, CS-34\n---\n");

	printf("\n--------------------------\nAvailable combinations:\n--------------------------\n");
	printf("Initial sum:\t%d\n", INITIAL_MONEY);

	hr();

	printf("Simple win:\t%d. Combo: ", VERY_SIMPLE_WIN);
		print_arr(very_simple_win, sizeof(very_simple_win) / 4);;
		new_line();
	printf("Medium win:\t%d. Combo: ", SIMPLE_WIN);
		print_arr(simple_win, sizeof(simple_win) / 4);;
		new_line();
	printf("Hard win:\t%d. Combo: ", HARD_WIN);
		print_arr(hard, sizeof(hard) / 4);
		new_line();
	printf("Impossible win:\t%d. Combo: ", IMPOSSIBLE_WIN);
		print_arr(wins, sizeof(IMPOSSIBLE_WIN) / 4);
		new_line();
	
	hr();

	printf("Cost per game:\t%d\n", COST_PER_GAME);
	printf("The worst lose:\t%d", LOSE);
	
	hr();
		
}
void print_menu() {
	printf("\n-------------------\n\n\nAvailable commands:\n \
			1. Play\n \
			2. Check your balance\n \
			0. Exit\n \
		       	\nEnter the number:\t");
}

int get_random_number() {
	return rand() % 8;
}

void check_input(){
	while (getchar() != '\n')
		continue;
}

int check_comb (int num) {

	int i = 0;

	

	for (i = 0; i < sizeof(hard) / 4; i++) {
		if (hard[i] == num) {
			return HARD_WIN;
		}
	}
	
	for (i = 0; i < sizeof(simple_win) / 4; i++) {
		if (simple_win[i] == num / 10) {
			return SIMPLE_WIN;
		}
	}
	

	for (i = 0; i < sizeof(very_simple_win) / 4; i++) {
		if (very_simple_win[i] == num / 100) {
			return VERY_SIMPLE_WIN;
		}
	}

	for (i = 0; i < sizeof(lose) / 4; i++) {
		if (lose[i] == num) {
			return LOSE;
		}
	}

	
	for (i = 0; i < sizeof(wins) / 4; i++) {
		if (wins[i] == num) {
			return IMPOSSIBLE_WIN;
		}
	}
	
	return 0;
	
}	

int get_size(int *array[]) {
	return sizeof(array) / sizeof(int);
}

void win() {
	printf("\n\n\n\n");
	printf("---------------------------------");
	printf("You've have won! Congratulations!");
	printf("---------------------------------");
	printf("\n\n\n\n");
	

	printf("Exiting...");
	sleep(3);
	exit(0);
}


void looser() {
	printf("\n\n\n\n");
	printf("----------------------------");
	printf("You are such a looser! How?!");
	printf("----------------------------");
	printf("\n\n\n\n");
	

	printf("Exiting...");
	sleep(3);
	exit(0);
}

void print_arr(int* A, int size) {
	printf("[");
	for(int k = 0; k < size; k++ ) {
		if (A[k] == 0)
			printf("000");
		else if (A[k] < 10)
			printf("%d**", A[k]); 
		else if (A[k] < 100)
			printf("%d*", A[k]); 
		else 
			printf("%d", A[k]);

		if (k + 1 != size)
			printf(", ");
	}
	printf("]");
}

void hr(){
	printf("\n~~~~~~~~~~~~~~~~~~~~~~\n");
}

void new_line(){
	printf("\n");
}
