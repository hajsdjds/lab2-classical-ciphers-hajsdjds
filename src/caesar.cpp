#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool is_valid_message(const string &text) {
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

char shift_char(char c, int shift) {
    if (!isalpha(static_cast<unsigned char>(c))) return c;

    char base = isupper(static_cast<unsigned char>(c)) ? 'A' : 'a';
    shift %= 26;
    if (shift < 0) shift += 26;
    return static_cast<char>((c - base + shift) % 26 + base);
}

string caesar_encrypt(const string &plaintext, int shift) {
    string ciphertext;
    for (char c : plaintext) {
        ciphertext += shift_char(c, shift); // đã xử lý dịch ký tự
    }
    return ciphertext;
}

string caesar_decrypt(const string &ciphertext, int shift) {
    return caesar_encrypt(ciphertext, -shift); // giải mã bằng dịch ngược
}

int main() {
    cout << "=== Caesar Cipher Demo ===\n";
    cout << "1. Encrypt\n2. Decrypt\nChoose: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string message;
    int shift;

    cout << "Enter message: ";
    getline(cin, message);
    cout << "Enter key: ";
    cin >> shift;

    if (!is_valid_message(message)) {
        cout << "Invalid input. Only letters and spaces are allowed.\n";
        return 0;
    }

    if (choice == 1) {
        cout << "Ciphertext: " << caesar_encrypt(message, shift) << "\n";
    } else if (choice == 2) {
        cout << "Plaintext: " << caesar_decrypt(message, shift) << "\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
