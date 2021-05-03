/**
 * PROJECT HEADER
 * @file solution.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/solution.h"

int Solution::size() {
  return solution_.size();
}


void Solution::addElementToSolution(Element newElement) {
  solution_.push_back(newElement);
}


void Solution::print() {
  std::cout << "\n\nFinal solution: \n";
  for (int i = 0; i < size(); i++) {
    solution_[i].print();
    std::cout << " ";
  }
  std::cout << std::endl;
}
