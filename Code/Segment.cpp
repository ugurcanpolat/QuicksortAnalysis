/* @Author
 * Student Name: Ugurcan Polat
 * Student ID : 150140117
 * Date: 09.11.2017
 * * * * * * * * * * * * * * * * * *
 
 Compile command: g++ -std=c++11 150140117.cpp -o project2
 
 * * * * * * * * * * * * * * * * * */

#include "Segment.h"

Segment::Segment(const string input[]) {
    population = stoi(input[0]);
    
    if(input[1].empty()) // If minimum_age is null
        minAge = -1;
    else
        minAge = stoi(input[1]);
    
    if(input[2].empty()) // If maximum_age is null
        maxAge = -1;
    else
        maxAge = stoi(input[2]);
    
    gender = input[3];
    zipCode = stoi(input[4]);
    geoId = input[5];
}

int Segment::getPopulation() const {
    return population;
}

int Segment::getMinAge() const  {
    return minAge;
}

int Segment::getMaxAge() const {
    return maxAge;
}

string Segment::getGender() const {
    return gender;
}

int Segment::getZipCode() const {
    return zipCode;
}

string Segment::getGeoId() const {
    return geoId;
}

int Segment::compare(const Segment& cmp, COMPARETYPE compareBy) const {
    string selfGeoId, otherGeoId;
    
    int otherPopulation = cmp.getPopulation();
    
    // Get values for comparison type
    switch(compareBy) {
        case POPULATION:
            if (population < otherPopulation) {
                return -1;
            } else if (population == otherPopulation) {
                return 0;
            } else {
                return 1;
            } break;
        case GEO_ID:
            selfGeoId = geoId;
            otherGeoId = cmp.getGeoId();
            break;
        case SORT:
            return sortCompare(*this, cmp);
        default:
            return -1;
            break;
    }
    
    // Return string compare
    return selfGeoId.compare(otherGeoId);
}

int Segment::sortCompare(const Segment& self, const Segment& cmp) const {
    /* This function compares |this| segment with the |cmp| */
    
    // Get the comparison results for population and geo_id
    int populationCompare = self.compare(cmp, POPULATION);
    int geoIdCompare = self.compare(cmp, GEO_ID);
    
    if (populationCompare == 0) {
        return geoIdCompare;
    } else { // Different population
        return populationCompare;
    }
}
