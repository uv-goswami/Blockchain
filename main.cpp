#include "Blockchain.h"
#include <iostream>
#include <string>

int main() {
    Blockchain blockchain;

    while (true) {
        std::cout << "1. Add Transaction\n";
        std::cout << "2. View Blockchain\n";
        std::cout << "3. Exit\n";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string sender, receiver;
                int amount;
                std::cout << "Enter Sender: ";
                std::cin >> sender;
                std::cout << "Enter Receiver: ";
                std::cin >> receiver;
                std::cout << "Enter Amount: ";
                std::cin >> amount;
                blockchain.AddBlock(Block(blockchain.getChainSize(), sender, receiver, amount));
                break;
            }
            case 2: {
                blockchain.printChain();
                break;
            }
            case 3: {
                std::cout << "Exiting...\n";
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }

    return 0;
}
