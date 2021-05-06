/**
 * PROJECT HEADER
 * @input GRASP.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 06/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/GRASP.h"


void GRASP::setK() {
  std::cout << "\nIntroduce the k value: ";
  std::cin >> k_;
}


void GRASP::setK(int k) {
  k_ = k;
}


int GRASP::getK() {
  return k_;
}


bool sortBySecondDesc(const farthestElement& first, const farthestElement& second) {
  return first.second > second.second;
}


std::vector<farthestElement> GRASP::bestKValues(std::vector<farthestElement> distances) {
  std::sort(distances.begin(), distances.end(), sortBySecondDesc);
  distances.resize(k_);
  return distances;
}


Solution GRASP::execute(Problem problem, int solutionSizeM) {
  std::vector<Element> initialElements = problem.getInitialX();
  Solution solutionS;
  Element gravityCenter = calculateGravityCenter(initialElements);
  do {
    std::vector<farthestElement> distances;
    std::vector<farthestElement> bestKDistances;

    farthestElement choosedElement;

    // Finds every distance to the gravity center from initial elements
    for (int i = 0; i < initialElements.size(); i++) {
      float distance = calculateEuclideanDistance(gravityCenter, initialElements[i]);
      choosedElement.first = i;
      choosedElement.second = distance;
      distances.push_back(choosedElement);
    }

    // Adds the farthest random element to the solution
    bestKDistances = bestKValues(distances);
    int random = (std::rand() % bestKDistances.size()); 
    solutionS.addElementToSolution(initialElements[bestKDistances[random].first]);
  
    // Delete the farthest element from the initial elements
    std::vector<Element>::iterator it = initialElements.begin() + bestKDistances[random].first;
    initialElements.erase(it);

    // Obtain the gravity center within the parcial solution
    gravityCenter = calculateGravityCenter(solutionS.getSolution());
  } while(solutionS.size() != solutionSizeM);

  double z = solutionS.calculateObjectiveFunction();
  return solutionS;  
}