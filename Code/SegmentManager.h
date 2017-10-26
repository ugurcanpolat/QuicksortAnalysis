/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 09.11.2017
 */

#ifndef SegmentManager_h
#define SegmentManager_h

#include "Segment.cpp"

#include <iostream> 
#include <vector> // vector

class SegmentManager {
  private:
    vector<Segment> segments;
    int size;
    void insertionSort(COMPARETYPE compareBy);
    void mergeSort(int p, int r, COMPARETYPE compareBy);
    void merge(int p, int q, int r, COMPARETYPE compareBy);
    int partition(int p, int r);
    void quickSort(int p, int r);
  public:
    SegmentManager();
    float sortSegments();
    void insertSegment(const Segment& new_card);
    void writeOutputFile(const string file_name) const;
};

#endif /* SegmentManager_h */
