#include <stdio.h>
#include <string.h>

void encrypt(char *line, char *output); // Function declaration for the encrypt function
void decrypt(char *line, char *output); // Function declaration for the decrypt function

int main(int argc, char *argv[]) { // Main function
    if (argc < 3) { // Check if the number of command line arguments is less than 3
        printf("Usage: cryptoMagic [-E|-D] input_file\n"); // Print a usage message for the user
        return 1;
    }
    char *inputFileName = argv[2]; // Get the input file name from command line arguments.
    char *outputFileName; // Declare a variable to store the output file name.
    int encryptMode = 1; // 1 for encrypt, 0 for decrypt

    if (argc == 3) { // Check if there are exactly 3 command line arguments.
        if (strcmp(argv[1], "-D") == 0) { // Check if the second argument is "-D" (decrypt mode).
            encryptMode = 0; // Set decrypt mode.
            outputFileName = "decrypted.txt"; // Set the output file name to "decrypted.txt".
        }
        else {
            encryptMode = 1; // Set encrypt mode (default).
            outputFileName = "encrypted.crp"; // Set the output file name to "encrypted.crp".
        }
    }
    else {
        printf("Invalid Entry.\n"); // Print an error message for invalid input.
        return 1;
    }
    FILE *inputFile = fopen(inputFileName, "r"); // Open the input file for reading.
    FILE *outputFile = fopen(outputFileName, "w"); // Open the output file for writing.

    if (inputFile == NULL || outputFile == NULL) { // Check if file opening was successful.
        printf("Error: Unable to open files.\n");
        return 1;
    }
    char line[256]; // Declare a character array to store a line from the input file.
    char processedLine[512]; // Declare a character array to store the processed line.

    while (fgets(line, sizeof(line), inputFile)) { // Read lines from the input file.
        printf("Original Line: %s\n", line); // Debugging output.

        if (encryptMode) { // Check if in encryption mode.
            encrypt(line, processedLine); // Call the encrypt function.
        }
        else {
            decrypt(line, processedLine); // Call the decrypt function.
        }
        printf("Processed Line: %s\n\n", processedLine); // Debugging output.
        fprintf(outputFile, "%s", processedLine); // Write the processed line to the output file.
    }
    fclose(inputFile); // Close the input file.
    fclose(outputFile); // Close the output file.

    printf("%s complete.\n", encryptMode ? "Encryption" : "Decryption"); // Print a completion message depnding on which mode was prior selected.
    return 0; // Return 0 to indicate successful execution.
}

void encrypt(char *line, char *output) { // Encryption function.
    char encryptedLine[512]; // Declare a character array to store the encrypted line.
    int j = 0; // Initialize a variable for the index of the encrypted line.

    for (int i = 0; line[i] != '\0' && j < sizeof(encryptedLine) - 2; i++) { // Loop through the input line.
        if (line[i] == '\t') { // Check if the current character is a tab.
            encryptedLine[j++] = 'T'; // Replace it with 'T'.
            encryptedLine[j++] = 'T'; // Append another 'T'.
        }
        else if (line[i] != '\n') { // Check if the current character is not a newline.
            int outChar = line[i] - 16; // Perform some character transformation.
            if (outChar < 32) { // Check if the result is less than 32.
                outChar = (outChar - 32) + 144; // Further transformation.
            }
            sprintf(encryptedLine + j, "%02X", outChar); // Format and store the result in hexadecimal.
            j += 2; // Move the index by 2.
        }
        if (line[i + 1] == '\0' && line[i] != '\n') { // Check for the end of the line.
            encryptedLine[j++] = '\n'; // Add a newline character.
        }
    }
    encryptedLine[j] = '\0'; // Null-terminate the encrypted line.
    strcpy(output, encryptedLine); // Copy the encrypted line to the output.
}

void decrypt(char *line, char *output) { // Decryption function.
    char decryptedLine[512]; // Declare a character array to store the decrypted line.
    int j = 0; // Initialize a variable for the index of the decrypted line.

    for (int i = 0; line[i] != '\0' && j < sizeof(decryptedLine) - 1; i += 2) { // Loop through the input line in pairs of characters.
        if (line[i] == 'T' && line[i + 1] == 'T') { // Check for 'TT' which represents a tab.
            decryptedLine[j++] = '\t'; // Replace it with a tab character.
        }
        else if (line[i] == '\n' && line[i + 1] == '\0') { // Check for a single newline character.
            decryptedLine[j++] = '\n'; // Add a newline character.
        }
        else {
            int outChar;
            sscanf(line + i, "%02X", &outChar); // Read a hexadecimal value from the input.
            outChar = outChar + 16; // Reverse the character transformation.
            if (outChar > 127) { // Check if the result is greater than 127.
                outChar = (outChar - 144) + 32; // Reverse the further transformation.
            }
            decryptedLine[j++] = outChar; // Store the result in the decrypted line.
        }
    }
    decryptedLine[j] = '\0'; // Null-terminate the decrypted line.
    strcpy(output, decryptedLine); // Copy the decrypted line to the output.
}