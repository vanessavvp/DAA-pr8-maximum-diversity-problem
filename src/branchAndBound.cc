/**
 * PROJECT HEADER
 * @file branchAndBound.cc
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 15/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#include "../include/branchAndBound.h"

void BranchAndBound::setAlgorithm(Algorithm* initialSolutionAlgorithm) {
  otherAlgorithm_ = initialSolutionAlgorithm;
}


Solution BranchAndBound::execute(Problem problem, int solutionSizeM) {
  // Generate the initial lower bound from Greedy or GRASP algorithms settled before
  Solution initialSolution = otherAlgorithm_->execute(problem, solutionSizeM);
  float lowerBound = initialSolution.getZ();
  std::cout << std::endl << "INITIAL SOLUTION: "; initialSolution.print();
  std::cout << std::endl << "INITIAL LOWER BOUND: " << lowerBound << std::endl;


  // Create a set of active nodes to be expanded
  // DEPTH = 0, because is the first iteration and none of the coordinates are permanent
  std::vector<Node<Solution>> activeNodes = generateLeaf(problem, initialSolution, 0, solutionSizeM);
  Node<Solution> actualNode(activeNodes[0].getSolution(), 0);
  double min = activeNodes[0].getSolution().getZ();
  int minPos = 0;
  while (!activeNodes.empty()) {
    for (int i = 0; i < activeNodes.size(); i++) {
      if (activeNodes[i].getSolution().getZ() < min) {
        min = activeNodes[i].getSolution().getZ();
        minPos = i;
      }
      actualNode = activeNodes[minPos];
      std::cout << "MIN" << minPos;
    }
    while (actualNode.getDepth() < solutionSizeM) {
      std::vector<Node<Solution>> nodes = generateLeaf(problem, initialSolution, actualNode.getDepth(), solutionSizeM);
      std::vector<Node<Solution>>::iterator activeNodesIt = std::find(activeNodes.begin(), activeNodes.end(), actualNode);
      activeNodes.erase(activeNodesIt);
      for (int i = 0; i < nodes.size(); i++) {
        activeNodes.push_back(nodes[i]);
      }
      // Best of the leafs
      for (int i = 0; i < activeNodes.size(); i++) {
        if (activeNodes[i].getSolution().getZ() < min) {
          min = activeNodes[i].getSolution().getZ();
          minPos = i;
        }
        actualNode = activeNodes[minPos];
      }
    }
    // Calculate z
    double actualNodeZ = actualNode.getSolution().getZ();
    if (actualNodeZ > lowerBound) {
      lowerBound = actualNodeZ;
    }
    for (int i = 0; i < activeNodes.size(); i++) {
      if (activeNodes[i].getSolution().getZ() <= lowerBound) {
        std::vector<Node<Solution>>::iterator activeNodesIt = std::find(activeNodes.begin(), activeNodes.end(), activeNodes[i]);
        activeNodes.erase(activeNodesIt);
      }
      actualNode.setDepth(actualNode.getDepth() + 1);
    }*/
  }

  return initialSolution;
}


std::vector<Node<Solution>> BranchAndBound::generateLeaf(Problem problem, Solution parent, int depth, int solutionSizeM) {
  std::vector<Node<Solution>> children;
  Solution selectedElement;


  // Add to the possible solution the correspondant elements of the parent because of the current
  // depth
  for (int i = 0; i < depth; i++) {
    selectedElement.addElementToSolution(parent[i]);
  }


  // Delete every element of the generated solution that are inside the initial set of elements
  std::vector<Element> initialX = problem.getInitialX();
  for (int i = 0; i < selectedElement.size(); i++) {
    std::vector<Element>::iterator initialXIterator = std::find(initialX.begin(), initialX.end(), selectedElement.getSolution()[i]);
    initialX.erase(initialXIterator);
  }

  
  // Set a coordinate axis
  selectedElement.resize(depth + 1);
  for (int i = 0; i < initialX.size(); i++) {
    selectedElement[depth] = initialX[i];
    std::vector<Element> initialWithoutSelected = initialX;
    initialWithoutSelected.erase(initialWithoutSelected.begin() + i);
    Node<Solution> newLeaf(generateBestSolution(initialWithoutSelected, selectedElement, solutionSizeM), depth + 1);
    children.push_back(newLeaf);
  }

  return children;
}


/**
 * Generates each possible solution with the remaining coordinates for then to only
 * choose the solution that has the best objective function value (The lesser value one)
 **/
Solution BranchAndBound::generateBestSolution(std::vector<Element> initialX, Solution selectedElement, int solutionSizeM) {
  std::pair<Element, double> bestCandidate; // Each position corresponds to the element and its z value
  bestCandidate.second = 0.0;
  Solution auxSolution;
  double candidate;

  while (selectedElement.size() < solutionSizeM) {
    for (int i = 0; i < initialX.size(); i++) {
      auxSolution = selectedElement;
      auxSolution.addElementToSolution(initialX[i]);
      candidate = auxSolution.calculateObjectiveFunction();
      if (candidate > bestCandidate.second) {
        bestCandidate.first = initialX[i];
        bestCandidate.second = candidate;
      }
    }
    selectedElement.addElementToSolution(bestCandidate.first);
  }
  selectedElement.calculateObjectiveFunction();
  return selectedElement;
}