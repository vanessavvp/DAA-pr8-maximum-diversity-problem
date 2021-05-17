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
#define MAX_FLOAT 159874.23

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
    BranchAndBound(Algorithm* initialSolutionAlgorithm);
    void setAlgorithm(Algorithm* initialSolutionAlgorithm);
    int getAmountOfNodes();
    std::vector<Node<Solution>> generateLeaf(Problem problem, Solution parent, int depth, int solutionSizeM);
    Solution generateBestSolution(std::vector<Element> initialX, Solution selectedElement, int solutionSizeM);
    Solution execute(Problem problem, int solutionSizeM);
    std::vector<Node<Solution>> sortByOption(std::vector<Node<Solution>>& activeNodes);
    void setOption(int option);

  private:
    Algorithm* otherAlgorithm_;
    int amountOfNodes_;
    std::vector<Node<Solution>> activeNodes_;
    int option_;
};

#endif // !BRANCH_AND_BOUND_H