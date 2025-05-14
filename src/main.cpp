/* Neural Network Implementation in C++.
Author: Omar T. Mohammed
Date: 18-Jan-2021 */

#include <vector>
#include "../include/Net.h"
#include "../include/dataset.h"
#include <iostream>
#include <cmath> // For calculating loss
using namespace std;

/* Function to train the network */
void trainComplexNetwork(Net& myNet, const vector<vector<double>>& trainingInputs, const vector<vector<double>>& trainingTargets, unsigned totalEpochs) {
    vector<double> resultVals;

    /***************************Training Phase**************************************/
    for (unsigned epoch = 0; epoch < totalEpochs; ++epoch) {
        double totalLoss = 0.0; // Accumulator for loss over the training dataset

        /* Loop through the training dataset */
        for (unsigned i = 0; i < trainingInputs.size(); ++i) {
            /* Get the current training example */
            const vector<double>& inputVals = trainingInputs[i];
            const vector<double>& targetVals = trainingTargets[i];

            /* Do feedForward. */
            myNet.feedForward(inputVals);

            /* Do Back backProbagation. */
            myNet.backProbagation(targetVals);

            /* Store the results in resultVals. */
            myNet.getResults(resultVals);

            /* Calculate loss (Mean Squared Error) for this example */
            totalLoss += pow(resultVals[0] - targetVals[0], 2);
        }

        /* Output the average loss for this epoch (optional, can be limited for clarity). */
        if ((epoch + 1) % 1000 == 0) { // Print every 1,000 epochs
            double averageLoss = totalLoss / trainingInputs.size();
            cout << "Epoch " << epoch + 1 << ": Average Loss = " << averageLoss << endl;
        }
    }
}

/* Function to test the network */
void testComplexNetwork(Net& myNet, const vector<vector<double>>& testInputs, const vector<vector<double>>& testTargets) {
    unsigned correctPredictions = 0;
    double totalLoss = 0.0;

    /***************************Testing Phase**************************************/
    for (unsigned i = 0; i < testInputs.size(); ++i) {
        /* Get the current test example */
        const vector<double>& inputVals = testInputs[i];
        const vector<double>& targetVals = testTargets[i];

        /* Do feedForward to get predictions */
        vector<double> resultVals;
        myNet.feedForward(inputVals);
        myNet.getResults(resultVals);

        /* Calculate accuracy */
        if (resultVals[0] >= 0.5 && targetVals[0] == 1.0) {
            correctPredictions++;
        } else if (resultVals[0] < 0.5 && targetVals[0] == 0.0) {
            correctPredictions++;
        }

        /* Calculate loss (Mean Squared Error) */
        totalLoss += pow(resultVals[0] - targetVals[0], 2);
    }

    /* Calculate and output final accuracy and loss */
    double accuracy = (static_cast<double>(correctPredictions) / testInputs.size()) * 100.0;
    double averageLoss = totalLoss / testInputs.size();

    cout << "\nTesting Results:" << endl;
    cout << "Accuracy: " << accuracy << "%" << endl;
    cout << "Average Loss: " << averageLoss << endl;
}

/* Function to check if there is any overlap between the training and test datasets */
bool hasOverlap(const vector<vector<double>>& trainingInputs, const vector<vector<double>>& testInputs) {
    for (const auto& trainInput : trainingInputs) {
        for (const auto& testInput : testInputs) {
            if (trainInput == testInput) {
                return true; // Overlap found
            }
        }
    }
    return false; // No overlap
}

int main() {
    /* Create a vector of topology, which specifies number of layers and neurons in the Neural network. */
    vector<unsigned> topology = {10, 32, 8, 1};

    /* Initialize a Network with the above specifications */
    Net myNet(topology);

    // Training and test datasets
    vector<vector<double>> trainingInputs, trainingTargets;
    vector<vector<double>> testInputs, testTargets;

    /* Generate training and test datasets */
    generateTrainingSet(trainingInputs, trainingTargets, 1000); // 1000 training examples
    generateTestSet(testInputs, testTargets, 100);             // 100 test examples

    /* Check for overlap between training and test datasets */
    if (hasOverlap(trainingInputs, testInputs)) {
        cout << "Warning: Overlap detected between training and test datasets!" << endl;
    } else {
        cout << "No overlap detected between training and test datasets. Proceeding with training..." << endl;
    }

    /* Train the network */
    cout << "Starting Training Phase..." << endl;
    trainComplexNetwork(myNet, trainingInputs, trainingTargets, 12000); // Train for N epochs

    /* Test the network */
    cout << "\nStarting Testing Phase..." << endl;
    testComplexNetwork(myNet, testInputs, testTargets);

    return 0;
}
