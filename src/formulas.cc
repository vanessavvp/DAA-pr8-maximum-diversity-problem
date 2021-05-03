#include "../include/formulas.h"

double calculateEuclideanDistance(Element first, Element second) {
  double distance = 0;
  for (int i = 0; i < first.getDimensionK(); i++) {
    distance += (pow((first[i] - second[i]), 2));
  }
  distance = sqrt(distance);
  return distance;
}