/**
 * PROJECT HEADER
 * @input interChange.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef INTER_CHANGE_H
#define INTER_CHANGE_H

#include "./solution.h"
#include "./localSearch.h"

#pragma once

class InterChange : public LocalSearch {
  public:
    InterChange() {}
    ~InterChange() {}
    std::vector<Solution> generateNeighbours(Solution generatedSolution, std::vector<Element> initialX);
};

#endif // !INTER_CHANGE_H