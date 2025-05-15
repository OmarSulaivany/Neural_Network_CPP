#include "dataset.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding rand()

/* Function to generate XOR dataset */
void generateXORData(unsigned& a, unsigned& b, std::vector<double>& inputVals, std::vector<double>& targetVals) {
    // XOR dataset logic (already implemented)
}

/* Function to generate a complex dataset with 10 inputs and 1 binary output */
void generateComplexData(std::vector<double>& inputVals, std::vector<double>& targetVals) {
    // Generate 10 random inputs between 0 and 1
    inputVals.clear();
    targetVals.clear();

    for (int i = 0; i < 10; ++i) {
        inputVals.push_back(static_cast<double>(rand()) / RAND_MAX); // Random value between 0 and 1
    }

    // Define a rule for the output: sum of inputs > 5 -> output = 1, else output = 0
    double sum = 0.0;
    for (double val : inputVals) {
        sum += val;
    }

    // Assign the target output based on the rule
    if (sum > 5.0) {
        targetVals.push_back(1.0); // Output is 1
    } else {
        targetVals.push_back(0.0); // Output is 0
    }
}

/* Function to generate a fixed training dataset */
void generateTrainingSet(std::vector<std::vector<double>>& trainingInputs, std::vector<std::vector<double>>& trainingTargets, unsigned size) {
    // Seed the random number generator with a fixed seed for reproducibility
    srand(42); // Fixed seed for training set.

    trainingInputs.clear();
    trainingTargets.clear();

    for (unsigned i = 0; i < size; ++i) {
        std::vector<double> inputVals;
        std::vector<double> targetVals;
        generateComplexData(inputVals, targetVals);

        trainingInputs.push_back(inputVals);
        trainingTargets.push_back(targetVals);
    }
}

/* Function to generate a fixed test dataset */
void generateTestSet(std::vector<std::vector<double>>& testInputs, std::vector<std::vector<double>>& testTargets, unsigned size) {
    // Use a different fixed seed for the test set to ensure no overlap with the training set
    srand(84); // Fixed seed for test set

    testInputs.clear();
    testTargets.clear();

    for (unsigned i = 0; i < size; ++i) {
        std::vector<double> inputVals;
        std::vector<double> targetVals;
        generateComplexData(inputVals, targetVals);

        testInputs.push_back(inputVals);
        testTargets.push_back(targetVals);
    }
}