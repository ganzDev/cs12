#include <iostream>

using namespace std;

void createPlane(char plane[][41], int n);
void insertPoints(char plane[][41], int n);
void printPlane(char plane[][41], int n);

int main() {
	char plane[41][41] = {""};
	int i, j;
	createPlane(plane, 41);
	insertPoints(plane, 41);
}


void insertPoints(char plane[][41], int n) {
	int x, y;
	cout<<"Please enter x value between -20 and 20: ";
	cin>>x;
	while(x >= -20 && x <= 20) {
		cout<<"Please enter y value between -20 and 20: ";
		cin>>y;
		
		while(y < -20 || y > 20) {
			cout<<"Incorrect y value.\nPlease enter y value between -20 and 20: ";
			cin>>y;
		}
		
		
		plane[20-y][20+x] = '*';
		
		cout<<"Please enter x value between -20 and 20: ";
		cin>>x;
	}

	printPlane(plane, n);
}

void createPlane(char plane[][41], int n) {
	int i, j;
	for(i = 0; i < n/2; i++) {
		
		for(j = 0; j < n; j++) {
			if(j == n/2) {
				plane[i][j] = '|';
			}
			
			else {
			plane[i][j] = ' ';
			}	
		}
	}
	for(i = 0; i < n; i++) {
		
		plane[n/2][i] = '-';
		
		if(i == n/2) {
			plane[n/2][i] = '+';
		}
	}
	for(i = n / 2 + 1; i < n; i++) {
		
		for(j = 0; j < n; j++) {
			if(j == n/2) {
				plane[i][j] = '|';
			}
			else {
			plane[i][j] = ' ';
			}
			
		}
	}
}


void printPlane(char plane [][41], int n) {
	int i, j;
	for(i = 0; i < n; i++) {
		
		for(j = 0; j < n; j++) {
			
			cout<<plane[i][j]<<" ";
		}
		cout<<endl;
	}
}
	