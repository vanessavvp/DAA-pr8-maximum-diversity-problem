/**
 * PROJECT HEADER
 * @file element.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/element.h"


Element::Element(int dimensionK) {
  dimensionK_ = dimensionK;
  coordinates_.resize(dimensionK);
}


std::vector<double> Element::getCoordinates() {
  return coordinates_;
}


int Element::getDimensionK() {
  return dimensionK_;
}


void Element::addCoordinate(double newCoordinate) {
  if (coordinates_.size() < dimensionK_) {
    coordinates_.push_back(newCoordinate);
  } 
  else {
    std::cerr << "ERROR: Class Element - There is no possible to add another coordinate because of the k-dimension" << std::endl;
  }
}


void Element::print() {
  for (int i = 0; i < dimensionK_; i++) {
    std::cout << coordinates_[i];
    if (i < (coordinates_.size() - 1)) {
      std::cout << ", ";
    }
  }
}


double& Element::operator[](int index) {
  if (index >= getDimensionK()) {
    std::cerr << "ERROR: Class Element - The required element index is greater than the k-dimension" << std::endl;
    exit(1);
  }
  return coordinates_[index];
}


double Element::getCoordinate(int index) {
  return coordinates_[index];
}
