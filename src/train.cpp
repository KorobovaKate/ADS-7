// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car *newCar = new Car{light, nullptr, nullptr};
    if (!first)
    {
        first = newCar;
        first->next = first;
        first->pred = first;
    } else {
        Car *last = first->pred;
        last->next = newCar;
        newCar->pred = last;
        newCar->next = first;
        first->pred = newCar;
    }
}

int Train::getLength()
{
  if (!first) return 0;
  int countOp = 0;
  Car *curr = first;
  
  if (!curr->light)
  {
    curr->light = true;
  }

  int steps = 0;
  
  while (true) {
    for (int i = 0; i < steps; i++) {
      curr = curr->next;
      countOp++;
    }
    if (curr->light) {
      curr->light = false;
      countOp++;

      for (int i = 0; i < steps; i++) {
        curr = curr->pred;
        countOp++;
      }

      if (!curr->light) {
        return steps;
      }
      steps = 0;
    }
    steps++;
  }
}

int Train::getOpCount() {
    return countOp;
}
