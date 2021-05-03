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
  Solution actualSolution;

  // Delete every element of the generated solution that are inside the initial set of elements
  std::vector<Element> solutionElements = generatedSolution.getSolution();
  for (int i = 0; i < solutionElements.size(); i++) {
    std::vector<Element>::iterator initialXIterator = std::find(initialX.begin(), initialX.end(), solutionElements[i]);
    // Element found in the initial set
    if (initialXIterator != initialX.end()) {
      int position = std::distance(initialX.begin(), initialXIterator);
      std::vector<Element>::iterator it = initialX.begin() + position;
      initialX.erase(it);
    }
  }

  // InterChange

  return result;
}
