# Encryption and Decryption Documentation

This document explains how the encryption and decryption functions work.

## Overview

The encryption and decryption mechanism uses a combination of a mathematical key and XOR operation to obscure the input string. The key is dynamically generated based on the length of the string. A custom alphabet is used to support a wide range of characters, including alphabets (both lowercase and uppercase), numbers, and special symbols.

### Encryption Process

1. **Key Generation:**
   - The key used for XOR encryption is derived using the mathematical expression:
     ```python
     key = math.atan2(math.sqrt(math.log(len(string))), math.sin(len(string)))
     ```
   - The key is based on the length of the input string. This ensures that the encryption is not static and changes with the size of the input.

2. **Character Processing:**
   - For each character in the string, its position in the `alphabet` is found.
   - The XOR operation is applied between the character's position and the key (converted to an integer).
   - The result is then taken modulo the length of the `alphabet` to ensure the position stays within bounds.
   - If the character is not part of the defined `alphabet`, it is added to the encrypted string without change.

3. **Final Encryption:**
   - The encrypted string is appended with two markers (`^^`) along with the computed key for the encrypted string's length:
     ```python
     encrypted_string += "^^" + str(math.atan2(math.sqrt(math.log(len(encrypted_string))), math.sin(len(encrypted_string)))) + "^^"
     ```
   - This additional information is used during the decryption process to retrieve the correct key for decryption.

### Decryption Process

1. **Key Extraction:**
   - The encrypted string includes the key embedded in the string after the `^^` markers.
   - The key for decryption is calculated in the same manner as the encryption key using the length of the encrypted string.
   
2. **Character Processing:**
   - For each character in the encrypted string (before the `^^` markers), the inverse XOR operation is applied using the same key as in the encryption.
   - If the character is part of the `alphabet`, the XOR operation is applied to retrieve the original position, and the character is decrypted.
   - If the character is not part of the `alphabet`, it remains unchanged.

3. **Final Decryption:**
   - The decrypted string is returned after removing the `^^` markers and the appended key information.

### Alphabet

The alphabet used for the encryption and decryption process includes:
```plaintext
abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYXY1234567890!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
