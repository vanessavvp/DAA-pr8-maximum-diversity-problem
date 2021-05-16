/**
 * PROJECT HEADER
 * @file nodet.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 16/05/2021
 * Subject: Diseño y Análisis de Algoritmos
 * Practice: Numberº8
 * Purpose: Maximum Diversity Problem
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>

#include "./solution.h"

#pragma once

template <typename TYPE>
class Node {
  public:
    Node() {};
    Node(Solution solution, int depth = 0) {
      depth_ = depth;
      solution_ = solution;
    }
    int getDepth() const {
      return depth_;
    }
    void setDepth(int depth) {
      depth_ = depth;
    }
    Solution getSolution() const {
      return solution_;
    }
    bool operator ==(const Node<TYPE>& a) {
      if ((a.getSolution() == solution_) && (a.getDepth() == depth_)) {
        return true;
      }
      return false;
    }
  private:
    int depth_;
    Solution solution_;
};

#endif // !NODE_H