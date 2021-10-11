// Copyright 2021 wm8

#include "Investigation.h"
Investigation::Investigation(ExperimentType t, std::vector<int64_t>& sizes) {
  Investigation::type = t;
  int id = 0;
  for (int64_t i=log2(sizes[0]/2); pow(2, i) < 3*sizes[sizes.size()-1]/2; i++)
  {
    id++;
    Experiment* e =new Experiment(id, type, pow(2, i));
    e->run();
    experiments.push_back(e);
  }
}
void Investigation::print(std::ostream& os) {
  os<< "investigation\n\ttravel_variant: " << to_string(type) << std::endl;
  for ( Experiment* experiment : experiments)
  {
    os << "\texperiment:\n";
    experiment->print(os);
  }
}
