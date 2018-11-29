#include "../MarkovChain/MarkovChain.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <list>

using namespace std;

#define STATES 5

int main()
{
	typedef int ** iMatrix;
	typedef double ** dMatrix;

	// Transition arrays
	int sunnyTrans[STATES] = { 0, 1, 2, 3, 4 };
	int rainingTrans[STATES] = { 1, 0, 2, 3, 4 };
	int windyTrans[STATES] = { 2, 0, 1, 3, 4 };
	int stormingTrans[STATES] = { 3, 0, 1, 2, 4 };
	int snowingTrans[STATES] = { 4, 0, 1, 2, 3 };

	int* transArray[STATES];
	transArray[0] = sunnyTrans;
	transArray[1] = rainingTrans;
	transArray[2] = windyTrans;
	transArray[3] = stormingTrans;
	transArray[4] = snowingTrans;

	// Transitions matrix
	iMatrix trans = new int*[STATES];
	for (size_t i = 0; i < STATES; i++)
	{
		trans[i] = transArray[i];
	}

	// Probability arrays
	double sunnyProbs[STATES] = { 0.5, 0.2, 0.2, 0.1, 0 };
	double rainingProbs[STATES] = { 0.3, 0.2, 0.2, 0.1, 0.2 };
	double windyProbs[STATES] = { 0.3, 0.1, 0.2, 0.1, 0.3 };
	double stormingProbs[STATES] = { 0.4, 0.1, 0.3, 0.2, 0 };
	double snowingProbs[STATES] = { 0.5, 0, 0.2, 0.2, 0.1 };

	double* probsArray[STATES];
	probsArray[0] = sunnyProbs;
	probsArray[1] = rainingProbs;
	probsArray[2] = windyProbs;
	probsArray[3] = stormingProbs;
	probsArray[4] = snowingProbs;

	// Probabilities matrix
	dMatrix probs = new double*[STATES];
	for (size_t i = 0; i < STATES; i++)
	{
		probs[i] = probsArray[i];
	}

	// Current states
	string currentState = "";
	int current = 0;

	// State counts
	int stateOneCount = 0;
	int stateTwoCount = 0;
	int stateThreeCount = 0;
	int stateFourCount = 0;
	int stateFiveCount = 0;

	// Total loops
	int loops = 0;

	// Sleep time
	int time = 1000;

	while (true)
	{
		Sleep(time);
		loops++;
		current = calculateWeatherState(STATES, trans, probs);
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
		case 3:
			currentState = "STORMING";
			stateFourCount++;
			break;
		case 4:
			currentState = "SNOWING";
			stateFiveCount++;
			break;
		}
		cout << "CURRENT STATE > " << currentState << endl; // " Generated Random: " << getRandom() << endl;
		if(loops % 5 == 0)
			cout << "Sunny: " << stateOneCount << ", Rainy: " << stateTwoCount << ", Windy: " << stateThreeCount << ", Storming: " << stateFourCount << ", Snowing: " << stateFiveCount << endl;
	}

	cin.get();
	return 0;
}