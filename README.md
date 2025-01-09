# 2023/11/06

# Encryption-Decryption-Crypto-Magic

INPUT:
The CryptoMagic program accepts command-line arguments to specify its operation and the input file for encryption
or decryption.

Command-Line Arguments:

    -E: This flag specifies that you want to encrypt a file. When using this flag, CryptoMagic will read the
    specified input file, perform encryption, and save the encrypted data to an output file.
    
    -D: This flag specifies that you want to decrypt a file. When using this flag, CryptoMagic will read the
    specified input file (which should be the encrypted data), perform decryption, and save the decrypted data to
    an output file.

Input File (input_file):

    This is the path to the file you want to encrypt or decrypt. You should provide the filename or the path to the
    file you want to process. CryptoMagic will read the contents of this file and apply the appropriate operation
    (encryption or decryption) based on the command-line arguments.

OUTPUT:
The output of the CryptoMagic program depends on whether you are encrypting or decrypting a file.

For Encryption:

    If you use the -E flag to encrypt a file, the program will create an output file that contains the encrypted
    data.

    By default, the output file is named encrypted.crp.
    You can specify a different output file name by providing it as a command-line argument. For example:

        cryptoMagic -E mydata.txt -o my_encrypted_data.crp

    This command will save the encrypted data to a file named my_encrypted_data.crp.

For Decryption:

    If you use the -D flag to decrypt a file, the program will create an output file that contains the decrypted
    data.
    
    By default, the output file is named decrypted.txt.
    
    You can also specify a different output file name by providing it as a command-line argument, similar to the
    encryption operation.

In summary, the input to CryptoMagic consists of the command-line arguments specifying the operation and the input
file. The output is the result of the specified operation (either encrypted or decrypted data), which is saved in
an output file. The default output file names are encrypted.crp for encryption and decrypted.txt for decryption,
but you can customize these output file names if needed.
