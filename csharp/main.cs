using System;

class Program
{
    static string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYXY1234567890!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    static string Encrypt(string input)
    {
        double key = Math.Atan2(Math.Sqrt(Math.Log(input.Length)), Math.Sin(input.Length));
        string encryptedString = "";

        foreach (char letter in input)
        {
            if (alphabet.Contains(letter))
            {
                int position = alphabet.IndexOf(letter);
                int xorValue = (int)key;
                int encryptedPosition = (position ^ xorValue) % alphabet.Length;
                encryptedString += alphabet[encryptedPosition];
            }
            else
            {
                encryptedString += letter;
            }
        }

        encryptedString += "^^" + Math.Atan2(Math.Sqrt(Math.Log(encryptedString.Length)), Math.Sin(encryptedString.Length)) + "^^";
        return encryptedString;
    }

    static string Decrypt(string encryptedString)
    {
        double key = Math.Atan2(Math.Sqrt(Math.Log(encryptedString.Length)), Math.Sin(encryptedString.Length));
        string decryptedString = "";

        encryptedString = encryptedString.Split("^^")[0];

        foreach (char letter in encryptedString)
        {
            if (alphabet.Contains(letter))
            {
                int position = alphabet.IndexOf(letter);
                int xorValue = (int)key;
                int decryptedPosition = (position ^ xorValue) % alphabet.Length;
                decryptedString += alphabet[decryptedPosition];
            }
            else
            {
                decryptedString += letter;
            }
        }

        return decryptedString;
    }

    static void Main()
    {
        string message = "Hello, World!";
        var start = DateTime.Now;
        string encryptedMessage = Encrypt(message);
        var elapsed = DateTime.Now - start;
        Console.WriteLine("Encrypted message: " + encryptedMessage);
        Console.WriteLine($"Took {elapsed.TotalSeconds:F8} sec to encrypt");

        start = DateTime.Now;
        string decryptedMessage = Decrypt(encryptedMessage);
        elapsed = DateTime.Now - start;
        Console.WriteLine("Decrypted message: " + decryptedMessage);
        Console.WriteLine($"Took {elapsed.TotalSeconds:F8} sec to decrypt");
    }
}
