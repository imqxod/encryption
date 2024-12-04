use std::time::Instant;

static ALPHABET: &str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY1234567890!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

fn encrypt(input: &str) -> String {
    let key = (input.len() as f64).ln().sqrt().atan2(input.len() as f64);
    let mut encrypted_string = String::new();

    for letter in input.chars() {
        if let Some(position) = ALPHABET.find(letter) {
            let xor_value = key as usize;
            let encrypted_position = (position ^ xor_value) % ALPHABET.len();
            encrypted_string.push(ALPHABET.chars().nth(encrypted_position).unwrap());
        } else {
            encrypted_string.push(letter);
        }
    }

    let extra = (encrypted_string.len() as f64).ln().sqrt().atan2(encrypted_string.len() as f64);
    encrypted_string.push_str(&format!("^^{}^^", extra));
    encrypted_string
}

fn decrypt(encrypted_string: &str) -> String {
    let key = (encrypted_string.len() as f64).ln().sqrt().atan2(encrypted_string.len() as f64);
    let mut decrypted_string = String::new();

    let input = encrypted_string.split("^^").next().unwrap();
    for letter in input.chars() {
        if let Some(position) = ALPHABET.find(letter) {
            let xor_value = key as usize;
            let decrypted_position = (position ^ xor_value) % ALPHABET.len();
            decrypted_string.push(ALPHABET.chars().nth(decrypted_position).unwrap());
        } else {
            decrypted_string.push(letter);
        }
    }

    decrypted_string
}

fn main() {
    let message = "Hello, World!";

    let start = Instant::now();
    let encrypted_message = encrypt(message);
    let duration = start.elapsed();
    println!("Encrypted message: {}", encrypted_message);
    println!("Took {:.9} seconds to encrypt", duration.as_secs_f64());

    let start = Instant::now();
    let decrypted_message = decrypt(&encrypted_message);
    let duration = start.elapsed();
    println!("Decrypted message: {}", decrypted_message);
    println!("Took {:.9} seconds to decrypt", duration.as_secs_f64());
}
