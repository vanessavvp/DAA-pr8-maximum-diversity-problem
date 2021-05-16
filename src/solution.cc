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


Solution::Solution(int dimensionK, int numberOfElementsN) {
  dimensionK_ = dimensionK;
  numberOfElementsN_ = numberOfElementsN;
}


int Solution::size() {
  return solution_.size();
}


void Solution::addElementToSolution(Element newElement) {
  solution_.push_back(newElement);
}


std::string Solution::printFile() {
  std::string string;
  for (int i = 0; i < solution_.size(); i++) {
    string.append(solution_[i].printFile() + " ");
  }
  return string;
}


void Solution::print() {
  for (int i = 0; i < solution_.size(); i++) {
    solution_[i].print();
    std::cout << " ";
  }
  std::cout << std::endl;
  std::cout << "z: " << getZ() << std::endl;
}


double Solution::calculateObjectiveFunction() {
  z_ = 0;
  for (int i = 0; i < solution_.size(); i++) {
    for (int j = i + 1; j < solution_.size(); j++) {
      z_ += calculateEuclideanDistance(solution_[i], solution_[j]);
    }
  }
  return z_;
}


std::vector<Element> Solution::getSolution() const {
  return solution_;
}


double Solution::getZ() const {
  return z_;
}


bool Solution::operator ==(const Solution& solution) {
  if ((solution.getSolution() == solution_) && (solution.getZ() == getZ())) {
    return true;
  }
  return false;
}


bool Solution::operator!=(const Solution& solution) {
  Solution solutionCopy = solution;
  return !(solutionCopy == *this);
}


Element& Solution::operator[](int index) {
  if (index >= solution_.size()) {
    std::cerr << "\nERROR: Class Solution - Required index greater than the number of elements within the solution\n";
    exit(1);
  }
  return solution_[index];
}


void Solution::resize(int size) {
  solution_.resize(size);
}

