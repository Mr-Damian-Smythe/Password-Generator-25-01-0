#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Function to generate a random password
void generate_password(int min_length, int max_length) {
    // Define the range of Unicode characters
    unsigned int unicode_start = 0x21; // Starting from '!' (decimal 33)
    unsigned int unicode_end = 0x10FFFF; // Maximum valid Unicode code point

    // Randomly choose the password length between the min and max range
    int length = min_length + rand() % (max_length - min_length + 1);

    // Allocate memory for the password
    wchar_t password[length + 1]; // +1 for the null terminator

    // Generate each character in the password
    for (int i = 0; i < length; i++) {
        // Generate a random Unicode code point in the range
        unsigned int random_codepoint = unicode_start + rand() % (unicode_end - unicode_start + 1);

        // Ensure it's a valid printable character (skip surrogate pairs)
        while ((random_codepoint >= 0xD800 && random_codepoint <= 0xDFFF) || random_codepoint > unicode_end) {
            random_codepoint = unicode_start + rand() % (unicode_end - unicode_start + 1);
        }

        // Assign the random character to the password
        password[i] = (wchar_t)random_codepoint;
    }

    // Null-terminate the password
    password[length] = L'\0';

    // Print the generated password
    wprintf(L"Generated Password: %ls\n", password);
}

int main() {
    // Set locale to support Unicode output
    setlocale(LC_ALL, "");

    // Seed the random number generator with the current time
    srand((unsigned int)time(NULL));

    // Call the password generation function
    generate_password(20, 25);

    return 0;
}
