#include "solutions.h"

void extractWordsAndUniqueStatus(string& s, map<string, bool>& uncommonMap) {
    int pos;
    while((pos = (int)s.find(" ")) != string::npos) {
        string word = s.substr(0, pos);
        if(uncommonMap.find(word) == uncommonMap.end()) {
            uncommonMap.insert({word, false});
        } else {
            uncommonMap[word] = true;
        }
        s = s.erase(0, pos + 1);
    }
    if(uncommonMap.find(s) == uncommonMap.end()){
        uncommonMap.insert({s, false});
    } else {
        uncommonMap[s] = true;
    }
}

vector<string> Solution::uncommonFromSentences(string s1, string s2) {
    map<string, bool> uncommonCheck;
    extractWordsAndUniqueStatus(s1, uncommonCheck);
    extractWordsAndUniqueStatus(s2, uncommonCheck);

    vector<string> uncommon;
    for(auto const& item : uncommonCheck) {
        if(!item.second) {
        uncommon.push_back(item.first);
        }
    }
    return uncommon;
}
