import java.util.HashMap;
import java.util.Map;

public class Encryption {
    
    private static final String ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY1234567890!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    public static String encrypt(String input) {
        double key = Math.atan2(Math.sqrt(Math.log(input.length())), Math.sin(input.length()));
        StringBuilder encryptedString = new StringBuilder();

        for (char letter : input.toCharArray()) {
            int position = ALPHABET.indexOf(letter);
            if (position != -1) {
                int xorValue = (int) key;
                int encryptedPosition = (position ^ xorValue) % ALPHABET.length();
                encryptedString.append(ALPHABET.charAt(encryptedPosition));
            } else {
                encryptedString.append(letter);
            }
        }

        double extra = Math.atan2(Math.sqrt(Math.log(encryptedString.length())), Math.sin(encryptedString.length()));
        encryptedString.append("^^").append(extra).append("^^");
        return encryptedString.toString();
    }

    public static String decrypt(String encryptedString) {
        double key = Math.atan2(Math.sqrt(Math.log(encryptedString.length())), Math.sin(encryptedString.length()));
        StringBuilder decryptedString = new StringBuilder();

        String input = encryptedString.split("\\^\\^")[0];
        for (char letter : input.toCharArray()) {
            int position = ALPHABET.indexOf(letter);
            if (position != -1) {
                int xorValue = (int) key;
                int decryptedPosition = (position ^ xorValue) % ALPHABET.length();
                decryptedString.append(ALPHABET.charAt(decryptedPosition));
            } else {
                decryptedString.append(letter);
            }
        }

        return decryptedString.toString();
    }

    public static void main(String[] args) {
        String message = "Hello, World!";

        long startTime = System.nanoTime();
        String encryptedMessage = encrypt(message);
        long endTime = System.nanoTime();
        double encryptDuration = (endTime - startTime) / 1_000_000_000.0;
        System.out.println("Encrypted message: " + encryptedMessage);
        System.out.printf("Took %.9f seconds to encrypt%n", encryptDuration);

        startTime = System.nanoTime();
        String decryptedMessage = decrypt(encryptedMessage);
        endTime = System.nanoTime();
        double decryptDuration = (endTime - startTime) / 1_000_000_000.0;
        System.out.println("Decrypted message: " + decryptedMessage);
        System.out.printf("Took %.9f seconds to decrypt%n", decryptDuration);
    }
}
