/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 09.11.2017
 */

#include "SegmentManager.h"

#include <fstream> // ofstream
#include <chrono> // high_resolution_clock

SegmentManager::SegmentManager() {
    size = 0;
}

int SegmentManager::partition(int p, int r) {
    /* This function is written according to the pseudocode in
     the lecture slides. */
    return 0;
}

void SegmentManager::quickSort(int p, int r) {
    /* This function is written according to the pseudocode in
     the lecture slides. */
    
    if (p < r) {
        int q = partition(p, r);
        quickSort(p, q-1);
        quickSort(p, q+1);
    }
}

float SegmentManager::sortSegments() {
    using namespace chrono;
    
    auto sortingStart = high_resolution_clock::now(); // Begin time stamp
    quickSort(0, size-1);
    auto sortingEnd = high_resolution_clock::now(); // End time stamp
    
    // Get the elapsed time in unit microseconds
    float elapsed_time = duration_cast<microseconds>(sortingEnd - sortingStart).count();
    
    return elapsed_time;
}

void SegmentManager::insertionSort(COMPARETYPE compareBy) {
    /* This function is written according to the pseudocode in
     the Week-1 slide. */
    
    Segment key;
    int i, j;
    for (j=1; j < size; j++) {
        key = segments[j];
        i = j - 1;
        
        while ((i >= 0) && (key.compare(segments[i], compareBy)) < 0) {
            segments[i+1] = segments[i];
            i--;
        }
        segments[i+1] = key;
    }
}

void SegmentManager::mergeSort(int p, int r, COMPARETYPE compareBy) {
    /* This function is written according to the pseudocode in
     the Week-2 slide. */
    
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(p, q, compareBy);
        mergeSort(q+1, r, compareBy);
        merge(p, q, r, compareBy);
    }
}

void SegmentManager::merge(int p, int q, int r, COMPARETYPE compareBy) {
    /* This function is written according to the pseudocode in
     the Week-2 slide. */
    
    int n1 = (q - p) + 1;
    int n2 = (r - q);
    
    int i, j;
    
    vector<Segment> left;
    vector<Segment> right;
    
    left.resize(n1);
    right.resize(n2);
    
    for(i = 0; i < n1; i++) {
        left[i] = segments[p+i];
    }
    
    for(j = 0; j < n2; j++) {
        right[j] = segments[q+j+1];
    }

    i = j = 0;
    int k;
    for(k=p; k < r; k++) {
        if ((i >= n1) || (j >= n2))
            break;
        
        if ((left[i]).compare(right[j], compareBy) <= 0) {
            segments[k] = left[i];
            i++;
        } else {
            segments[k] = right[j];
            j++;
        }
    }
    
    while(i < n1) {
        segments[k] = left[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        segments[k] = right[j];
        j++;
        k++;
    }
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
        output << (segments[counter]).getMinAge() << ',';
        output << (segments[counter]).getMaxAge() << ',';
        output << (segments[counter]).getGender() << ',';
        output << (segments[counter]).getZipCode() << ',';
        output << (segments[counter]).getGeoId() << endl;
    }
    
    // Close the output file since it is no longer needed
    output.close();
}

