#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// global variables in and out.

ofstream out;
ifstream in;

// function prototypes.

int tossPotato(string a[], int count);
void passPotato(string a[], int&, int&);
int inputFile(string a[]);
void openFile(string);
void setSeed();
void removeEliminated(string a[], int, int&, int&);
void play(string a[], int&);
void printArray(string a[], int);

// driver function.

int main() 
{
	string name, a[15] = {""};
	int count;
	openFile(name);
	setSeed();
	count = inputFile(a);
	play(a, count);
	in.close();
	out.close();
}

// function takes a string and opens the corresponding file as the input file.
// if file name is incorrect, asks for an input until the correct name is inserted.

void openFile(string name) 
{
	cout<<"Enter the name of the input file: ";
	int count = 0;
	cin>>name;
	in.open(name);
	while(!in.is_open()) {
		cout<<"Please enter a correct name of the file: ";
		cin>>name;
		in.open(name);
	}
	out.open("output.txt");
}

// function reads the first line of the file and sets it as a seed for the random number generator.

void setSeed()
{
	int seed;
	in>>seed;
	srand(seed);
}

// function takes an array of strings.
// inserts the name of the players inside the input file into the array a[].
// returns the number of players.

int inputFile(string a[]) 
{
	string name;
	int count = 0;
	while(getline(in,name)) {
		in>>a[count];
		count++;
	}
	return count;
}

// takes the array of players and its length, chooses the first player according to a randomly generated number and prints his name.
// also prints the header: "passes eliminated".
// returns the index of the chosen player.

int tossPotato(string a[], int count) 
{
	int chosenPlayer = rand() % count;
	out<<"Game starts with "<<a[chosenPlayer]<<" holding the hot potato"<<endl;
	out<<"passes      eliminated"<<endl;
	return chosenPlayer;
}

// the function takes the array of players and references of the length and the chosen (starting) player.
// the function calculates the index of the eliminated player by the formula: eliminated = (startingPlayer + numOfPasses) % length of the array and removes theirs instance in the array.
// formula explanation: 
// If children sit in a closed circle, the next player can be calculated by startingPlayer + numOfPasses. 
// The modulo operation shortens the amount of iterations needed to calculate the next player.
// For example, 21 passes of the hot potato between 4 players can be reduced to one pass to the next player.

void passPotato(string a[], int& count, int& chosenPlayer) 
{
	int passes, i = 0, j;
	passes = rand() % 20 + 1;
	int elim = (chosenPlayer + passes) % count;
	out<<setw(2)<<left<<passes<<"           "<<right<<a[elim]<<endl;
	removeEliminated(a, elim, count, chosenPlayer);
}

// The function takes the array of players, the eliminated players, the reference to an array's length and reference to the starting player.
// moves the eliminated player to the end of the array, passes the potato to the next player in the array and reduces the count of players by 1.

void removeEliminated(string a[], int elim, int& count, int& chosenPlayer)
 {
	int i;
	string temp;
	// if the eliminated player is stored last in the list of players, pass the potato to the first player in the list.
	if(elim == count - 1) {
		chosenPlayer = 0;
	}
	// else move the eliminated player to the end of the array.
	else 
	{
		for(i = elim; i < count-1; i++)
		{
			temp = a[i+1];
			a[i+1] = a[i];
			a[i] = temp;
		}
		chosenPlayer = elim;
	}
	count--;
}

// takes the array of players and the reference to it's length.
// prints the list of players, chooses starting player and passes the potato between the players
// until the length of the array is 1, meaning one player is remaining.
// prints the last player.

void play(string a[], int& count) 
{
	int chosenPlayer;
	printArray(a, count);
	chosenPlayer = tossPotato(a, count);
	while(count > 1)
	{
		passPotato(a, count, chosenPlayer);
	}
	out<<"The winner is "<<a[0];
}

// takes the array of players and its length and prints it.

void printArray(string a[], int n) 
{
	int i;
	out<<"Participating players: \n";
	for(i = 0; i < n; i++) {
		out<<a[i]<<endl;
	}
	out<<"\n\n";
}