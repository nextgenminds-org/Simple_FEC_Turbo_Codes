# TurboCodec: An Educational Implementation of FEC Turbo Codes

This project is a simple implementation of Forward Error Correction (FEC) Turbo Codes. It was developed as part of the participation of the **NGM Team** (a group of children aged 13 to 16) in the **CanSat Greece 2024-2025 competition**. The primary goal is to introduce young learners to the principles of error correction coding while delivering a functional system that can be adapted for educational and competition purposes. 

TurboCodec is a software implementation of turbo codes, a class of forward error correction (FEC) codes renowned for their near-Shannon-limit performance. This program offers a robust platform for encoding and decoding data, featuring multiple decoding algorithms and customizable parameters to suit various applications.


---

## Features of TurboCodec

- **Turbo Encoding**:
  - Utilizes two recursive systematic convolutional (RSC) encoders.
  - Incorporates an interleaver to improve error resilience by rearranging data bits.

- **Turbo Decoding**:
  - Includes four decoding algorithms: **BCJR**, **MAP**, **SOVA**, and **Hybrid MAP-SOVA**.
  - Allows customization of decoding parameters such as:
    - Maximum iterations (`maxIterations`): Default is 20.
    - Convergence threshold (`convergenceThreshold`): Default is 0.001.
    - Noise variance (`noiseVariance`): Default is 0.5.

- **User Interaction**:
  - Interactive menu-driven interface to select encoding/decoding options.
  - Real-time parameter adjustment for noise variance, iterations, and convergence threshold.

---

## File Descriptions

- **TurboCodes.cpp**: Contains the main program logic, providing a user interface to encode and decode messages interactively.
- **TurboCodec.cpp**: Implements the encoding and decoding algorithms, including the logic for different decoding methods.
- **TurboCodec.h**: Header file with declarations for encoding/decoding and adjustable parameters.
- **README.md**: This document serves as a comprehensive guide to the project.
- **LICENSE**: Contains licensing information for the codebase.

---

## Turbo Encoding Process

Turbo encoding is the foundation of TurboCodec, providing robust error correction through parallel concatenation of encoders.

### Process
1. **Recursive Systematic Convolutional (RSC) Encoding**:
   - The original data is passed through two RSC encoders, producing a systematic output and two parity streams.

2. **Interleaving**:
   - An interleaver rearranges the input data bits, ensuring that correlated errors in the channel affect independent regions of the data.

3. **Output Formation**:
   - The systematic bits and the two parity streams are concatenated to form the encoded message.

### Advantages
- Near-Shannon-limit error correction performance.
- Enhanced resilience to burst errors due to interleaving.

### Disadvantages
- Increased complexity compared to simpler codes like Hamming codes.
- Interleaver design may impact performance in certain conditions.

---

## Turbo Decoding Algorithms

The decoding process involves iterative methods to refine the received data. TurboCodec supports the following decoding methods:

### 1. BCJR (MAP) Algorithm
- **Description**: Computes the a posteriori probabilities (APPs) of the transmitted bits using forward-backward recursion.
- **Advantages**:
  - Optimal decoding performance in terms of minimizing symbol error rates.
- **Disadvantages**:
  - High computational complexity due to logarithmic-domain operations.

### 2. MAP Algorithm
- **Description**: A simplification of BCJR, focused on maximizing the a posteriori probability for each bit.
- **Advantages**:
  - Provides high decoding accuracy.
- **Disadvantages**:
  - Computationally demanding compared to suboptimal methods like SOVA.

### 3. SOVA (Soft Output Viterbi Algorithm)
- **Description**: Extends the Viterbi algorithm by generating soft outputs for likelihood estimation.
- **Advantages**:
  - Computationally less intensive than BCJR or MAP.
  - Suitable for real-time systems.
- **Disadvantages**:
  - May underperform in decoding accuracy compared to MAP-based methods.

### 4. Hybrid MAP-SOVA
- **Description**: Combines MAP in early iterations for accuracy and SOVA in later iterations for efficiency.
- **Advantages**:
  - Balances decoding accuracy and computational efficiency.
- **Disadvantages**:
  - Implementation complexity increases due to algorithm switching.

---

## Default Parameters and Customization

### Default Values
- **`maxIterations = 20`**: Determines the maximum number of iterations for the decoding process.
- **`convergenceThreshold = 0.001`**: Defines the threshold for terminating iterations early if convergence is detected.
- **`noiseVariance = 0.5`**: Represents the variance of noise in the communication channel.

### Customization
These parameters can be adjusted dynamically via the user menu:
1. Select option `3` to change noise variance.
2. Select option `4` to update the maximum iterations.
3. Select option `5` to modify the convergence threshold.

---

## How to Use

1. **Compile the Program**:
   - Use a C++ compiler to build the program: `g++ TurboCodes.cpp TurboCodec.cpp -o TurboCodec`.
2. **Run the Program**:
   - Execute the compiled binary: `./TurboCodec`.
3. **Interact with the Menu**:
   - Choose options for encoding, decoding, or parameter adjustments.
4. **Analyze Outputs**:
   - View the encoded/decoded messages and iteration details.

---

## Applications

- **Satellite Communications**: Used in telemetry and data integrity for satellite systems.
- **Mobile Networks**: Enhances data reliability in 3G and LTE systems.
- **Space Missions**: Supports decoding in deep-space communication systems, e.g., NASA's Deep Space Network.
- **Educational Tools**: Provides hands-on learning for FEC techniques and algorithms.

---

## Strengths and Limitations

### Strengths
- Supports four decoding algorithms for flexibility.
- Customizable parameters for tailored performance.
- Demonstrates near-optimal error correction capabilities.

### Limitations
- High computational complexity for MAP-based methods.
- Decoding performance depends on accurate noise variance estimation.

---

## References

1. Bahl, L., Cocke, J., Jelinek, F., & Raviv, J. (1974). "Optimal Decoding of Linear Codes for Minimizing Symbol Error Rate". IEEE Transactions on Information Theory.
2. Hagenauer, J., & Hoeher, P. (1989). "A Viterbi Algorithm with Soft-Decision Outputs and its Applications". IEEE Globecom.
3. Berrou, C., Glavieux, A., & Thitimajshima, P. (1993). "Near Shannon Limit Error-Correcting Coding and Decoding: Turbo-Codes". IEEE International Conference on Communications.
4. Deep Space Network Documentation. NASA. [Link](https://deepspace.jpl.nasa.gov/dsndocs/810-005/208/208B.pdf)
5. Turbo Codes Overview. Wikipedia. [Link](https://en.wikipedia.org/wiki/Turbo_code)

---

## Contribution

This project was developed with educational purposes in mind. Contributions and feedback are welcome to improve its functionality and expand its use cases.

**NGM Team** - CanSat Greece 2024-2025
