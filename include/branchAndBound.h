/**
 * PROJECT HEADER
 * @file branchAndBound.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 15/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef BRANCH_AND_BOUND_H
#define BRANCH_AND_BOUND_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>

#include "./algorithm.h"
#include "./problem.h"
#include "./node.h"

#pragma once

class BranchAndBound : public Algorithm {
  public:
    BranchAndBound() {}
    void setAlgorithm(Algorithm* initialSolutionAlgorithm);
    int getAmountOfNodes();
    std::vector<Node<Solution>> generateLeaf(Problem problem, Solution parent, int depth, int solutionSizeM);
    Solution generateBestSolution(std::vector<Element> initialX, Solution selectedElement, int solutionSizeM);
    Solution execute(Problem problem, int solutionSizeM);

  private:
    Algorithm* otherAlgorithm_;
    int amountOfNodes_;
    std::vector<Node<Solution>> activeNodes_;
};

#endif // !BRANCH_AND_BOUND_H