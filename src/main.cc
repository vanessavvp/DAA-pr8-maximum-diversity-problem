/**
 * PROJECT HEADER
 * @input main.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 02/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/problem.h"
#include "../include/greedy.h"
#include "../include/GRASP.h"
#include "../include/interChange.h"

#include <chrono>

int main(int argc, char* argv[]) {
  std::cout << "\n\tMAXIMUM DIVERSITY PROBLEM\n";
  std::string fileName = argv[1];
  Problem problem(fileName);

  // ---------------------------- First week assignment ----------------------------------------- //
  int solutionSizeM = 3;
  Greedy* greedy = new Greedy;
  problem.setAlgorithm(greedy);
  problem.execute(solutionSizeM);
  std::cout << "Greedy: \n";
  problem.printSolution();

  // Solution to be used in the local search
  Solution actualSolution = problem.getSolution();
  // InterChange* interChange = new InterChange;
  InterChange interChange;
  Solution final = interChange.execute(actualSolution, problem.getInitialX());
  std::cout << "\nLocalSearch: \n";
  final.print();
}