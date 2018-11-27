#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

void input(int** A,int n, int m);
void output(int** A, int n, int m);
int max_distance(int** A, int n, int m, int &point_1, int &point_2, double &max_dist);

int main() {
	int n;
	int m = 2;
	cout << "Please, input the number of points: ";
	cin >> n;
	int **A = new int* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new int [m];
	}
	input(A, n, m);
	cout << "|  x  |  y  | #Number" << endl;
	cout << " --------------------" << endl;
	output(A, n, m);
	int point_1, point_2;
	double max_dist;
	max_distance(A, n, m, point_1, point_2, max_dist);
	cout << "============================================" << endl;
	cout << "Maximal distance between points: " << max_dist << endl;
	cout << "Number of the first point: " << point_1 << endl;
	cout << "Number of the second point: " << point_2;
	
	_getch();
}

void input(int** A, int n, int m) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
  		A[i][j]=rand() % 16 - 5;
  		}
	}
}

void output(int** A, int n, int m) {
	for (int i = 0; i < n; i++) {
		cout << "| ";
		for (int j = 0; j < m; j++) {
			cout << setw(2) << A[i][j] << "  | ";
		}
		cout << i + 1 << endl;
	}
}

int max_distance(int** A, int n, int m, int &point_1, int &point_2, double &max_dist ) {
	max_dist = 0;
	double dist;
	int j = 0;
	for (int i = 0; i < n - 1; i++) {
		dist = sqrt(pow((A[i+1][j] - A[i][j]),2)+pow((A[i+1][j+1] - A[i][j+1]),2));
		if (dist > max_dist) {
			max_dist = dist;
			point_1 = i + 1;
			point_2 = i + 2;
		}
	}
	
	return max_dist, point_1, point_2;		
}
