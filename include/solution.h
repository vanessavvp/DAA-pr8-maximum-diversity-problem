/**
 * PROJECT HEADER
 * @file solution.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>

#include "./element.h"
#include "./formulas.h"

#pragma once

class Solution {
  public:
    Solution() {};
    Solution(int dimensionK, int numberOfElementsN);
    ~Solution() {};

    std::vector<Element> getSolution() const;
    void addElementToSolution(Element newElement);
    double calculateObjectiveFunction();
    double getZ() const;
    int size();
    std::string printFile();
    void print();
    bool operator ==(const Solution& solution);
    bool operator!=(const Solution& solution);
    Element& operator[](int index);
    
  private:
    std::vector<Element> solution_;
    int dimensionK_;
    int numberOfElementsN_;
    double z_;
};

#endif // !SOLUTION_H