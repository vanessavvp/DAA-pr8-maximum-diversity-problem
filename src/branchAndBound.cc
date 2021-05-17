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


int BranchAndBound::getAmountOfNodes() {
  return amountOfNodes_;
}


/*
bool sortByObjectiveFunction(std::pair<int, Solution> &a, std::pair<int, Solution> &b) {
  return (a.second.evaluateObjectiveFunction() > b.second.evaluateObjectiveFunction());
}

bool sortByDepth(std::pair<int, Solution> &a, std::pair<int, Solution> &b) {
  return (a.first < b.first);
}
.
.
void BranchAndBound::sortByStrategy(std::vector<std::pair<int, Solution>>& activeNodes_) {
  // strategy 1 = node with smallest objective function value
  if (strategy_ == 1) {
    std::sort(activeNodes_.begin(), activeNodes_.end(), sortByObjectiveFunction);
  //strategy 2 = deepest node
  } else if (strategy_ == 2) {
    std::sort(activeNodes_.begin(), activeNodes_.end(), sortByDepth);
  }
}*/

Solution BranchAndBound::execute(Problem problem, int solutionSizeM) {
  // Generate the initial lower bound from Greedy or GRASP algorithms settled before
  Solution initialSolution = otherAlgorithm_->execute(problem, solutionSizeM);
  Node<Solution> node(initialSolution, 0);
  activeNodes_.push_back(node);
  float lowerBound = initialSolution.getZ();
  amountOfNodes_ = 1;

  // Create a set of active nodes to be expanded
  // DEPTH = 0, because is the first iteration and none of the coordinates are permanent
  Node<Solution> actualNode = activeNodes_[0];
  double min = actualNode.getSolution().getZ();
  int minPos = 0;
  while (activeNodes_.size() > 0) {
    for (int i = 0; i < activeNodes_.size(); i++) {
      if (activeNodes_[i].getSolution().getZ() < min) {
        min = activeNodes_[i].getSolution().getZ();
        minPos = i;
      }
      actualNode = activeNodes_[minPos];
    }
    while (actualNode.getDepth() < solutionSizeM) {
      std::vector<Node<Solution>> nodes = generateLeaf(problem, initialSolution, actualNode.getDepth(), solutionSizeM);
      std::vector<Node<Solution>>::iterator activeNodes_It = std::find(activeNodes_.begin(), activeNodes_.end(), actualNode);
      activeNodes_.erase(activeNodes_It);
      for (int i = 0; i < nodes.size(); i++) {
        activeNodes_.push_back(nodes[i]);
      }
      amountOfNodes_ += activeNodes_.size();
      //Best of the leafs
      for (int i = 0; i < activeNodes_.size(); i++) {
        if (activeNodes_[i].getSolution().getZ() < min) {
          min = activeNodes_[i].getSolution().getZ();
          minPos = i;
        }
        actualNode = activeNodes_[minPos];
      }
    }
    // Calculate z
    double actualNodeZ = actualNode.getSolution().getZ();
    if (actualNodeZ > lowerBound) {
      lowerBound = actualNodeZ;
    }
    int i = 0;
    while (i < activeNodes_.size()) {
      if (activeNodes_[i].getSolution().getZ() <= lowerBound) {
        //std::cout << "Z " << activeNodes_[i].getSolution().getZ() << " LOWER " << lowerBound << std::endl;
        std::vector<Node<Solution>>::iterator activeNodes_It = activeNodes_.begin(); // + i;//std::find(activeNodes_.begin(), activeNodes_.end(), activeNodes_[i]);
        activeNodes_.erase(activeNodes_It);
        i--;
      }
      i++;
    }
  }
  //actualNode.getSolution().print();
  return actualNode.getSolution();
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