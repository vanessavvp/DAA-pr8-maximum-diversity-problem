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


BranchAndBound::BranchAndBound(Algorithm* initialSolutionAlgorithm) {
  otherAlgorithm_ = initialSolutionAlgorithm;
  amountOfNodes_ = 1;
  option_ = 0;
}


void BranchAndBound::setAlgorithm(Algorithm* initialSolutionAlgorithm) {
  otherAlgorithm_ = initialSolutionAlgorithm;
}


void BranchAndBound::setOption(int option) {
  option_ = option;
}


int BranchAndBound::getAmountOfNodes() {
  return amountOfNodes_;
}


bool sortByZ(const Node<Solution>& a, const Node<Solution>& b) {
  return (a.getSolution().getZ() < b.getSolution().getZ());
}


bool sortByDepth(const Node<Solution>& a, const Node<Solution>& b) {
  return (a.getDepth() < b.getDepth());
}


std::vector<Node<Solution>> BranchAndBound::sortByOption(std::vector<Node<Solution>>& activeNodes) {
  if (option_ == 0) { // SmallestZ
    std::sort(activeNodes.begin(), activeNodes.end(), sortByZ);
  } else if (option_ == 1) { // Deeper
    std::sort(activeNodes.begin(), activeNodes.end(), sortByDepth);
  }
  return activeNodes;
}


Solution BranchAndBound::execute(Problem problem, int solutionSizeM) {
  // Generate the initial lower bound from Greedy or GRASP algorithms settled before
  Solution lowerBound = otherAlgorithm_->execute(problem, solutionSizeM);
  Node<Solution> node(lowerBound, 0);
  // Create a set of active nodes to be expanded
  activeNodes_.push_back(node);
  amountOfNodes_ = 1;
  Node<Solution> actualNode = activeNodes_[0];

  // Active nodes to be verified by its upper bound and that could be expanded
  while (activeNodes_.size() > 0) {
    sortByOption(activeNodes_);
    actualNode = activeNodes_[activeNodes_.size() - 1];

    // The actual node can continue to expand
    while (actualNode.getDepth() < solutionSizeM) {
      std::vector<Node<Solution>> nodes = generateLeaf(problem, lowerBound, actualNode.getDepth(), solutionSizeM);
      std::vector<Node<Solution>>::iterator activeNodes_It = std::find(activeNodes_.begin(), activeNodes_.end(), actualNode);
      activeNodes_.erase(activeNodes_It);
      sortByOption(nodes);
      for (int i = 0; i < nodes.size(); i++) {
        activeNodes_.push_back(nodes[i]);
        amountOfNodes_ += 1;
      }

      //Best of the leafs
      actualNode = activeNodes_[activeNodes_.size() - 1];
    }
    // Calculate z
    double actualNodeZ = actualNode.getSolution().getZ();
    if (actualNodeZ > lowerBound.getZ()) {
      lowerBound = actualNode.getSolution();
    }
    for (int i = 0; i < activeNodes_.size(); i++) {
      if (activeNodes_[i].getSolution().getZ() <= lowerBound.getZ()) {
        std::vector<Node<Solution>>::iterator activeNodes_It = std::find(activeNodes_.begin(), activeNodes_.end(), activeNodes_[i]);
        activeNodes_.erase(activeNodes_It);
        i--;
      }
    }
  }
  return lowerBound;
}

/**
 * Generates every leaf/children of a parent node, advancing through each of its  branches and, depending on the depth, setting
 * elements to obtain all possible combinations
 **/
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