const ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY1234567890!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

function encrypt(input) {
    const key = Math.atan2(Math.sqrt(Math.log(input.length)), Math.sin(input.length));
    let encryptedString = "";

    for (let i = 0; i < input.length; i++) {
        let letter = input[i];
        let position = ALPHABET.indexOf(letter);
        if (position !== -1) {
            const xorValue = Math.floor(key);
            const encryptedPosition = (position ^ xorValue) % ALPHABET.length;
            encryptedString += ALPHABET[encryptedPosition];
        } else {
            encryptedString += letter;
        }
    }

    const extra = Math.atan2(Math.sqrt(Math.log(encryptedString.length)), Math.sin(encryptedString.length));
    encryptedString += `^^${extra}^^`;
    return encryptedString;
}

function decrypt(encryptedString) {
    const key = Math.atan2(Math.sqrt(Math.log(encryptedString.length)), Math.sin(encryptedString.length));
    let decryptedString = "";

    let input = encryptedString.split("^^")[0];
    for (let i = 0; i < input.length; i++) {
        let letter = input[i];
        let position = ALPHABET.indexOf(letter);
        if (position !== -1) {
            const xorValue = Math.floor(key);
            const decryptedPosition = (position ^ xorValue) % ALPHABET.length;
            decryptedString += ALPHABET[decryptedPosition];
        } else {
            decryptedString += letter;
        }
    }

    return decryptedString;
}

function measureTime(callback) {
    const start = performance.now();
    callback();
    const end = performance.now();
    return (end - start) / 1000;
}

const message = "Hello, World!";

const encryptDuration = measureTime(() => {
    const encryptedMessage = encrypt(message);
    console.log("Encrypted message:", encryptedMessage);
});

console.log(`Took ${encryptDuration.toFixed(9)} seconds to encrypt`);

const decryptDuration = measureTime(() => {
    const encryptedMessage = encrypt(message);
    const decryptedMessage = decrypt(encryptedMessage);
    console.log("Decrypted message:", decryptedMessage);
});

console.log(`Took ${decryptDuration.toFixed(9)} seconds to decrypt`);
