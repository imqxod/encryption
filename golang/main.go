package main

import (
	"fmt"
	"math"
	"strings"
	"time"
)

var alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY1234567890!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

func encrypt(input string) string {
	key := math.Atan2(math.Sqrt(math.Log(float64(len(input)))), math.Sin(float64(len(input))))
	encryptedString := ""

	for _, letter := range input {
		position := strings.IndexRune(alphabet, letter)
		if position != -1 {
			xorValue := int(key)
			encryptedPosition := (position ^ xorValue) % len(alphabet)
			encryptedString += string(alphabet[encryptedPosition])
		} else {
			encryptedString += string(letter)
		}
	}

	encryptedString += "^^" + fmt.Sprintf("%f", math.Atan2(math.Sqrt(math.Log(float64(len(encryptedString)))), math.Sin(float64(len(encryptedString))))) + "^^"
	return encryptedString
}

func decrypt(encryptedString string) string {
	key := math.Atan2(math.Sqrt(math.Log(float64(len(encryptedString)))), math.Sin(float64(len(encryptedString))))
	decryptedString := ""

	input := encryptedString[:strings.Index(encryptedString, "^^")]
	for _, letter := range input {
		position := strings.IndexRune(alphabet, letter)
		if position != -1 {
			xorValue := int(key)
			decryptedPosition := (position ^ xorValue) % len(alphabet)
			decryptedString += string(alphabet[decryptedPosition])
		} else {
			decryptedString += string(letter)
		}
	}

	return decryptedString
}

func main() {
	message := "Hello, World!"

	start := time.Now()
	encryptedMessage := encrypt(message)
	elapsed := time.Since(start)
	fmt.Println("Encrypted message:", encryptedMessage)
	fmt.Printf("Took %d ns to encrypt\n", elapsed.Nanoseconds())

	start = time.Now()
	decryptedMessage := decrypt(encryptedMessage)
	elapsed = time.Since(start)
	fmt.Println("Decrypted message:", decryptedMessage)
	fmt.Printf("Took %d ns to decrypt\n", elapsed.Nanoseconds())
}
