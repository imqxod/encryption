#include <iostream>
#include <cmath>
#include <string>
#include <chrono>

std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY1234567890!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

std::string encrypt(const std::string& input) {
    double key = std::atan2(std::sqrt(std::log(input.length())), std::sin(input.length()));
    std::string encryptedString = "";

    for (char letter : input) {
        size_t position = alphabet.find(letter);
        if (position != std::string::npos) {
            int xorValue = static_cast<int>(key);
            size_t encryptedPosition = (position ^ xorValue) % alphabet.length();
            encryptedString += alphabet[encryptedPosition];
        } else {
            encryptedString += letter;
        }
    }

    encryptedString += "^^" + std::to_string(std::atan2(std::sqrt(std::log(encryptedString.length())), std::sin(encryptedString.length()))) + "^^";
    return encryptedString;
}

std::string decrypt(const std::string& encryptedString) {
    double key = std::atan2(std::sqrt(std::log(encryptedString.length())), std::sin(encryptedString.length()));
    std::string decryptedString = "";

    std::string input = encryptedString.substr(0, encryptedString.find("^^"));
    for (char letter : input) {
        size_t position = alphabet.find(letter);
        if (position != std::string::npos) {
            int xorValue = static_cast<int>(key);
            size_t decryptedPosition = (position ^ xorValue) % alphabet.length();
            decryptedString += alphabet[decryptedPosition];
        } else {
            decryptedString += letter;
        }
    }

    return decryptedString;
}

int main() {
    std::string message = "Hello, World!";
    
    auto start = std::chrono::high_resolution_clock::now();
    std::string encryptedMessage = encrypt(message);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    std::chrono::duration<double> encryptDuration = std::chrono::duration_cast<std::chrono::duration<double>>(elapsed);
    std::cout << "Encrypted message: " << encryptedMessage << std::endl;
    std::cout << "Took " << encryptDuration.count() * 1000 << " ms to encrypt" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::string decryptedMessage = decrypt(encryptedMessage);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    std::chrono::duration<double> decryptDuration = std::chrono::duration_cast<std::chrono::duration<double>>(elapsed);
    std::cout << "Decrypted message: " << decryptedMessage << std::endl;
    std::cout << "Took " << decryptDuration.count() * 1000 << " ms to decrypt" << std::endl;

    return 0;
}
