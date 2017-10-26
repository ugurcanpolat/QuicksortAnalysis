/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 09.11.2017
 */

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
    
    bool minNull;
    bool maxNull;
    
    string name;
    string cardClass;
    string rarity;
    string set;
    string type;
    int cost;
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
    int sortCompare(const Segment& cmp1, const Segment& cmp2) const;
};

#endif /* Segment_h */
