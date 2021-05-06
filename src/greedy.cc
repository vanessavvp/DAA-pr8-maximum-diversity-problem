/**
 * PROJECT HEADER
 * @input firstGreedy.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/greedy.h"

Solution Greedy::execute(Problem problem, int solutionSizeM) {
  std::vector<Element> initialElements = problem.getInitialX();
  Solution solutionS;
  Element gravityCenter = calculateGravityCenter(initialElements);
  do {
    std::pair<int, double> farthestElement;
    farthestElement.first  = 0;   // Position in initial elements
    farthestElement.second = 0.0; // Euclidean distance

    // Finds the farthest element
    for (int i = 0; i < initialElements.size(); i++) {
      float distance = calculateEuclideanDistance(gravityCenter, initialElements[i]);
      if (distance > farthestElement.second) {
        farthestElement.first  = i;
        farthestElement.second = distance;
      }
    }
    // Adds the farthest element to the solution
    solutionS.addElementToSolution(initialElements[farthestElement.first]);

    // Delete the farthest element from the initial elements
    std::vector<Element>::iterator it = initialElements.begin() + farthestElement.first;
    initialElements.erase(it);

    // Obtain the gravity center within the parcial solution
    gravityCenter = calculateGravityCenter(solutionS.getSolution());
  } while(solutionS.size() != solutionSizeM);

  double z = solutionS.calculateObjectiveFunction();
  return solutionS;  
}