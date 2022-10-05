#include<float.h>	// for easier comparison
#include<math.h> 	// for distance measuring
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 	// for random


#define MEMORY_ALLOCATION_ERROR "\n\nError occurred during memory allocation...\n\n"

struct Point {
	double x;
	double y;
	double z;
	double mass;
};

typedef struct Point Point;

Point* points;

/* main functions */
void gen_array(int );
int find_min(int n);
int find_nearest(int ,int );
double dist_3d(double x1, double y1, double z1, double x2, double y2, double z2);
void add_mass(old_index, new_index);
void del_point(int , int );

// for easier testing the program
void debug();
double rand_double(double , double );
void point_info(int );

// for easier input
int enter_int(char* );
double enter_double(char* );

int main() {
	int round_index = 0;
	int min_p_index;
	int nearest_point_index;

	// prep for generating really random numbers
	srand((unsigned int) time(NULL));

	// make while cycle where suggest a person to add some points
	printf("Welcome to Danylo Sydorenko's implementation of PointTask\n~~~\n");


	// enter amount of points
	int count = enter_int("How many points do you want to generate?\n> ");
	if (count <= 1) {
		printf("Too small an amount was enterred.\n");
		return 1;
	}

	gen_array(count);

	while (count > 1) {
		round_index++;
		printf("\n~~~~~~~~~~~~~\nRound %d. Fight!", round_index);
		printf("Start find min");
		// find minimal mass point (return index)
		min_p_index = find_min(count);
		printf("\nMinimal point: ");
		point_info(min_p_index);


		// find the nearest point to the previous point (return index)
		printf("\nEnd find min. Start near point\n");
		int nearest_p_index = find_nearest(count, min_p_index);
		printf("\nThe nearest point: ");
		point_info(nearest_p_index);
		printf("\nNearest point success\n");



		// add mass to the nearest 
		add_mass(min_p_index, nearest_p_index);
		printf("\nAdd mass success!\n");

		// delete minimal mass point with index and reallocate array
		printf("\nDeleting point: ");
		point_info(min_p_index);
		del_point(min_p_index, count);
		printf("\nDelete point success!\n");

		// decrease count
		count--;
	}
}

void debug(int n) {
	// write code for adding some points
	//srand(time(NULL));
//	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for (int i = 0; i < n; i++) {
		printf("- [%d] %lf|%lf|%lf|%lf\n", i, (points+i)->x, (points+i)->y, (points+i)->z, (points+i)->mass);
	}

//	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}

int enter_int(char* msg) {
	int temp;

	printf(msg);
	scanf("%d", &temp);

	return temp;
}

double enter_double(char* msg) {
	double temp;

	printf(msg);
	scanf("%lf", &temp);

	return temp;
}

// generating random double number in specific range
double rand_double(double min, double max) {
	double scale = rand() / (double)  RAND_MAX;
	return min + scale * (max - min);
}

void gen_array(int n) {
	// creating array
	points = (Point* ) malloc(n * sizeof(Point));
	if (points == NULL) {
		printf(MEMORY_ALLOCATION_ERROR);
		exit(1);
	}

	printf("\n\nYour points:\n");
	for (int i = 0; i < n; i++) {
		(points+i)->x = rand_double(0, 100);
		(points+i)->y = rand_double(0, 100);
		(points+i)->z = rand_double(0, 100);
		(points+i)->mass = rand_double(0, 100);
		printf("- [%d] %lf|%lf|%lf|%lf\n", i, (points+i)->x, (points+i)->y, (points+i)->z, (points+i)->mass);
	}
}


double dist_3d(double x1, double y1, double z1, double x2, double y2, double z2) {
	return  sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0) + pow(z1-z2, 2.0));
}


int find_min(int n) {
	double min = 999;;
	int index;
	
	printf("Comparison with min num:\n");
	for (int i = 0; i < n; i++) {
		double num = (points + i)->mass;
		printf("%lf|%lf\n", num, min);
		if (min > num) {
			min = num;
			index = i;
		}
	}

//	printf("Minimal point has index %d. [x|y|z]: [%lf|%lf|%lf]. Mass: %lf\n", index, points[index].x, points[index].y, points[index].z, points[index].mass );

	return index;
}


int find_nearest(int count, int index) {

	double min_dist = (points)->mass;
	int nearest_index;
	for (int i = 0; i < count; i++) {
		// skip the same index
		if (index == i)
			continue;
		
		printf("hehe?");
		double distance = dist_3d( (points+i)->x, (points+i)->y, (points+i)->z, (points+index)->x, (points+index)->y, (points+index)->z);
		printf("!hehe!");
		printf("\n%d|%d|%lf~", i, index, distance);

		if (min_dist > distance) {
			min_dist = distance;
			nearest_index = i;
		}
		
	}

	return nearest_index;
}


void add_mass(old_index, new_index) {
	(points + new_index)->mass += (points + old_index)->mass;
}


void del_point(int index, int size) {
	for (int i = index; i < size; i++) {
		points[i] = points[i+1];
	}

	points = (Point* ) realloc(points, (size - 1) * sizeof(Point));
	if (points == NULL) {
		printf(MEMORY_ALLOCATION_ERROR);
		exit(1);
	}
}


void point_info(int i) {

	printf("- [%d] %lf|%lf|%lf|%lf\n", i, (points+i)->x, (points+i)->y, (points+i)->z, (points+i)->mass);
}
