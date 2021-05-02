/**
 * PROJECT HEADER
 * @file problem.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/problem.h"

Problem::Problem(std::string& inputFileName) {
  readFile(inputFileName);
}


void Problem::readFile(std::string& inputFileName) {
  std::ifstream file(inputFileName);
  std::string lineInfo;

  if (!file.good()) {
    std::cerr << "\nERROR: The inputfile " << inputFileName << " could not be readed\n"; 
  } else {
    std::cout << "\tThe inputfile " << inputFileName << " was correctly readed...\n";

    // Number of elements
    getline(file, lineInfo);
    std::istringstream elements(lineInfo);
    while (elements >> lineInfo);
    numberOfElementsN_ = std::stoi(lineInfo);
    std::cout << "Number of elements n: " << numberOfElementsN_ << std::endl;
    initialX_.resize(numberOfElementsN_);

    // K-dimension
    getline(file, lineInfo);
    std::istringstream dimension(lineInfo);
    while (dimension >> lineInfo);
    dimensionK_ = std::stoi(lineInfo);
    std::cout << "K-dimension: " << dimensionK_ << std::endl;

    // Set of initial elements
    int count = 0;
    while (getline(file, lineInfo)) {
      std::istringstream element(lineInfo);
      // Parse commas to dots for it to be save as a float number
      element.imbue(std::locale(""));
      Element coordinates(dimensionK_);
      for (int i = 0; i < dimensionK_; i++) {
        element >> coordinates[i];
      }
      initialX_[count] = coordinates;
      count++;
    }
  }
}


void Problem::printInitialX() {
  for (int i = 0; i < initialX_.size(); i++) {
    std::cout << "Solution " << i << ": { ";
    initialX_[i].print();
    std::cout << " }\n";
  }
}



int Problem::getNumberOfElementsN() {
  return numberOfElementsN_;
}
    
    
int Problem::getDimensionK() {
  return dimensionK_;
}


std::vector<Element> Problem::getInitialX() {
  return initialX_;
}