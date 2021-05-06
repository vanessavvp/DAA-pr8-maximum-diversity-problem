/**
 * PROJECT HEADER
 * @input interChange.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 03/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/interChange.h"

/**
 * Interchanges an element within the generated solution for an element that has been 
 * not included, from the initial set of elements
 **/
std::vector<Solution> InterChange::generateNeighbours(Solution generatedSolution, std::vector<Element> initialX) {
  std::vector<Solution> result;
  std::vector<Element> aux = initialX;

  // Delete every element of the generated solution that are inside the initial set of elements
  std::vector<Element> solutionElements = generatedSolution.getSolution();
  for (int i = 0; i < solutionElements.size(); i++) {
    std::vector<Element>::iterator initialXIterator = std::find(aux.begin(), aux.end(), solutionElements[i]);
    // Element found in the initial set
    if (initialXIterator != aux.end()) {
      int position = std::distance(aux.begin(), initialXIterator);
      std::vector<Element>::iterator it = aux.begin() + position;
      aux.erase(it);
    }
  }

  // InterChange
  Solution actualSolution;
  std::vector<Element> auxInitial = aux;
  for (int i = 0; i < aux.size(); i++) {
    for (int j = 0; j < solutionElements.size(); j++) {
      actualSolution = generatedSolution;
      Element tempElement = actualSolution[j];
      actualSolution[j] = auxInitial[i];
      actualSolution.calculateObjectiveFunction();
      result.push_back(actualSolution);
    }
  }

  return result;
}
