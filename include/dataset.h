#ifndef DATASET_H
#define DATASET_H

#include <vector>

/* Function to generate XOR dataset */
void generateXORData(unsigned& a, unsigned& b, std::vector<double>& inputVals, std::vector<double>& targetVals);

/* Function to generate a complex dataset with 10 inputs and 1 binary output */
void generateComplexData(std::vector<double>& inputVals, std::vector<double>& targetVals);

/* Function to generate a fixed training dataset */
void generateTrainingSet(std::vector<std::vector<double>>& trainingInputs, std::vector<std::vector<double>>& trainingTargets, unsigned size);

/* Function to generate a fixed test dataset */
void generateTestSet(std::vector<std::vector<double>>& testInputs, std::vector<std::vector<double>>& testTargets, unsigned size);

#endif // DATASET_H