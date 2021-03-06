//
// Created by b.karjoo on 3/23/2017.
//

#ifndef BRIMUS_BAR_SERIES_H
#define BRIMUS_BAR_SERIES_H

#include "stdafx.h"
#include "bar.h"
#include "bar_time.h"
#include "stock.h"
#include "stock_field.h"

class bar_series {
    std::map<bar_time,std::shared_ptr<bar> > bars;
    std::shared_ptr<bar> current_bar = nullptr;
    unsigned short int bar_duration = 1;
    std::string symbol;
    std::vector<std::function<void(std::string)> > newBarObservers;
public:
    bar_series(std::string _symbol) : symbol(_symbol) {}
    const std::string &getSymbol() const;
    void setSymbol(const std::string &symbol);
    void add_price(std::string timestamp,double price);
    std::string to_string() const;
    unsigned short getBar_duration() const;
    void setBar_duration(unsigned short bar_duration);
    std::function<void(const stock&, stock_field)> get_callback();
    const std::shared_ptr<bar> CurrentBar() const { return current_bar; }
    const std::shared_ptr<bar> PreviousBar(unsigned int i) const;
    double AverageClose(int numberOfBars);
    double AverageClose(int numberOfBars, int barsBack);
    double AverageHigh(int numberOfBars);
    double AverageHigh(int numberOfBars, int barsBack);
    double AverageLow(int numberOfBars);
    double AverageLow(int numberOfBars, int barsBack);
    double MaxClose(int numberOfBars);
    double MaxClose(int numberOfBars, int barsBack);
    double MaxHigh(int numberOfBars);
    double MaxHigh(int numberOfBars, int barsBack);
    double MaxLow(int numberOfBars);
    double MaxLow(int numberOfBars, int barsBack);
    double MinClose(int numberOfBars);
    double MinClose(int numberOfBars, int barsBack);
    double MinHigh(int numberOfBars);
    double MinHigh(int numberOfBars, int barsBack);
    double MinLow(int numberOfBars);
    double MinLow(int numberOfBars, int barsBack);

    void AddNewBarObserver(std::function<void(std::string)>);

};
#endif //BRIMUS_BAR_SERIES_H