/**
 * PROJECT HEADER
 * @file element.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <vector>

#pragma once

class Element {
 public:
  Element() {};
  Element(int dimensionK);
  ~Element() {};

  std::vector<double> getCoordinates();
  int getDimensionK();

  void addCoordinate(int newCoordinate);
  void print();

  double& operator[](int index);

 private:
  std::vector<double> coordinates_;
  int dimensionK_;
};

#endif // !ELEMENT_H