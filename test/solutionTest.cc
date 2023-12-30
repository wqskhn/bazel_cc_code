#include "src/lib/solution.h"
#include <gtest/gtest.h>

TEST(SolutionTest, SingleValueWithSingleRule)
{
    Solution solution;
    std::vector<Material> originalMaterialList;
    std::vector<ProductionShareDropDown> productionShareDropDownList;
    std::vector<Material> actualMaterialList;

    Material material1{2022, 1000};
    originalMaterialList = {material1};
    ProductionShareDropDown psdd1{0, 2500, 100, 2500};
    productionShareDropDownList = {psdd1};
    solution.calculateActualMaterial(originalMaterialList, productionShareDropDownList, actualMaterialList);

    ASSERT_EQ(1, actualMaterialList.size());
    ASSERT_EQ(2022, actualMaterialList[0].year);
    ASSERT_EQ(1000, actualMaterialList[0].tonnes);
}

TEST(SolutionTest, SingleValueWithMultipleRules)
{
    Solution solution;
    std::vector<Material> originalMaterialList;
    std::vector<ProductionShareDropDown> productionShareDropDownList;
    std::vector<Material> actualMaterialList;

    Material material2{2023, 1500};
    originalMaterialList = {material2};
    ProductionShareDropDown psdd2{0, 2500, 100, 2500};
    ProductionShareDropDown psdd3{2500, 0, 50, 2500};
    productionShareDropDownList = {psdd2, psdd3};
    solution.calculateActualMaterial(originalMaterialList, productionShareDropDownList, actualMaterialList);

    ASSERT_EQ(1, actualMaterialList.size());
    ASSERT_EQ(2023, actualMaterialList[0].year);
    ASSERT_EQ(750, actualMaterialList[0].tonnes); // (1500 * 50%) due to second rule
}

TEST(SolutionTest, MultipleValuesWithMultipleRules)
{
    Solution solution;
    std::vector<Material> originalMaterialList;
    std::vector<ProductionShareDropDown> productionShareDropDownList;
    std::vector<Material> actualMaterialList;
    Material material1{2022, 1000};
    Material material2{2023, 1500};
    Material material3{2024, 900};
    Material material4{2025, 1000};
    originalMaterialList = {material1, material2, material3, material4};
    ProductionShareDropDown psdd1{0, 2500, 100, 2500};
    ProductionShareDropDown psdd2{0, 2500, 100, 2500};
    ProductionShareDropDown psdd3{2500, 0, 50, 2500};
    productionShareDropDownList = {psdd1, psdd2, psdd3};
    solution.calculateActualMaterial(originalMaterialList, productionShareDropDownList, actualMaterialList);

    ASSERT_EQ(4, actualMaterialList.size());
    ASSERT_EQ(2024, actualMaterialList[2].year);
    ASSERT_EQ(675, actualMaterialList[2].tonnes); // (900 * 75%) due to third rule
}

TEST(SolutionTest, EdgeCaseSplitPercentage)
{
    Solution solution;
    std::vector<Material> originalMaterialList;
    std::vector<ProductionShareDropDown> productionShareDropDownList;
    std::vector<Material> actualMaterialList;
    Material material1{2022, 1000};
    Material material2{2023, 1500};
    Material material3{2024, 900};
    Material material4{2025, 1000};
    Material material5{2026, 1200};
    originalMaterialList = {material1, material2, material3, material4, material5};
    ProductionShareDropDown psdd1{0, 2500, 100, 2500};
    ProductionShareDropDown psdd2{0, 2500, 100, 2500};
    ProductionShareDropDown psdd3{2500, 0, 50, 2500};
    productionShareDropDownList = {psdd1, psdd2, psdd3};
    solution.calculateActualMaterial(originalMaterialList, productionShareDropDownList, actualMaterialList);

    ASSERT_EQ(5, actualMaterialList.size());
    ASSERT_EQ(2026, actualMaterialList[4].year);
    ASSERT_EQ(900, actualMaterialList[4].tonnes); // (1200 * 75%) due to third rule
}
