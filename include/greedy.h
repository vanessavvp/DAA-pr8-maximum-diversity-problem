/**
 * PROJECT HEADER
 * @file greedy.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef GREEDY_H
#define GREEDY_H

#include <iostream>

#include "./algorithm.h"
#include "./problem.h"
#include "./formulas.h"
#include "./localSearch.h"

#pragma once

class Greedy : public Algorithm {
  public: 
    Greedy() {};
    ~Greedy() {}
    Solution execute(Problem problem, int solutionSizeM);
};

#endif // !GREEDY_H
