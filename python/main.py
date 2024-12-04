import math, time

alphabet = r"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYXY1234567890!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~"

def encrypt(string):
    key = math.atan2(math.sqrt(math.log(len(string))), math.sin(len(string)))
    encrypted_string = ""
    
    for letter in string:
        if letter in alphabet:
            position = alphabet.index(letter)
            xor_value = int(key)
            encrypted_position = (position ^ xor_value) % len(alphabet)
            encrypted_string += alphabet[encrypted_position]
        else:
            encrypted_string += letter
    
    encrypted_string += "^^" + str(math.atan2(math.sqrt(math.log(len(encrypted_string))), math.sin(len(encrypted_string)))) + "^^"
    
    return encrypted_string

def decrypt(encrypted_string):
    key = math.atan2(math.sqrt(math.log(len(encrypted_string))), math.sin(len(encrypted_string)))
    decrypted_string = ""
    
    encrypted_string = encrypted_string.split("^^")[0]
    
    for letter in encrypted_string:
        if letter in alphabet:
            position = alphabet.index(letter)
            xor_value = int(key)
            decrypted_position = (position ^ xor_value) % len(alphabet)
            decrypted_string += alphabet[decrypted_position]
        else:
            decrypted_string += letter
    
    return decrypted_string

# Test cases
message = "Hello, World!"
start = time.perf_counter()
encrypted_message = encrypt(message)
elapsed = time.perf_counter() - start
print("Encrypted message: ", encrypted_message)
print(f"Took {elapsed:.8f} sec to encrypt")

start = time.perf_counter()
decrypted_message = decrypt(encrypted_message)
elapsed = time.perf_counter() - start
print("Decrypted message: ", decrypted_message)
print(f"Took {elapsed:.8f} sec to decrypt")