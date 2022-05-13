#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"

MerkelMain::MerkelMain()
{
}

void MerkelMain::init()
{
    loadOrderBook();
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOptions(input);
    }
}

void MerkelMain::loadOrderBook()
{
    orders.push_back(OrderBookEntry{100,
                                    0.1,
                                    "hi",
                                    "yes",
                                    OrderBookType::bid});

    orders.push_back(OrderBookEntry{1500,
                                    0.01,
                                    "bye",
                                    "no",
                                    OrderBookType::ask});
}

void MerkelMain::printHelp()
{
    std::cout << "You do need help... You're broke!" << std::endl;
}

void MerkelMain::printMarketStats()
{
    std::cout << "No exchange stats here in Moscow" << std::endl;
    std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
}

void MerkelMain::enterAsk()
{
    std::cout << "Make an offer - enter amount:" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter amount:" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty. Re-evaluate your entire life." << std::endl;
}

void MerkelMain::gotoNextTimeframe()
{
    std::cout << "Proceeding to next step..." << std::endl;
}

void MerkelMain::printMenu()
{
    // Main menu options printed to console
    std::cout << "1: Print help" << std::endl;
    std::cout << "2: Print exchange stats" << std::endl;
    std::cout << "3: Make an offer" << std::endl;
    std::cout << "4: Make a bid" << std::endl;
    std::cout << "5: Print wallet" << std::endl;
    std::cout << "6: Continue" << std::endl;

    // Main menu divider
    std::cout << "=========================" << std::endl;

    // Main menu prompt
    std::cout << "Type in 1-6" << std::endl;
}

int MerkelMain::getUserOption()
{
    // User input
    int userOption{};
    std::cin >> userOption;
    std::cout << "You selected: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOptions(int userOption)
{
    // Conditional output based on user input
    if (userOption == 0 || userOption > 6)
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterAsk();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        gotoNextTimeframe();
    }
}