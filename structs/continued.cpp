#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Word {
    string token;
    vector<int> positions;
};

size_t findToken(const string& token, const vector<Word>& words) {
    for (size_t index = 0; index < words.size(); ++index) {
        if (words[index].token == token) return index;
    }
    return words.size();
}

int main() {
    ifstream inputStream("jabberwocky");
    if (!inputStream) {
        cout << "File not found" << endl;
        exit(1);
    }

    vector<Word> words;

    string token;
    int pos = 0;
    while (inputStream >> token) {
        // Have we seen word?
        size_t where = findToken(token, words);
        // If so
        if (where != words.size()) {
            // add position
            words[where].positions.push_back(pos);
        }
        //if not
        else {
            // add a new Word object to vector
            Word aWord;
            aWord.token = token;
            aWord.positions.push_back(pos);
            words.push_back(aWord);

        }

        ++pos;

    }
    inputStream.close();
    
}