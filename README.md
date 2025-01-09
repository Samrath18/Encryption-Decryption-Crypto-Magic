# 2023/11/06

# Encryption-Decryption-Crypto-Magic

This C program encrypts or decrypts text files based on command-line arguments. The encryption transforms text by modifying characters and converting them to hexadecimal, while the decryption reverses this process.

Features:
Encryption: Transforms characters with a specific offset and outputs in hexadecimal.
Decryption: Reverses the transformation, converting hex values back to original characters.

Tab and Newline Handling: Replaces tabs with "TT" during encryption and restores them during decryption.
File Input/Output: Processes an input text file and outputs the result to a specified file.

Usage:
cryptoMagic -E input_file: Encrypts the input file.
cryptoMagic -D input_file: Decrypts the input file.

Output:
The program outputs either encrypted.crp or decrypted.txt based on the mode.
