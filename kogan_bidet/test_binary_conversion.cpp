#include <array>
#include "esp_log.h"

int main() {
    std::array<uint8_t, 80> bitsArrayInChecksum_test = {
        0x14, 0x40, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x40, 0x14, 0x40,
        0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16,
        0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x40, 0x14, 0x16, 0x14, 0x16,
        0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16,
        0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16, 0x14, 0x16
    };

    // Create a new array (newArray) by extracting odd-indexed elements from bitsArrayInChecksum_test
    std::array<uint8_t, 40> newArray;
    for (size_t i = 1, j = 0; i < bitsArrayInChecksum_test.size(); i += 2, ++j) {
        newArray[j] = bitsArrayInChecksum_test[i];
    }

    // Replace 0x40 with 0x01 and 0x16 with 0x00 in newArray
    for (auto &element : newArray) {
        if (element == 0x40) {
            element = 0x01;
        } else if (element == 0x16) {
            element = 0x00;
        }
    }

    // Display the modified values of newArray in hexadecimal format
    ESP_LOGD("TAG", "Modified newArray (hex): ");
    for (size_t i = 0; i < newArray.size(); ++i) {
        ESP_LOGD("TAG", "%x ", static_cast<int>(newArray[i]));
    }
    ESP_LOGD("TAG", "\n");

    // Create a new array (bytesInBinaryFormat) by setting individual bits based on newArray
    std::array<uint8_t, 5> bytesInBinaryFormat = {0};
    for (size_t i = 0; i < newArray.size(); ++i) {
        bytesInBinaryFormat[i / 8] |= (newArray[i] & 0x01) << (7 - i % 8);
    }

    // Display the values of bytesInBinaryFormat in binary format
    ESP_LOGD("TAG", "bytesInBinaryFormat (binary): ");
    for (size_t i = 0; i < bytesInBinaryFormat.size(); ++i) {
        for (int j = 7; j >= 0; --j) {
            ESP_LOGD("TAG", "%d", (bytesInBinaryFormat[i] >> j) & 0x01);
        }
        ESP_LOGD("TAG", " ");
    }
    ESP_LOGD("TAG", "\n");

    // Create an array (decimalEquivalents) by converting each byte to its decimal equivalent
    std::array<uint8_t, 5> decimalEquivalents;
    for (size_t i = 0; i < bytesInBinaryFormat.size(); ++i) {
        decimalEquivalents[i] = bytesInBinaryFormat[i];
    }

    // Display the values of decimalEquivalents in decimal format
    ESP_LOGD("TAG", "decimalEquivalents (decimal): ");
    for (size_t i = 0; i < decimalEquivalents.size(); ++i) {
        ESP_LOGD("TAG", "%d ", static_cast<int>(decimalEquivalents[i]));
    }
    ESP_LOGD("TAG", "\n");

    // Calculate the checksum by summing the values in decimalEquivalents
    int checkSum = 0;
    for (size_t i = 0; i < decimalEquivalents.size(); ++i) {
        checkSum += decimalEquivalents[i];
    }

    // Display the value of checkSum
    ESP_LOGD("TAG", "checkSum: %d\n", checkSum);

    return 0;
}
