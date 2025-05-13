#include "Encryption.h"

std::string xorEncryptDecrypt(const std::string &data, const std::string &key) {
    std::string result = data;

    for (size_t i = 0; i < data.size(); i++)
        result[i] = data[i] ^ key[i  % key.size()];
    return result
}