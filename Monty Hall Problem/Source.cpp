
/*
This program serves to proof that the monty hall problem is true.
To proof this I simulate thousands of games and calculate the percentage of wins.
When switching doors there should be a 66% chance of winning.
*/

#include<iostream>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));

	const int GAMES = 10000; //Amount of games
	const int DOORS = 3; //Amount of doors
	int wins = 0; // total amount of wins

	for (int i = 0; i < GAMES; i++)
	{
		int prize = rand() % DOORS + 1; // Door with prize
		int choice = rand() % DOORS + 1; // Player Choice
		int door_revealed;

		//reveals door thats not prize or choice
		for (int i = 1; i <= DOORS; i++)
			if (i != prize && i != choice)
			{
				door_revealed = i;
				break;
			}

		//switches choice
		for (int i = 1; i <= DOORS; i++) // commenting this out will yeild a 33% chance instead. 
			if (i != choice && i != door_revealed)
			{
				choice = i;
				break;
			}

		if (prize == choice)
			wins++;
	}

	cout << "Win Percentage: " << wins * 100 / GAMES << "%" << endl;
	system("pause");
	return 0;
}
