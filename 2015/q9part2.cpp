#include<iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<int> allDistances;

struct myStruc{
    string city1;
    string city2;
    int distance;

};
// Function to reset the "visited" status of cities after a search is complete
void resetVisited(vector<pair<string,bool>> &visited, vector<myStruc> data){

    for(int i = 0; i<visited.size(); i++){
        visited[i].second = 0;
    }

}

// Function to extract a word (city name or distance) from a string based on its position
string extractWord(string str, int count){
    string temp;
    count--;
    for(char c:str){
        if(c == ' '){ // Skip spaces
            count--;
            continue;
        }
        if(count == 0) temp += c; // When count reaches zero, start adding characters to 'temp'
    }
    return temp; // Return the extracted word (city name or distance)
}

// Function to count how many cities have been marked as "visited" (status == true)
int countVisited(vector<pair<string,bool>> &visited){
    int count = 0;
    for(pair<string,bool> element : visited){
        if(element.second == 1){
            count += 1;
        }
    }
    return count;
}

// Function to mark a city as visited
void markVisited(string city, vector<pair<string,bool>> &visited){
    for(int i = 0; i < visited.size(); i++){
        if(visited[i].first == city){
            visited[i].second = 1; // Mark the city as visited
        }
    }
}
void calMaxDistance(string city, vector<myStruc> data, vector<pair<string,bool>> &visited,int &distance){
    
    // Mark the current city as visited
    markVisited(city, visited);

    // Check how many cities have been visited so far
    int count = countVisited(visited);

    // If all cities are visited, reset the visited status for all cities and return
    if(count == visited.size()){
        resetVisited(visited, data);
        return;
    }

    //function to calculate the furthest city from the current city
    int maxDistance = INT32_MIN;
    string nextCity;
    for(myStruc values : data){
        if(values.city1==city || values.city2==city){
            for(pair<string,bool> element : visited){
                if(element.first==values.city1 || element.first==values.city2){
                    //if city is not visited, check if its distance is larger than the maximum distance
                    if(element.second==0){
                        //if distance is larger than the maximum, update the maxDistance and city to be visited
                        if(maxDistance<values.distance){
                            maxDistance = values.distance;
                            nextCity = element.first;
                        }
                    }
                }
            }
        }
    }
    //append the current max to the total distance
    distance+=maxDistance;
    //recursively visit all the cities
    calMaxDistance(nextCity,data,visited,distance);
}

int main() {
    string s;
    vector<myStruc> data;

    ifstream myfile;
    myfile.open("q9input.txt");

    // Read the input file line by line
    while(getline(myfile, s)){

        // Extract city names and distance from the line
        string city1 = extractWord(s, 1);
        string city2 = extractWord(s, 3);
        int distance = stoi(extractWord(s, 5));

        // Create a new structure for the city pair and distance and add it to 'data'
        myStruc a = {city1, city2, distance};
        data.push_back(a);
    }

    // Vector to keep track of visited cities
    vector<pair<string,bool>> visited;

    // Populate the visited vector with unique city names
    for(myStruc values : data){
        bool duplicate1 = 0;
        bool duplicate2 = 0;
        // Check if city1 and city2 are already in the visited list
        for(pair<string,bool> element: visited){
            if(element.first == values.city1){
                duplicate1 = 1;
            }
            if(element.first == values.city2){
                duplicate2 = 1;
            }
        }
        // If city1 is not in visited list, add it
        if(!duplicate1){
            visited.push_back({values.city1, 0});
        }
        // If city2 is not in visited list, add it
        if(!duplicate2){
            visited.push_back({values.city2, 0});
        }
    }

    // variable to store the maximum route
    int distance = 0;
    int maxDistance = INT16_MIN;
    for(pair<string,bool> element: visited){
        calMaxDistance(element.first,data,visited,distance);
        maxDistance = max(maxDistance,distance);
        distance = 0;
    }
    cout<<maxDistance;
}