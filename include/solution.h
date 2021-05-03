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

#pragma once

class Solution {
  public:
    Solution() {};
    Solution(int dimensionK, int numberOfElementsN);
    ~Solution() {};

    std::vector<Element> getSolution();
    void addElementToSolution(Element newElement);
    double calculateObjectiveFunction();
    int size();
    void print();
    
  private:
    std::vector<Element> solution_;
    int dimensionK_;
    int numberOfElementsN_;
};

#endif // !SOLUTION_H