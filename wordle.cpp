#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here

bool wordleWordCheck(const std::string& floating, const std::set<std::string>& dict, const std::string& curr);
void wordleHelperFunc(const std::string& in, const std::string& floating, 
const std::set<std::string>& dict, std::set<std::string>& mySet, std::string curr, int cnt);


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{

  // Add your code here

  std::set<std::string> mySet;
  bool check = true;
  std::string curr = "";
  int cnt = 0;




  // Check to see how many spots are open
  for (size_t i = 0; i < in.length(); ++i) {
    if (in[i] == '-') {
      cnt++; // see how many open spots there are
      check = false;
    }
  }

  // Case 1: If String is empty
  if (in.empty()) { 
    return mySet;
  }

  // Case 2: If the word given is complete
  else if (check == true) {
    mySet.insert(in);
  }

  // Case 3: Not solved yet
  else {
    wordleHelperFunc(in, floating, dict, mySet, curr, cnt);
  }

  return mySet;
}

// Define any helper functions here

bool wordleWordCheck(const std::string& floating, const std::set<std::string>& dict, const std::string& curr)
{

  int cnt = 0;
  std::string currString = curr;

  for (int i = floating.length() - 1; i >= 0; --i) {
    char floatingChar = floating[i];
    size_t currLoc = currString.find(floatingChar);

    // if found
    if (currLoc != string::npos) {
      currString.erase(currString.begin() + (int)currLoc);
      cnt++;
    }
  }

  if (dict.find(curr) == dict.end()) {
    return false;
  }
  
  if ((unsigned int)cnt != floating.length()) {
    return false;
  }

  return true;

}

void wordleHelperFunc(const std::string& in, const std::string& floating, const std::set<std::string>& dict, 
std::set<std::string>& mySet, std::string curr, int cnt)
{

  // Case 1: Length is same
  if (curr.length() == in.length()) { 
    if (wordleWordCheck(floating, dict, curr)) {
      mySet.insert(curr);
    }
    return;
  }

  // Case 2: IF character at point is already figured out --> NOT A DASH
  if (in[curr.length()] != '-') {
    std::string myString = curr + in[curr.length()];
    wordleHelperFunc(in, floating, dict, mySet, myString, cnt);
  }

  else if (cnt  == (int)floating.length()) {
    for (int i = floating.length() - 1; i >= 0; --i) {
      std::string myFloatingString = floating;
      std::string currCopy = curr + myFloatingString[i];
      myFloatingString.erase(i, 1);
      wordleHelperFunc(in, myFloatingString, dict, mySet, currCopy, cnt - 1);
    }
  }


  else {
    for (char i = 'a'; i <= 'z'; ++i) {
      std::string myFloatingString = floating;
      if (myFloatingString.find(i) != string::npos) {
        myFloatingString.erase(myFloatingString.find(i), 1);
      }
      wordleHelperFunc(in, myFloatingString, dict, mySet, curr + i, cnt - 1);
    }
  }
}
