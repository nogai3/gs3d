#include <iostream>
#include <random>

void game(int epoch) {
    int maxNum;
    int computer;
    int player;
    switch (epoch) {
        case 0:
            std::cout << "It`s game: Guess Number!\nPlease write the max number, which the computer can guess: ";
            std::cin >> maxNum;
            computer = rand() % (maxNum - 1 + 1) + 1;
            epoch++;
            break;
        case 1:
            std::cout << "I guess! Try here: ";
            std::cin >> player;
            epoch++;
            break;
    }

    if (player < computer) {
        std::cout << "Greater!" << std::endl;
        game(1);
    }  else if (player > computer) {
        std::cout << "Lower!" << std::endl;
        game(1);
    } else {
        std::cout << "Good job!" << std::endl;
    }
}

int main() {
    game(0);
}