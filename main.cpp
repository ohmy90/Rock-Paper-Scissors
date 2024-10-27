#include <cstdlib>
#include <iostream>

std::string player(std::string &result) { 
	bool loop = 1;
	while (loop == 1) {
		std::cout << "ROCK, PAPER, OR SCISSORS?" << std::endl;
		std::cin >> result;
		if (result == "ROCK" || result == "PAPER" || result == "SCISSORS") {
			break;
		}
		else {
			std::cout << "Invalid input. Try again\n";
		}
	}
	return result;
}
/* loop could be better
* 
std::string player() {
    std::string result;
    while (true) {
        std::cout << "ROCK, PAPER, OR SCISSORS?" << std::endl;
        std::cin >> result;
        if (result == "ROCK" || result == "PAPER" || result == "SCISSORS") {
            return result;
        } else {
            std::cout << "Invalid input. Try again\n";
        }
    }
}

*/

int main() {
	std::string Result; //naming could be better, use PlayerChoice or ComputerChoice
	player(Result);

	std::string pcResult;
	srand(time(NULL)); //should be placed outside of main(), call it once only 
	int temp = rand() % 3 + 1;

	switch (temp) {
	case 1:
		pcResult = "ROCK";;
		break;
	case 2:
		pcResult = "PAPER";
		break;

	case 3:
		pcResult = "SCISSORS";
		break;
	}

	int playerWin = 0;

	if (Result == "ROCK"&&pcResult=="SCISSORS") {
		playerWin = 1;
	}
	else if (Result == "PAPER" && pcResult == "ROCK") {
		playerWin = 1;
	}
	else if (Result == "SCISSORS" && pcResult == "PAPER") {
		playerWin = 1;
	}

	if (Result == pcResult) {
		playerWin = 3;
		}
	/*if statements could be better and be more compact, 
	std::string finalResult;
if (Result == pcResult) {
    finalResult = "It's a draw!";
} else if ((Result == "ROCK" && pcResult == "SCISSORS") ||
           (Result == "PAPER" && pcResult == "ROCK") ||
           (Result == "SCISSORS" && pcResult == "PAPER")) {
    finalResult = "Player wins :)";
} else {
    finalResult = "PC wins :(";
}

*/

	std::string finalResult = (playerWin == 1) ? "Player wins :)" : "PC wins :(";
	if (playerWin == 3) {
		finalResult = "No winners or losers.";
	}
	std::cout << finalResult;
	std::cout << "\nPlayer move: " << Result;
	std::cout << "\nPC move: " << pcResult;

	return 0;
}


