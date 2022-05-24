#pragma once

#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
public:
    MerkelMain();
    // Call this to start simulation
    void init();

private:
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    void printMenu();
    int getUserOption();
    void processUserOptions(int userOption);

    std::string currentTime;

    OrderBook orderBook{"20200317.csv"};
};