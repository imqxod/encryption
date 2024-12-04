ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY1234567890!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

def encrypt(input_string)
  key = Math.atan2(Math.sqrt(Math.log(input_string.length)), Math.sin(input_string.length))
  encrypted_string = ""

  input_string.each_char do |letter|
    position = ALPHABET.index(letter)
    if position
      xor_value = key.to_i
      encrypted_position = (position ^ xor_value) % ALPHABET.length
      encrypted_string += ALPHABET[encrypted_position]
    else
      encrypted_string += letter
    end
  end

  extra = Math.atan2(Math.sqrt(Math.log(encrypted_string.length)), Math.sin(encrypted_string.length))
  encrypted_string += "^^#{extra}^^"
  encrypted_string
end

def decrypt(encrypted_string)
  key = Math.atan2(Math.sqrt(Math.log(encrypted_string.length)), Math.sin(encrypted_string.length))
  decrypted_string = ""

  input = encrypted_string.split("^^")[0]
  input.each_char do |letter|
    position = ALPHABET.index(letter)
    if position
      xor_value = key.to_i
      decrypted_position = (position ^ xor_value) % ALPHABET.length
      decrypted_string += ALPHABET[decrypted_position]
    else
      decrypted_string += letter
    end
  end

  decrypted_string
end

message = "Hello, World!"
start_time = Process.clock_gettime(Process::CLOCK_MONOTONIC)
encrypted_message = encrypt(message)
encrypt_duration = Process.clock_gettime(Process::CLOCK_MONOTONIC) - start_time
puts "Encrypted message: #{encrypted_message}"
puts "Took #{'%.8f' % encrypt_duration} seconds to encrypt"

start_time = Process.clock_gettime(Process::CLOCK_MONOTONIC)
decrypted_message = decrypt(encrypted_message)
decrypt_duration = Process.clock_gettime(Process::CLOCK_MONOTONIC) - start_time
puts "Decrypted message: #{decrypted_message}"
puts "Took #{'%.8f' % decrypt_duration} seconds to decrypt"
