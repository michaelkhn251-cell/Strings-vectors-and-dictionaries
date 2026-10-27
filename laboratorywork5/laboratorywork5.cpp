#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <limits>

using namespace std;

    int main() {
    const int maxLimit = 100;
    const int maxTextLength = 200;
    const int maxKeyLength = 40;
    const int minVal = -1000;
    const int maxVal = 1000;

    char partChoice;
    if(!(cin >> partChoice)) {
        cout << "INVALID\n";
        return 1;
    }

    // Очистка буфера после ввода символа выбора части
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(partChoice == 'A') {
        // ==========================================
        // ЧАСТЬ A – Палиндром букв
        // ==========================================
        string rawText;
        getline(cin, rawText);

        if(rawText.length() > maxTextLength) {
            cout << "INVALID\n";
            return 1;
        }

        string filteredText = "";
        for(int charIndex = 0; charIndex < static_cast<int>(rawText.length()); ++charIndex) {
            unsigned char currentChar = static_cast<unsigned char>(rawText[charIndex]);
            if(isalpha(currentChar)) {
                filteredText += static_cast<char>(tolower(currentChar));
            }
        }

        if(filteredText.empty()) {
            cout << "YES\n";
            return 0;
        }

        bool isPalindrome = true;
        int leftIndex = 0;
        int rightIndex = static_cast<int>(filteredText.length()) - 1;

        while(leftIndex < rightIndex) {
            if(filteredText[leftIndex] != filteredText[rightIndex]) {
                isPalindrome = false;
                break;
            }
            ++leftIndex;
            --rightIndex;
        }

        if(isPalindrome) {
            cout << "YES\n";
        }
 else {
            cout << "NO\n";
    }

    }
 else if (partChoice == 'B') {
      //==========================================
     // ЧАСТЬ B – Общие значения
     // ==========================================
     int firstCount;
     if(!(cin >> firstCount) || firstCount < 0 || firstCount > maxLimit) {
         cout << "INVALID\n";
         return 1;
     }

     vector<int> firstVector;
     for(int loopIndex = 0; loopIndex < firstCount; ++loopIndex) {
         int currentValue;
         if(!(cin >> currentValue) || currentValue < minVal || currentValue > maxVal) {
             cout << "INVALID\n";
             return 1;
         }
         firstVector.push_back(currentValue);
     }

     int secondCount;
     if(!(cin >> secondCount) || secondCount < 0 || secondCount > maxLimit) {
         cout << "INVALID\n";
         return 1;
     }

     vector<int> secondVector;
     for(int loopIndex = 0; loopIndex < secondCount; ++loopIndex) {
         int currentValue;
         if(!(cin >> currentValue) || currentValue < minVal || currentValue > maxVal) {
             cout << "INVALID\n";
             return 1;
         }
         secondVector.push_back(currentValue);
     }

     vector<int> commonValues;
     for(int firstIndex = 0; firstIndex < firstCount; ++firstIndex) {
         bool isInSecond = false;
         for(int secondIndex = 0; secondIndex < secondCount; ++secondIndex) {
             if(firstVector[firstIndex] == secondVector[secondIndex]) {
                 isInSecond = true;
                 break;
             }
         }

         if(isInSecond) {
             bool isAlreadyAdded = false;
             for(int resultIndex = 0; resultIndex < static_cast<int>(commonValues.size()); ++resultIndex) {
                 if(commonValues[resultIndex] == firstVector[firstIndex]) {
                     isAlreadyAdded = true;
                     break;
                 }
             }

             if(!isAlreadyAdded) {
                 commonValues.push_back(firstVector[firstIndex]);
             }
         }
     }

     if(commonValues.empty()) {
         cout << "EMPTY\n";
     }
 else {
         for(int resultIndex = 0; resultIndex < static_cast<int>(commonValues.size()); ++resultIndex) {
             if(resultIndex > 0) {
                 cout << " ";
             }
             cout << commonValues[resultIndex];
         }
         cout << "\n";
         }

         }
 else if (partChoice == 'C') {
             // ==========================================
             // ЧАСТЬ C – Ключ минимального значения
             // ==========================================
             int pairCount;
             if(!(cin >> pairCount) || pairCount < 0 || pairCount > maxLimit) {
                 cout << "INVALID\n";
                 return 1;
             }

             map<string, int> valueMap;
             for(int loopIndex = 0; loopIndex < pairCount; ++loopIndex) {
                 string currentKey;
                 int currentValue;

                 if(!(cin >> currentKey >> currentValue)) {
                     cout << "INVALID\n";
                     return 1;
                 }

                 if(currentKey.empty() || currentKey.length() > maxKeyLength) {
                     cout << "INVALID\n";
                     return 1;
                 }

                 for(int charIndex = 0; charIndex < static_cast<int>(currentKey.length()); ++charIndex) {
                     if(static_cast<unsigned char>(currentKey[charIndex]) > 127) {
                         cout << "INVALID\n";
                         return 1;
                     }
                 }

                 if(currentValue < minVal || currentValue > maxVal) {
                     cout << "INVALID\n";
                     return 1;
                 }

                 // Присваивание реализует правило последнего значения для повторяющихся ключей
                 valueMap[currentKey] = currentValue;
             }

             if(valueMap.empty()) {
                 cout << "NONE\n";
                 return 0;
             }

             string minKey = "";
             int minValue = 0;
             bool isFirst = true;

             // Классический цикл с итератором (без enhanced for)
             for(map<string, int>::iterator iter = valueMap.begin(); iter != valueMap.end(); ++iter) {
                 if(isFirst) {
                     minKey = iter->first;
                     minValue = iter->second;
                     isFirst = false;
                 }
 else {
                     if(iter->second < minValue) {
                         minKey = iter->first;
                         minValue = iter->second;
                     }
 else if (iter->second == minValue) {
                         // Благодаря сортировке map, ключи идут лексикографически. 
                         // Но для надежности и явного выполнения условия тай-брейка:
                         if(iter->first < minKey) {
                             minKey = iter->first;
                         }
                         }
                         }
             }

             cout << minKey << " " << minValue << "\n";

             }
 else if (partChoice == 'D') {
                 // ==========================================
                 // ЧАСТЬ D – Отменённые заявки
                 // ==========================================
                 int recordCount;
                 if(!(cin >> recordCount) || recordCount < 0 || recordCount > maxLimit) {
                     cout << "INVALID\n";
                     return 1;
                 }

                 map<string, bool> activeParticipants;
                 for(int loopIndex = 0; loopIndex < recordCount; ++loopIndex) {
                     string currentName;
                     string currentAction;

                     if(!(cin >> currentName >> currentAction)) {
                         cout << "INVALID\n";
                         return 1;
                     }

                     if(currentName.empty() || currentName.length() > maxTextLength) {
                         cout << "INVALID\n";
                         return 1;
                     }

                     for(int charIndex = 0; charIndex < static_cast<int>(currentName.length()); ++charIndex) {
                         if(static_cast<unsigned char>(currentName[charIndex]) > 127) {
                             cout << "INVALID\n";
                             return 1;
                         }
                     }

                     if(currentAction != "join" && currentAction != "cancel") {
                         cout << "INVALID\n";
                         return 1;
                     }

                     if(currentAction == "join") {
                         activeParticipants[currentName] = true;
                     }
 else if (currentAction == "cancel") {
                         activeParticipants.erase(currentName);
                         }
                 }

                 for(map<string, bool>::iterator iter = activeParticipants.begin(); iter != activeParticipants.end(); ++iter) {
                     cout << iter->first << "\n";
                 }

                 }
 else {
                     cout << "INVALID\n";
                     return 1;
                     }

                     return 0;
}
