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
    // --------------------- trace
    std::cout << "\n------------\n";
    std::cout << "\nGravity center: \n"; gravityCenter.print();
    std::cout << std::endl;

    std::pair<int, double> farthestElement;
    farthestElement.first  = 0;   // Position in initial elements
    farthestElement.second = 0.0; // Euclidean distance

    // Finds the farthest element
    for (int i = 0; i < initialElements.size(); i++) {
      float distance = problem.getEuclideanDistance(gravityCenter, initialElements[i]);
      // --------------------- trace
      std::cout << "\ncurrent: "; initialElements[i].print();
      std::cout << " dist: " << distance;
      if (distance > farthestElement.second) {
        farthestElement.first  = i;
        farthestElement.second = distance;
      }
    }
    // --------------------- trace
    std::cout << "\nfarthest: "; initialElements[farthestElement.first].print();

    // Adds the farthest element to the solution
    solutionS.addElementToSolution(initialElements[farthestElement.first]);

    // Delete the farthest element from the initial elements
    std::vector<Element>::iterator it = initialElements.begin() + farthestElement.first;
    initialElements.erase(it);

    // Obtain the gravity center within the parcial solution
    gravityCenter = calculateGravityCenter(initialElements);
  } while(solutionS.size() != solutionSizeM);

  // TODO: Calculate the objective function
  double z = solutionS.calculateObjectiveFunction();
  std::cout << "\n\nz: " << z << std::endl;
  return solutionS;  
}
