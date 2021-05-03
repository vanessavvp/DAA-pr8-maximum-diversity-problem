/**
 * PROJECT HEADER
 * @file algorithm.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/algorithm.h"

Element Algorithm::calculateGravityCenter(std::vector<Element> elements) {
  double result = 0.0;
  Element newElement(elements[0].getDimensionK());
  // Each coordinate of the element (k-dimension)
  for (int i = 0; i < elements[0].getDimensionK(); i++) {
    result = 0.0;
    // Sum of all elements for the same coordinate
    for (int j = 0; j < elements.size(); j++) {
      result += elements[j].getCoordinate(i);
    }
    result /= elements.size();
    newElement[i] = result;
  }
  return newElement;
}


