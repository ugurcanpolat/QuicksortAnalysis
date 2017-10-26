/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 09.11.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project2
 
 * * * * * * * * * * * * * * * * * */

#include <iostream> // cout
#include <iomanip> // setprecision, fixed
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <string> // string

#include "SegmentManager.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // All arguments must be passed with run command
    if (argc != 2) {
        cout << endl << "Missing arguments to proceed." << endl << endl;
        return 0;
    }
    
    int number = stoi(string(argv[1])); // Number of lines to process
    
    ifstream input("population_by_zip_2010.csv", ifstream::in); // Read
    
    if (!input.is_open()) {
        cout << endl << "Error opening input file." << endl << endl;
        return 0;
    }
    
    string line;
    SegmentManager segmentManager;
  
    getline(input, line); // Skip the header line
    
    for(int count = 0; count < number; count++) {
        getline(input, line); // Read the line
        
        // If line is empty, no need to take action
        if(line.empty()) break;
        if(input.eof()) break;
        
        // Create stringstream to parse with ','
        stringstream linestream(line);
    
        string read[6];
        
        // Parse the line
        getline(linestream, read[0], ',');
        getline(linestream, read[1], ',');
        getline(linestream, read[2], ',');
        getline(linestream, read[3], ',');
        getline(linestream, read[4], ',');
        linestream >> read[5];
        
        // Create a new segment and insert it to |segmentManager|
        Segment new_segment(read);
        segmentManager.insertSegment(new_segment);
    }
    
    // Close the input file since it is no longer needed
    input.close();
    
    float sort_time;
    
    // Sort segments with quick sort algorithm
    sort_time = segmentManager.sortSegments();
    
    // Write sorted segments into the output file
    segmentManager.writeOutputFile("output.csv");

    cout << endl << "Time elapsed: " << fixed << setprecision(0) << sort_time;
    cout << " microseconds" << endl << endl;
    
    return 0;
}
