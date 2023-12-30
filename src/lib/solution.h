#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <iostream>
#include <vector>

struct Material
{
    int year;
    int tonnes;
};

struct ProductionShareDropDown
{
    int cumulativeMineProducedStart;
    int cumulativeMineProducedEnd;
    int companyProductionSharePercentage;
    int cumulativeMineProduction;
};

/**
 * Cumulative Mine Produced Start - the starting tonnage threshold that the rule should apply from.
 * Cumulative Mine Produced End - the ending tonnage threshold that the rule should apply to.
 * Company Production Share Percentage - the amount the Company is expecting to receive for the
 * material within the thresholds above.
 * Note: This is not necessarily a decreasing percentage.
 *
 * Tonnes are added from the start of Mine production.
 * Rules:
 * - If the company produced this amount, it'll yield 100% and then decrease according to the rules.
 * - Example:
 *    - 0 --> 2500  -- yield 100%
 *    - 2500 --> infinity -- yield 50%
 *
 * Begin year 0:
 * - Year input adds to the previous year.
 * - Check the rule.
 * - Apply appropriate percentage (100%).
 */

class Solution
{
private:
    /* data */

public:
    Solution();
    ~Solution();

    std::string printHelloWorld();
    void rulesProductionShareDropDown(std::vector<ProductionShareDropDown> &productionShareDropDown);
    void enterOriginalMaterial(std::vector<Material> &originalMaterial);
    void calculateActualMaterial(const std::vector<Material> &originalMaterialList,
                                 std::vector<ProductionShareDropDown> &productionShareDropDownList,
                                 std::vector<Material> &actualMaterialList);
    void outputResult(const std::vector<Material> &actualMaterial);
};

#endif
