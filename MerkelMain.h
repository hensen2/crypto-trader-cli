#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkelMain
{
public:
    MerkelMain();
    // Call this to start simulation
    void init();

private:
    void loadOrderBook();
    void printHelp();
    void printMarketStats();
    void enterAsk();
    void enterBid();
    void printWallet();
    void gotoNextTimeframe();
    void printMenu();
    int getUserOption();
    void processUserOptions(int userOption);

    std::vector<OrderBookEntry> orders;
};