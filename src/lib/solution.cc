#include "solution.h"

Solution::Solution()
{
}

Solution::~Solution()
{
}

std::string Solution::printHelloWorld()
{
     return "Hello World!";
}

void Solution::rulesProductionShareDropDown(std::vector<ProductionShareDropDown> &productionShareDropDown)
{
     ProductionShareDropDown psdd;
     std::cout << "Enter the Cumulative Mine Produced Start " << std::endl;
     std::cin >> psdd.cumulativeMineProducedStart;

     std::cout << "Enter the Cumulative Mine Produced End " << std::endl;
     std::cin >> psdd.cumulativeMineProducedEnd;

     std::cout << "Enter the Company Production Share Percentage " << std::endl;
     std::cin >> psdd.companyProductionSharePercentage;

     productionShareDropDown.push_back(psdd);
}

void Solution::enterOriginalMaterial(std::vector<Material> &originalMaterial)
{
     Material orgMaterial;
     std::cout << "Enter the year " << std::endl;
     std::cin >> orgMaterial.year;

     std::cout << "Enter the materials in tonnes" << std::endl;
     std::cin >> orgMaterial.tonnes;

     originalMaterial.push_back(orgMaterial);
}

void Solution::calculateActualMaterial(const std::vector<Material> &originalMaterialList,
                                       std::vector<ProductionShareDropDown> &productionShareDropDownList,
                                       std::vector<Material> &actualMaterialList)
{
     int sum = 0;
     int percentage = 0;
     int residual = 0;
     Material actMaterial{2000, 0};

     for (const Material &material : originalMaterialList)
     {
          sum += material.tonnes;
          actMaterial.tonnes = material.tonnes;
          actMaterial.year = material.year;
     }

     for (ProductionShareDropDown &productionShareDropDown : productionShareDropDownList)
     {
          if (productionShareDropDown.cumulativeMineProducedEnd > productionShareDropDown.cumulativeMineProducedStart)
          {
               if (sum <= productionShareDropDown.cumulativeMineProducedEnd)
               {
                    percentage = productionShareDropDown.companyProductionSharePercentage;
                    productionShareDropDown.cumulativeMineProduction -= actMaterial.tonnes;
               }
               else if ((actMaterial.tonnes - productionShareDropDown.cumulativeMineProduction) > 0)
               {
                    residual = (productionShareDropDown.cumulativeMineProduction * productionShareDropDown.companyProductionSharePercentage) / 100;
                    actMaterial.tonnes -= productionShareDropDown.cumulativeMineProduction;
                    productionShareDropDown.cumulativeMineProduction = 0;
               }
          }
          else if (sum > productionShareDropDown.cumulativeMineProducedStart)
          {
               percentage = productionShareDropDown.companyProductionSharePercentage;
          }
     }

     actMaterial.tonnes = ((actMaterial.tonnes * percentage) / 100) + residual;
     actualMaterialList.push_back(actMaterial);
     // std::cout << "Year: " << actMaterial.year << ", Material: " << actMaterial.tonnes << "t\n" << std::endl;
}

void Solution::outputResult(const std::vector<Material> &actualMaterial)
{
     for (Material a : actualMaterial)
     {
          std::cout << "Year: " << a.year << ", Material: " << a.tonnes << "t" << std::endl;
     }
}
