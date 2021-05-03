/**
 * PROJECT HEADER
 * @file formulas.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef FORMULAS_H
#define FORMULAS_H

#include <cmath>

#include "./element.h"

#pragma once

/**
 * Returns the calculus of the euclidean distance between two given elements
 **/
double calculateEuclideanDistance(Element first, Element second) {
  double distance = 0;
  for (int i = 0; i < first.getDimensionK(); i++) {
    distance += (pow((first[i] - second[i]), 2));
  }
  distance = sqrt(distance);
  return distance;
}

#endif // !FORMULAS_H