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
#include "../include/branchAndBound.h"

#include <chrono>

std::string executeAndMeasureAlgorithms(Problem& problem, Algorithm* algorithm, int m);

int main(int argc, char* argv[]) {
  std::cout << "\n\tMAXIMUM DIVERSITY PROBLEM\n";
  std::string fileName = argv[1];
  Problem problem(fileName);

  // ---------------------------- First week assignment ----------------------------------------- //
  /*int solutionSizeM = 2;
  Greedy* greedy = new Greedy;
  std::cout << "Greedy: \n";
  std::string executionTime = executeAndMeasureAlgorithms(problem, greedy, solutionSizeM);
  problem.printSolution();
  std::cout << "Program execution time: " << executionTime;

  // Solution to be used in the local search
  Solution actualSolution = problem.getSolution();
  InterChange interChange;
  auto begin = std::chrono::system_clock::now();
  Solution final = interChange.execute(actualSolution, problem.getInitialX());
  auto end = std::chrono::system_clock::now();
  auto totalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  std::cout << "\nLocalSearch: \n";
  final.print();
  std::cout << "Program execution time: " << std::to_string(totalTime.count() * 1e-9) + " seconds\n";*/

  std::vector<std::string> problemFiles {"input/max_div_15_2.txt", 
                                         "input/max_div_20_2.txt",
                                         "input/max_div_30_2.txt",
                                         "input/max_div_15_3.txt",
                                         "input/max_div_20_3.txt",
                                         "input/max_div_30_3.txt"
                                      };

  /*// Generating output file with results for GREEDY
  std::ofstream outputFile;
  outputFile.open("greedy-results.csv");
  outputFile << "Problema, n, K, m, z, S, CPU" << std::endl;
  for (int i = 0; i < problemFiles.size(); i++) {
    Problem aux(problemFiles[i]);
    Greedy* greedy2 = new Greedy;
    // Each m value
    for (int m = 2; m < 6; m++) {
      std::string cpuTime = executeAndMeasureAlgorithms(aux, greedy2, m);
      outputFile << problemFiles[i] << ", " << aux.getNumberOfElementsN() << ", "; 
      outputFile << aux.getDimensionK() << ", " << m << ", " << aux.getSolution().getZ();
      outputFile << ", " << aux.getSolution().printFile() << ", " << cpuTime << std::endl;
    }
  }*/

  // Generating output file with results for LOCAL SEARCH
  /*std::cout << std::endl;
  std::ofstream outputFile2;
  outputFile2.open("local-search-results.csv");
  outputFile2 << "Problema, n, K, m, z, S, CPU" << std::endl;
  for (int i = 0; i < problemFiles.size(); i++) {
    Problem aux2(problemFiles[i]);
    Greedy* greedy3 = new Greedy;
    InterChange interChange2;
    // Each m value
    for (int m = 2; m < 6; m++) {
      executeAndMeasureAlgorithms(aux2, greedy3, m);
      Solution currentSolution = aux2.getSolution();
      auto begin = std::chrono::system_clock::now();
      Solution finalSolution = interChange2.execute(currentSolution, aux2.getInitialX());
      auto end = std::chrono::system_clock::now();
      auto totalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
      std::string cpuTime = std::to_string(totalTime.count() * 1e-9) + " seconds\n";
      outputFile2 << problemFiles[i] << ", " << aux2.getNumberOfElementsN() << ", "; 
      outputFile2 << aux2.getDimensionK() << ", " << m << ", " << finalSolution.getZ();
      outputFile2 << ", " << finalSolution.printFile() << ", " << cpuTime;
    }
  }*/

  // ---------------------------------------- Second week assignment --------------------------//
  /*GRASP* grasp = new GRASP;
  InterChange* interChange2 = new InterChange;
  std::cout << "GRASP: \n";
  srand(time(NULL));
  grasp->setLocalSearch(interChange2);
  grasp->setStopCriteria(true);
  grasp->setIterations(10);
  grasp->setK(2);
  executionTime = executeAndMeasureAlgorithms(problem, grasp, solutionSizeM);
  problem.printSolution();
  std::cout << "Program execution time: " << executionTime;*/


  // Generating output file with results for GRASP 
  /*std::ofstream outputFile3;
  outputFile3.open("grasp-results.csv");
  outputFile3 << "Problema, n, K, m, Iter, |LRC|, stop criteria, z, S, CPU" << std::endl;

  
  for (int i = 0; i < problemFiles.size(); i++) {
    Problem thirdProblem(problemFiles[i]);
    GRASP* secondGRASP = new GRASP;
    InterChange* interChange3 = new InterChange;
    secondGRASP->setLocalSearch(interChange3);
    for (int m = 2; m < 6; m++) {
      for (int it = 10; it <= 20; it += 10) {
        secondGRASP->setIterations(it);
        for (int k = 2; k < 4; k++) {
          secondGRASP->setK(k);
          for (int stopCriteria = 0; stopCriteria < 2; stopCriteria++) {
            secondGRASP->setStopCriteria((bool)stopCriteria);
            std::string cpuTime = executeAndMeasureAlgorithms(thirdProblem, secondGRASP, m);
            outputFile3 << problemFiles[i] << ", " << thirdProblem.getNumberOfElementsN() << ", "; 
            outputFile3 << thirdProblem.getDimensionK() << ", " << m << ", " << secondGRASP->getIterations();
            outputFile3 << ", " << secondGRASP->getK() << ", " <<  std::boolalpha << secondGRASP->getStopCriteria();
            outputFile3 << ", " <<thirdProblem.getSolution().getZ() << ", "<< thirdProblem.getSolution().printFile();
            outputFile3 << ", " << cpuTime << std::endl;
          }
        }
      }
    }
  }*/

  // ---------------------------------------- Third week assignment --------------------------//
  BranchAndBound* branchAndBound = new BranchAndBound();
  Greedy* greedy4 = new Greedy(); 
  branchAndBound->setAlgorithm(greedy4);
  executeAndMeasureAlgorithms(problem, branchAndBound, 4);

  std::ofstream outputFile4;
  outputFile4.open("branch-bound-results.csv");
  outputFile4 << "Problema, n, K, m, z, S, CPU, nodos generados" << std::endl;
  
  /*for (int i = 0; i < problemFiles.size(); i++) {
    Problem fourthProblem(problemFiles[i]);
    BranchAndBound* branchAndBound = new BranchAndBound;
    Greedy* greedy4 = new Greedy; 
    branchAndBound->setAlgorithm(greedy4);
    for (int m = 2; m < 6; m++) {
      std::string cpuTime = executeAndMeasureAlgorithms(fourthProblem, branchAndBound, m);
      outputFile4 << problemFiles[i] << ", " << fourthProblem.getNumberOfElementsN() << ", ";
      outputFile4 << fourthProblem.getDimensionK() << m << ", " << fourthProblem.getSolution().getZ();
      //outputFile4 << ", " << fourthProblem.getSolution().printFile() << ", " << cpuTime << ", ";
      //outputFile4 << branchAndBound->getAmountOfNodes();
    }
  }*/
}


std::string executeAndMeasureAlgorithms(Problem& problem, Algorithm* algorithm, int m) {
  std::string string;
  problem.setAlgorithm(algorithm);
  auto begin = std::chrono::system_clock::now();
  problem.execute(m);
  auto end = std::chrono::system_clock::now();
  auto totalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
  string = std::to_string(totalTime.count() * 1e-9) + " seconds\n";
  return string;
}
