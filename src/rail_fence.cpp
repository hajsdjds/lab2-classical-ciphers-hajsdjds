#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Rail Fence Encrypt
string railFenceEncrypt(string text, int rails) {
    if (rails < 2 || text.empty()) {
        return text;
    }
    vector<string> fence(rails, "");
    int row = 0, direction = 1;
    for (char ch : text) {
        fence[row] += ch;
        row += direction;
        if (row == rails - 1) direction = -1;
        else if (row == 0) direction = 1;
    }
    string result = "";
    for (string r : fence) result += r;
    return result;
}

// === HÀM BẮT BUỘC - TÊN ĐÚNG CHECKER ===
string rail_fence_decrypt(string cipher, int rails) {
    if (rails < 2 || cipher.empty()) {
        return cipher;
    }
    int n = cipher.length();
    vector<int> positions(n);
    vector<string> fence(rails, string(n, '*'));

    int row = 0, dir = 1;
    for (int i = 0; i < n; i++) {
        positions[i] = row;
        row += dir;
        if (row == rails - 1) dir = -1;
        else if (row == 0) dir = 1;
    }

    int idx = 0;
    for (int r = 0; r < rails; r++) {
        for (int i = 0; i < n; i++) {
            if (positions[i] == r) {
                fence[r][i] = cipher[idx++];
            }
        }
    }

    string result = "";
    row = 0; dir = 1;
    for (int i = 0; i < n; i++) {
        result += fence[row][i];
        row += dir;
        if (row == rails - 1) dir = -1;
        else if (row == 0) dir = 1;
    }
    return result;
}

// === HÀM BẮT BUỘC CHO Q8 - TÊN ĐÚNG CHECKER ===
string read_message_from_file() {
    ifstream infile("data/input.txt");
    string text = "";
    if (infile.is_open()) {
        getline(infile, text);
        infile.close();
    }
    return text;
}

int main() {
    cout << "=== RAIL FENCE CIPHER ===" << endl << endl;

    string text = "I LOVE YOU";
    int rails = 3;

    cout << "Original : " << text << endl;
    string enc = railFenceEncrypt(text, rails);
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << rail_fence_decrypt(enc, rails) << endl << endl;

    cout << "Test 2 rails: " << railFenceEncrypt("HELLO WORLD", 2) << endl;
    cout << "Test 4 rails: " << railFenceEncrypt("RAIL FENCE", 4) << endl;
    cout << "Invalid rails=1: " << railFenceEncrypt("TEST", 1) << endl << endl;

    string fileMsg = read_message_from_file();
    cout << "From input.txt: " << fileMsg << endl;
    if (!fileMsg.empty()) {
        cout << "Encrypt from file: " << railFenceEncrypt(fileMsg, 3) << endl;
    }

    return 0;
}
