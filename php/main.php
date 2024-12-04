<?php

$alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY1234567890!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

function encrypt($input) {
    $key = atan2(sqrt(log(strlen($input))), sin(strlen($input)));
    $encryptedString = "";

    foreach (str_split($input) as $letter) {
        $position = strpos($alphabet, $letter);
        if ($position !== false) {
            $xorValue = (int) $key;
            $encryptedPosition = ($position ^ $xorValue) % strlen($alphabet);
            $encryptedString .= $alphabet[$encryptedPosition];
        } else {
            $encryptedString .= $letter;
        }
    }

    $extra = atan2(sqrt(log(strlen($encryptedString))), sin(strlen($encryptedString)));
    $encryptedString .= "^^$extra^^";
    return $encryptedString;
}

function decrypt($encryptedString) {
    $key = atan2(sqrt(log(strlen($encryptedString))), sin(strlen($encryptedString)));
    $decryptedString = "";

    $input = explode("^^", $encryptedString)[0];
    foreach (str_split($input) as $letter) {
        $position = strpos($alphabet, $letter);
        if ($position !== false) {
            $xorValue = (int) $key;
            $decryptedPosition = ($position ^ $xorValue) % strlen($alphabet);
            $decryptedString .= $alphabet[$decryptedPosition];
        } else {
            $decryptedString .= $letter;
        }
    }

    return $decryptedString;
}

$message = "Hello, World!";
$startTime = microtime(true);
$encryptedMessage = encrypt($message);
$encryptDuration = microtime(true) - $startTime;
echo "Encrypted message: $encryptedMessage\n";
echo "Took $encryptDuration seconds to encrypt\n";

$decryptStartTime = microtime(true);
$decryptedMessage = decrypt($encryptedMessage);
$decryptDuration = microtime(true) - $decryptStartTime;
echo "Decrypted message: $decryptedMessage\n";
echo "Took $decryptDuration seconds to decrypt\n";

?>
