#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>
using namespace std;

const int n = 9;
int P[n], i;
void input();
void output();
int modul(int max);
int k = 0;
int max_elem();
int result();

int main() {
	input();
	output();
	int max = max_elem();
	cout << "\nP(max): " << max << endl;
	modul(max);
	cout << "===============" << endl;
	cout << "Results:" << endl;
	result();
	
	_getch();
}

void input() {
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		P[i] = rand() % 16 - 5; 
	}
}

void output() {
	cout << "P:";
	for (i = 0; i < n; i++) {
		cout << P[i] << " ";
	}
}

int max_elem() {
	int max = P[0];
	for (i = 1; i < n; i++) {
		if (P[i] > max) {
			max = P[i];
		}
	}
	return max;
}

int modul(int max) {
	for (i = 1; i < n; i += 2) {
		if (abs(P[i]) % 2 == 1) {
			k++;
			cout << "Element that will be changed: " << P[i] << endl;
			P[i] = abs(max - P[i]);
			cout << "Changed element: " << P[i] << endl;
		}
	}
	return k;
}

int result() {
	if (k == 0)
		cout << "No changes were made" << endl;
	else 
		cout << "Changed array ";
		output();
		cout << "\nNumber of changed elements: " << k;
}
