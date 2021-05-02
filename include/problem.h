/**
 * PROJECT HEADER
 * @file problem.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <locale>

#include "./element.h"
#include "./solution.h"
#include "./algorithm.h"

#pragma once

class Algorithm;
class Problem {
  public:
    Problem(std::string& inputFileName);
    ~Problem() {};

    int getNumberOfElementsN();
    int getDimensionK();
    std::vector<Element> getInitialX();

    void readFile(std::string& inputFileName);
    void printInitialX();

  private:
    int numberOfElementsN_;
    int dimensionK_;
    std::vector<Element> initialX_;
    Algorithm* algorithm_;
    Solution solution_;
};

#endif // !PROBLEM_H