#include <iostream>
#include <string>
#include <cctype>   // cho isupper, islower
using namespace std;

// Caesar Encrypt
string caesar_encrypt(string text, int key) {
    string result = "";
    key = key % 26;
    if (key < 0) key += 26;

    for (char ch : text) {
        if (isupper(ch)) {
            result += char((ch + key - 'A') % 26 + 'A');
        }
        else if (islower(ch)) {
            result += char((ch + key - 'a') % 26 + 'a');
        }
        else {
            result += ch;   // giữ dấu cách
        }
    }
    return result;
}

// === HÀM BẮT BUỘC - TÊN ĐÚNG CHECKER ===
string caesar_decrypt(string text, int key) {
    return caesar_encrypt(text, -key);
}

int main() {
    cout << "=== CAESAR CIPHER ===" << endl << endl;

    string text = "I LOVE YOU";
    int key = 3;

    cout << "Original : " << text << endl;
    string enc = caesar_encrypt(text, key);
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << caesar_decrypt(enc, key) << endl;

    return 0;
}
