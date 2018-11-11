#include "../MarkovChain/MarkovChain.h"
#include <Windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	// Current states
	string currentState = "";
	int current = 0;

	// State counts
	int stateOneCount = 0;
	int stateTwoCount = 0;
	int stateThreeCount = 0;

	// Total loops
	int loops = 0;

	// Sleep time
	int time = 1000;

	while (true)
	{
		Sleep(time);
		loops++;
		current = calculateWeatherState();
		switch (current)
		{
		case 0:
			currentState = "SUNNY";
			stateOneCount++;
			break;
		case 1:
			currentState = "RAINY";
			stateTwoCount++;
			break;
		case 2:
			currentState = "WINDY";
			stateThreeCount++;
			break;
		}
		cout << "Generated Random: " << getRandom() << " CURRENT STATE > " << currentState << endl;
		if(loops % 5 == 0)
			cout << "Sunny: " << stateOneCount << ", Rainy: " << stateTwoCount << ", Windy: " << stateThreeCount << endl;
	}

	cin.get();
	return 0;
}