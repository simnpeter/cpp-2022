//
// Created by SP on 2023. 01. 07..
//

#ifndef CPP_2022_SETTLEMENTSTATISTICSIMPL_H
#define CPP_2022_SETTLEMENTSTATISTICSIMPL_H

#include "Settlement.h"
#include "SettlementStatistics.h"
#include <map>

class SettlementStatisticsImpl : public SettlementStatistics {
private:
    multimap<string, Settlement> data;
public:
    explicit SettlementStatisticsImpl(const string& fileName);
    int numSettlements() const override;
    int numCounties() const override;
    int numSettlementsByCounty(const string& county) const override;
    vector<Settlement> findSettlementsByCounty(const string& county) const override;
    Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const override;
    Settlement maxPopulationDensity() const override;
    Settlement minPopulationDensity() const override;
    vector<Settlement> findSettlementsByName(const string& name) override;
};
#endif //CPP_2022_SETTLEMENTSTATISTICSIMPL_H
