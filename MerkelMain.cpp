#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

MerkelMain::MerkelMain()
{
}

void MerkelMain::init()
{
    int input;
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOptions(input);
    }
}

void MerkelMain::printHelp()
{
    std::cout << "You do need help... You're broke!" << std::endl;
}

void MerkelMain::printMarketStats()
{
    for (std::string const &p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;

        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                  p,
                                                                  "2020/03/17 17:01:24.884492");

        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
    // std::cout << "OrderBook contains: " << orders.size() << " entries" << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;

    // for (OrderBookEntry &e : orders)
    // {
    //     if (e.orderType == OrderBookType::ask)
    //     {
    //         asks++;
    //     }
    //     if (e.orderType == OrderBookType::bid)
    //     {
    //         bids++;
    //     }
    // }

    // std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl;
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