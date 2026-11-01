/****************************************************
 * Автор:   Сабитов Ильнур                          *
 * Задание: строки, векторы и словари               *
 * Вариант: 28                                      *
 ****************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
  /****
  * A *
  ****/
  const int maxStringLength = 200;
  string mainString;
  string subString;
  size_t foundPosition;

  cout << "Enter the main string: ";
  getline(cin, mainString);

  cout << "Enter the substring: ";
  getline(cin, subString);

  if (mainString.length() > maxStringLength || subString.length() == 0) {
    cout << "INVALID\n\n";
    return 0;
  }

  foundPosition = mainString.find(subString);

  if (foundPosition < mainString.length()) {
    cout << "Answer: " << foundPosition + 1 << "\n\n";
  } else {
    cout << "Answer: NONE\n\n";
  }

  /****
  * B *
  ****/
  const int maxElementCount = 100;
  const int maxElementValue = 1000;
  int elementCount;
  int tempValue;
  vector<int> numberVector;
  int initialSize;

  cout << "Enter the number of elements: ";
  if (!(cin >> elementCount) || elementCount < 0 || elementCount > maxElementCount) {
    cout << "INVALID\n\n";
    return 0;
  }

  for (int elementIndex = 0; elementIndex < elementCount; ++elementIndex) {
    cout << "Enter element " << elementIndex + 1 << ": ";

    if (!(cin >> tempValue) || tempValue < -maxElementValue || tempValue > maxElementValue) {
      cout << "INVALID\n\n";
      return 0;
    }
    numberVector.push_back(tempValue);
  }

  cout << "Vector user: ";
  for (int elementIndex = 0; elementIndex < numberVector.size(); ++elementIndex) {
    cout << numberVector[elementIndex] << ' ';
  }

  if (numberVector.size() == 0) {
    cout << "\nAnswer: EMPTY\n\n";
  } else {
    initialSize = numberVector.size();

    for (int elementIndex = 0; elementIndex < initialSize; ++elementIndex) {
      numberVector.push_back(numberVector[elementIndex]);
    }

    cout << "\nAnswer: ";
    for (int elementIndex = 0; elementIndex < numberVector.size(); ++elementIndex) {
      cout << numberVector[elementIndex] << ' ';
    }
    cout << "\n\n";
  }


  /****
  * C *
  ****/
  const int maxPairCount = 100;
  const int maxPairValue = 1000;
  const int maxKeyLength = 40;
  int pairCount;
  int currentValue;
  string currentKey;
  map<string, int> valueMap;
  long long totalSum = 0;
  auto mapIterator = valueMap.begin();

  cout << "Enter the number of dictionary elements: ";
  if (!(cin >> pairCount) || pairCount < 0 || pairCount > maxPairCount) {
    cout << "INVALID\n\n";
    return 0;
  }

  for (int pairIndex = 0; pairIndex < pairCount; ++pairIndex) {
    cout << "Enter key: ";
    cin >> currentKey;
    cout << "Enter value: ";
    cin >> currentValue;

    if (currentKey.length() == 0 || currentKey.length() > maxKeyLength ||
      currentValue < -maxPairValue || currentValue > maxPairValue) {
      cout << "INVALID\n\n";
      return 0;
    }

    valueMap[currentKey] = currentValue;
  }

  for (mapIterator = valueMap.begin(); mapIterator != valueMap.end(); ++mapIterator) {
    totalSum += mapIterator->second;
  }

  cout << "\nAnswer: " << totalSum << "\n\n";

  /****
  * D *
  ****/
  const int maxRecordCount = 100;
  int recordCount;
  string customerName;
  string addressText;
  vector<map<string, string>> recordList;
  map<string, string> firstKnownAddress;
  map<string, bool> conflictFlags;
  bool anyConflict = false;
  auto conflictIterator = conflictFlags.begin();

  cout << "Enter number of records: ";
  cin >> recordCount;

  if (recordCount < 0 || recordCount > maxRecordCount) {
    cout << "INVALID\n\n";
    return 0;
  }

  cin.ignore(maxStringLength, '\n');

  for (int recordIndex = 0; recordIndex < recordCount; ++recordIndex) {
    cout << "customer = ";
    getline(cin, customerName);
    cout << "address = ";
    getline(cin, addressText);

    if (customerName.length() == 0 || customerName.length() > maxStringLength ||
      addressText.length() == 0 || addressText.length() > maxStringLength) {
      cout << "INVALID\n\n";
      return 0;
    }
    recordList.push_back({ {"customer", customerName}, {"address", addressText} });
  }

  for (int recordIndex = 0; recordIndex < recordList.size(); ++recordIndex) {
    string custName = recordList[recordIndex]["customer"];
    string addrText = recordList[recordIndex]["address"];

    if (firstKnownAddress.find(custName) == firstKnownAddress.end()) {
      firstKnownAddress[custName] = addrText;
    }
    else if (firstKnownAddress[custName] != addrText) {
      conflictFlags[custName] = true;
    }
  }

  cout << "\nAnswer:\n";

  for (conflictIterator = conflictFlags.begin(); conflictIterator != conflictFlags.end(); ++conflictIterator) {
    if (conflictIterator->second == true) {
      cout << conflictIterator->first << "\n";
      anyConflict = true;
    }
  }

  if (!anyConflict) {
    cout << "EMPTY\n";
  }

  return 0;
}