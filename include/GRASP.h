/**
 * PROJECT HEADER
 * @file GRASP.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef GRASP_H
#define GRASP_H

#include <iostream>

#include "./algorithm.h"
#include "./problem.h"
#include "./formulas.h"
#include "./localSearch.h"

#pragma once

typedef std::pair<int, double> farthestElement;
class GRASP : public Algorithm {
  public: 
    GRASP() {};
    ~GRASP() {};

    void setK();
    void setK(int k);
    void setIterations(int iterations);
    void setLocalSearch(LocalSearch* localSearch);
    void setStopCriteria(bool stopCriteria);

    int getK();
    int getIterations();
    bool getStopCriteria();

    std::vector<farthestElement> bestKValues(std::vector<farthestElement> distances);
    Solution constructivePhase(Problem problem, int solutionSizeM);
    Solution execute(Problem problem, int solutionSizeM);

  private:
    int k_;
    int iterations_;
    bool iterationsWithImprovement_;
    LocalSearch* localSearch_;
};

#endif // !GRASP_H