/**
 * PROJECT HEADER
 * @file localSearch.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef LOCAL_SEARCH_H
#define LOCAL_SEARCH_H

#include <algorithm>

#include "./solution.h"

#pragma once

class LocalSearch {
  public:
    ~LocalSearch() = default;
    Solution execute(Solution& generatedSolution, std::vector<Element> initialX);
    virtual std::vector<Solution> generateNeighbours(Solution generatedSolution, std::vector<Element> initialX) = 0;
};

#endif // !LOCAL_SEARCH_H