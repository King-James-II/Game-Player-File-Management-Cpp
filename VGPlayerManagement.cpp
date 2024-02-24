#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Program: Video Game Player Data Management
// Description: This program manages player data in a video game, including writing, reading, appending,
//              and performing random access on player data stored in a file.

// Function prototypes
void writePlayerDataToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
        exit(1);
    }

    // Example: Write player data to file
    outFile << "Player Name: John Doe" << endl;
    outFile << "Level: 10" << endl;
    outFile << "Score: 5000" << endl;

    outFile.close();
}

void readPlayerDataFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file for reading: " << filename << endl;
        exit(1);
    }

    // Example: Read player data from file and output to console
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();
}

void appendPlayerDataToFile(const string& filename) {
    ofstream outFile(filename, ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file for appending: " << filename << endl;
        exit(1);
    }

    // Example: Append additional player data to file
    outFile << "New Player Name: Jane Smith" << endl;
    outFile << "New Level: 5" << endl;
    outFile << "New Score: 2500" << endl;

    outFile.close();
}

void randomAccessPlayerData(const string& filename) {
    fstream file(filename, ios::in | ios::out);
    if (!file) {
        cerr << "Error: Unable to open file for random access: " << filename << endl;
        exit(1);
    }

    // Example: Perform random access on player data in file
    srand(time(nullptr));
    const int numRecords = 2;
    for (int i = 0; i < numRecords; ++i) {
        int pos = rand() % numRecords;
        file.seekg(pos * sizeof(string), ios::beg);
        string record;
        getline(file, record);
        cout << "Randomly accessed record " << pos + 1 << ": " << record << endl;
    }

    file.close();
}

int main() {
    // File paths
    const string playerDataFile = "player_data.txt";

    // Write player data to file
    cout << "Writing player data to file..." << endl;
    writePlayerDataToFile(playerDataFile);
    cout << "Player data written successfully." << endl << endl;

    // Read player data from file
    cout << "Reading player data from file..." << endl;
    readPlayerDataFromFile(playerDataFile);
    cout << endl;

    // Append additional player data to file
    cout << "Adding additional player data to file..." << endl;
    appendPlayerDataToFile(playerDataFile);
    cout << "Additional player data added successfully." << endl << endl;

    // Perform random access on player data in file
    cout << "Performing random access on player data in file..." << endl;
    randomAccessPlayerData(playerDataFile);
    cout << endl;

    return 0;
}
