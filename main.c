#include<locale.h>	// for Ukrainian language
//#include<math.h>	// for rand() function // doesn't work
#include<stdio.h>	// for output to the terminal
#include<stdlib.h>	// to prevert warnings

const int INITIAL_MONEY = 5000;

void print_menu();
int get_random_menu();
void check_input();

int main() {
	int current_money = INITIAL_MONEY;
	int menubar;
	
	printf("---\nWelcome to our Slot Mashine - the most honest mashine in the whole world\n---\n\n");
		
	while (current_money > 0) {
//		check_input();
		print_menu();	
//		fflush(stdin);	
		scanf("%d", &menubar);
//		printf("----%d----", menubar);	
		switch(menubar) {
			case 1:

				break;
			default:
				printf("Your final balance: %d\n", current_money);
				return 0;

		}

	}

	printf("You losed. We hope you will be lucky next time ʕ•ᴥ•ʔ");
	return 0;
}

void print_menu() {
	printf("Available commands:\n \
			1. Play\n \
			0. Exit\n \
		       	\nEnter the number(0-1):\t");
}

int get_random_number() {
	return rand() % 8;
}

void check_input(){
	while (getchar() != '\n')
		continue;
}
