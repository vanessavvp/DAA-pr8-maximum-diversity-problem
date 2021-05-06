/**
 * PROJECT HEADER
 * @input localSearch.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 03/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/localSearch.h"

Solution LocalSearch::execute(Solution& generatedSolution, std::vector<Element> initialX) {
  Solution actualSolution;
  Solution bestSolution = generatedSolution;
  do {
    actualSolution = bestSolution;
    std::vector<Solution> neighbours = generateNeighbours(actualSolution, initialX);
    for (int i = 0; i < neighbours.size(); ++i) {
      if (neighbours[i].getZ() > bestSolution.getZ()) {
        bestSolution = neighbours[i];
      }
    }
  } while (bestSolution != actualSolution);

  return bestSolution;
} 