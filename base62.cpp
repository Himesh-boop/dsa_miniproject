#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const string BASE62 = "abcdefghijklmnopqrstuvwxyz"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "0123456789";

string encodeBase62(long long id){
    if(id == 0){
        return string(1, BASE62[0]);
    }
    string result = "";

    while(id>0){
        int remainder = id%62;
        result += BASE62[remainder];
        id /= 62;
    }
    reverse(result.begin(), result.end());
    return result;
}

long long decodeBase62(const string &shortCode){
    long long number = 0;

    for(char c: shortCode){
        number *= 62;
        number += BASE62.find(c);
    }
    return number;
}