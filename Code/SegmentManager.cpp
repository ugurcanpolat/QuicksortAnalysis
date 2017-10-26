/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 09.11.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project2
 
 * * * * * * * * * * * * * * * * * */

#include "SegmentManager.h"

#include <fstream> // ofstream
#include <chrono> // high_resolution_clock

SegmentManager::SegmentManager() {
    size = 0;
}

int SegmentManager::partition(int p, int r) {
    /* This function is written according to the pseudocode in
     the lecture slides. */
    
    Segment x = segments[r];
    int i = p - 1;
    
    for(int j = p; j < r; j++) {
        if (segments[j].compare(x, SORT) <= 0) {
            i++;
            Segment temp = segments[j];
            segments[j] = segments[i];
            segments[i] = temp;
        }
    }
    
    Segment temp = segments[r];
    segments[r] = segments[i+1];
    segments[i+1] = temp;
    
    return i+1;
}

void SegmentManager::quickSort(int p, int r) {
    /* This function is written according to the pseudocode in
     the lecture slides. */
    
    if (p < r) {
        int q = partition(p, r);
        quickSort(p, q-1);
        quickSort(q+1, r);
    }
}

float SegmentManager::sortSegments() {
    using namespace chrono;
    
    auto sortingStart = high_resolution_clock::now(); // Begin time stamp
    quickSort(0, size-1); // Sort
    auto sortingEnd = high_resolution_clock::now(); // End time stamp
    
    // Get the elapsed time in unit microseconds
    float elapsed_time = duration_cast<microseconds>(sortingEnd - sortingStart).count();
    
    return elapsed_time;
}

void SegmentManager::insertSegment(const Segment& new_card) {
    segments.push_back(new_card);
    size++;
}

void SegmentManager::writeOutputFile(const string file_name) const {
    ofstream output(file_name, ofstream::out); // Write
    
    if (!output.is_open()) {
        cout << endl << "Error opening output file." << endl << endl;
        return;
    }
    
    output << "population" << ',';
    output << "minimum_age" << ',';
    output << "maximum_age" << ',';
    output << "gender" << ',';
    output << "zipcode" << ',';
    output << "geo_id" << endl;
    
    // Write the sorted segment values
    for (int counter = 0; counter < size; counter++) {
        output << (segments[counter]).getPopulation() << ',';
        
        if ((segments[counter]).getMinAge() != -1)
            output << (segments[counter]).getMinAge() << ',';
        else
            output << ',';
        
        if ((segments[counter]).getMaxAge() != -1)
            output << (segments[counter]).getMaxAge() << ',';
        else
            output << ',';
        
        output << (segments[counter]).getGender() << ',';
        output << (segments[counter]).getZipCode() << ',';
        output << (segments[counter]).getGeoId() << endl;
    }
    
    // Close the output file since it is no longer needed
    output.close();
}

