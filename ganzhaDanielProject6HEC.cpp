#include <iostream>

#define ROWS 5
#define COLS 6
#define ALIVE '*'
#define DEAD ' ' 

void initWorld(char a[][COLS], int& gen);
void createFirstGen(char a[][COLS]);
void printWorld(char a[][COLS], int n);
void simulate(char a[][COLS], int gen);
int countNeighbors(char a[][COLS], int i, int j);
void copyMatrix(char a[][COLS], char b[][COLS]);

using namespace std;

int main () {
	char a[ROWS][COLS] = {""};
	int gen;
	initWorld(a, gen);
	simulate(a, gen);
}

void initWorld(char a[][COLS], int& gen) {
	int seed, i;
	cout<<"Enter random generator seed: ";
	cin>>seed;
	cout<<"Enter generations to display: ";
	cin>>gen;
	srand(seed);
	cout<<"\nInitial world"<<endl;
	cout<<"ROWS = "<<ROWS<<", COLS = "<<COLS;
	if(gen > 0) {
		createFirstGen(a);
	}
}

void createFirstGen(char a[][COLS]) {
	int i, j, r;
	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
			r = rand() % 2;
			if(r == 1)
				a[i][j] = ALIVE;
			else
				a[i][j] = DEAD; 
		}
	}
	printWorld(a, 1);
}

void printWorld(char a[][COLS], int gen) {
	int i, j;
	cout<<"\n\nGeneration "<<gen<<endl;
	cout<<"  ";
	for(i = 1; i <= COLS / 10; i++) {
		cout<<"         "<<i;
	}
	cout<<"\n  ";
	for(i = 0; i < COLS; i++) {
		cout<<(i+1)%10;
	}
	cout<<"\n  ";
	for(i = 0; i < COLS; i++) {
		cout<<"-";
	}
	for(i = 0; i < ROWS; i++) {
		cout<<"\n";	
		cout<<i+1<<"|";
		for(j = 0; j < COLS; j++) {
			cout<<a[i][j];
		}
	}
		cout<<"\n\n";
		system("pause");
}

void simulate(char a[][COLS], int gen) {
	char b[ROWS][COLS];
	int i, j, k, count;
	for(i = 2; i <= gen; i++) {
		copyMatrix(a, b);
		
		for(j = 0; j < ROWS; j++) {
			for(k = 0; k < COLS; k++) {
				count = countNeighbors(a, j, k);
				if(count < 2 || count > 3) {
					b[j][k] = DEAD;
				}
				else if(count == 3 && a[j][k] == DEAD) {
					b[j][k] = ALIVE;
				}
			}
		}
		copyMatrix(b,a);
		printWorld(a, i);
	}
}
	
int countNeighbors(char a[][COLS], int i, int j) {
	int count = 0, v, u;
	for(v = -1; v <= 1; v++) {
		for(u = -1; u <= 1; u++) {
			
			if(v + i >= 0 && v + i < ROWS && u + j >= 0 && u + j < COLS) {
				if(a[i+v][j+u] == ALIVE) {
					
					count++;
				}
			}
		}
	}
	if(a[i][j] == ALIVE) {
		return --count;
	}
	return count;
}

void copyMatrix(char a[][COLS], char b[][COLS]) {
	int i, j;
	for(i = 0; i < ROWS; i++) {
		for(j = 0; j < COLS; j++) {
			b[i][j] = a[i][j];
		}
	}
}
