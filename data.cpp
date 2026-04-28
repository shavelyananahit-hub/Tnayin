#include <iostream>
#include <string>
using namespace std;

string Data = R"(
[
  {
    "fullName": "John Smith",
    "points": 20,
    "child": {
      "fullName": "Michael Brown",
      "points": 25,
      "child": {
        "fullName": "David Wilson",
        "points": 14
      }
    }
  },
  {
    "fullName": "Emma Johnson",
    "points": 30
  },
  {
    "fullName": "Olivia Davis",
    "points": 22,
    "child": {
      "fullName": "James Miller",
      "points": 18
    }
  }
]
)";

string names[100];
int scores[100];
int count = 0;
int sum = 0;

string tempName = "";
int tempScore = -1;

int read(int i) {
    if (i >=Data.size())
        return i;

    if (i + 2 < Data.size() && Data[i] == '"' && Data[i+1] == 'f' &&  Data[i+2] == 'u') {

        i += 11;
       
        while (i < Data.size() && Data[i] != '"') i++;
        i++;

        while (i < Data.size() && Data[i] != '"') {
            tempName += Data[i];
            i++;
        }
    }

  if (i + 2 < Data.size() &&  Data[i] == '"' &&  Data[i+1] == 'p' &&   Data[i+2] == 'o') {

    while (i < Data.size() &&
          !(Data[i] >= '0' && Data[i] <= '9'))
           i++;

        tempScore = 0;

        while (i < Data.size() && Data[i] >= '0' && Data[i] <= '9') {
            tempScore = tempScore * 10 + (Data[i] - '0');
            i++;
        }
    }
    
    if (tempName != "" && tempScore != -1) {
        names[count] = tempName;
        scores[count] = tempScore;

        sum += tempScore;
        count++;
        tempName = "";
        tempScore = -1;
    }

    i++;
    return read(i);
}

int main() {
    read(0);

    cout << "Names:" << endl;
    for (int j = 0; j < count; j++) {
        cout << names[j] << endl; 
    }

    if (count > 0)
        cout << "Average points: "
             << (double)sum / count << endl;
    else
        cout << "No data";
}