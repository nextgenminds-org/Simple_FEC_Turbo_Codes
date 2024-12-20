#include "include/TurboCodec.h"
#include <iostream>

// Main function: Entry point for the Turbo Encoder/Decoder application.
int main() {
    TurboCodec codec; // Instantiate the TurboCodec class for encoding/decoding operations.
    std::string input, encodedOutput, decodedOutput; // Strings to hold the input, encoded, and decoded messages.
    char option; // Variable to store user menu option.
    double noiseVariance = 0.5; // Initial noise variance value, representing the noise level in the channel.
    int maxIterations = 20; // Default maximum number of decoding iterations.
    double convergenceThreshold = 0.001; // Default threshold for detecting convergence in decoding.

    // Display the application header.
    std::cout << "Turbo Encoder/Decoder\n";

    // Infinite loop to display the menu and process user inputs.
    while (true) {
        // Display the menu options to the user.
        std::cout << "1. Encode\n2. Decode\n3. Set Noise Variance (current: " << noiseVariance << ")\n";
        std::cout << "4. Set Max Iterations (current: " << maxIterations << ")\n";
        std::cout << "5. Set Convergence Threshold (current: " << convergenceThreshold << ")\n";
        std::cout << "Select an option: ";

        // Read the user's menu option.
        std::cin >> option;
        std::cin.ignore(); // Ignore the newline character left in the input buffer.

        if (option == '1') {
            // Encoding process
            std::cout << "Enter the message to encode: ";
            std::getline(std::cin, input); // Read the input message to encode.
            codec.encode(input, encodedOutput); // Perform encoding using the TurboCodec class.
            std::cout << "Encoded message: " << encodedOutput << "\n"; // Display the encoded message.
        } else if (option == '2') {
            // Decoding process
            std::cout << "Enter the encoded message: ";
            std::getline(std::cin, encodedOutput); // Read the encoded message from the user.

            char decodeOption; // Variable to store the decoding algorithm choice.
            std::cout << "Choose decoding algorithm:\n";
            std::cout << "1. BCJR\n";
            std::cout << "2. MAP\n";
            std::cout << "3. SOVA\n";
            std::cout << "4. HYBRID (MAP + SOVA)\n";
            std::cout << "Select an option: ";
            std::cin >> decodeOption;
            std::cin.ignore(); // Ignore the newline character left in the input buffer.

            // Select the decoding algorithm based on user input.
            if (decodeOption == '1') {
                codec.decode(encodedOutput, decodedOutput, noiseVariance, "BCJR");
                std::cout << "Decoded message (using BCJR): " << decodedOutput << "\n";
            } else if (decodeOption == '2') {
                codec.decode(encodedOutput, decodedOutput, noiseVariance, "MAP");
                std::cout << "Decoded message (using MAP): " << decodedOutput << "\n";
            } else if (decodeOption == '3') {
                codec.decode(encodedOutput, decodedOutput, noiseVariance, "SOVA");
                std::cout << "Decoded message (using SOVA): " << decodedOutput << "\n";
            } else if (decodeOption == '4') {
                codec.decode(encodedOutput, decodedOutput, noiseVariance, "HYBRID");
                std::cout << "Decoded message (using HYBRID): " << decodedOutput << "\n";
            } else {
                std::cout << "Invalid decoding algorithm option.\n"; // Handle invalid inputs for decoding algorithm.
            }
        } else if (option == '3') {
            // Set noise variance
            std::cout << "Enter new noise variance: ";
            std::cin >> noiseVariance; // Read the new noise variance value.
            std::cin.ignore(); // Ignore the newline character.
            std::cout << "Noise variance updated to " << noiseVariance << "\n"; // Confirm the change.
        } else if (option == '4') {
            // Set max iterations
            std::cout << "Enter new max iterations: ";
            std::cin >> maxIterations; // Read the new maximum iteration count.
            std::cin.ignore(); // Ignore the newline character.
            std::cout << "Max iterations updated to " << maxIterations << "\n"; // Confirm the change.
        } else if (option == '5') {
            // Set convergence threshold
            std::cout << "Enter new convergence threshold: ";
            std::cin >> convergenceThreshold; // Read the new convergence threshold value.
            std::cin.ignore(); // Ignore the newline character.
            std::cout << "Convergence threshold updated to " << convergenceThreshold << "\n"; // Confirm the change.
        } else {
            std::cout << "Invalid option.\n"; // Handle invalid menu options.
        }
    }

    return 0; // End of the program.
}
