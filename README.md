# Neural_Network_C++
Artificial Neural Network in C++.

## Overview
This project implements a simple feedforward artificial neural network (ANN) in C++. The network is capable of solving:
1. The **2-bit XOR problem**, a classic non-linear classification problem.
2. A **complex dataset** with 10 inputs and a binary output (0 or 1), where the output is determined by a rule based on the sum of the inputs.

---

## Complex Dataset
The complex dataset consists of:
- **10 random inputs**: Each input is a random value between 0 and 1.
- **1 binary output**: The output is `1` if the sum of the 10 inputs is greater than 5, otherwise `0`.

This dataset simulates a real-world classification problem where the output depends on a combination of multiple input features.

---

## Build Instructions
1. Navigate to the `Release` directory:
   ```bash
      cd Release
      cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo ../
      make
      ./Neural_Network_CPP
```