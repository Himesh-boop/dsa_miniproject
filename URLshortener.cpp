#include <iostream>
#include <string>
#include <unordered_map>
#include "base62.cpp"

using namespace std;

class URLshortener{
    private:
        unordered_map<string, string> longToShort;
        unordered_map<string, string> shortToLong;
        long long counter;
        
        string BASE62 =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789";
    
    public:
        URLshortener() {
            counter = 1;
        }
        
        string shortenURL(string longURL){
            if(longToShort.find(longURL)!=longToShort.end()){
                return longToShort[longURL];
            }
            string shortCode = encodeBase62(counter);
            shortToLong[shortCode] = longURL;
            longToShort[longURL] = shortCode;

            return shortCode;
        }
};