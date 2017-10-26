/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 09.11.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project2
 
 * * * * * * * * * * * * * * * * * */

#ifndef Segment_h
#define Segment_h

#include <string> // string

using namespace std;

#ifndef compare_enum
#define compare_enum
typedef enum CompareType {
    POPULATION = 0, GEO_ID, SORT
} COMPARETYPE;
#endif /* compare_enum */

class Segment {
  private:
    int population;
    int minAge;
    int maxAge;
    string gender;
    int zipCode;
    string geoId;
    int sortCompare(const Segment& cmp1, const Segment& cmp2) const;
  public:
    Segment() {}; // Necessary for 'new []' allocations
    Segment(const string input[]);
    int getPopulation() const;
    int getMinAge() const;
    int getMaxAge() const;
    string getGender() const;
    int getZipCode() const;
    string getGeoId() const;
    int compare(const Segment& cmp, COMPARETYPE compareBy) const;
};

#endif /* Segment_h */
