#include<iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

// Structure to store each edge and its associated distance
struct myStruc{
    string city1;
    string city2;
    int distance;
};

// Function to reset the "visited" status of cities after a search is complete
void resetVisited(vector<pair<string,bool>> &visited, vector<myStruc> data){
    // Reset each city as "not visited" (false) after a pathfinding attempt
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

// Recursive function to calculate the minimum distance by exploring all cities
void calMinDistance(string city, vector<myStruc> data, vector<pair<string,bool>> &visited, int &distance){

    // Mark the current city as visited
    markVisited(city, visited);

    // Check how many cities have been visited so far
    int count = countVisited(visited);

    // If all cities are visited, reset the visited status for all cities and return
    if(count == visited.size()){
        resetVisited(visited, data);
        return;
    }

    // Initialize the minimum distance and next city to visit
    int minDistance = INT32_MAX;
    string nextCity;

    // Loop through all the city pairs in the data
    for(myStruc values : data){

        // Check if the current city is either the start or end city of the edge
        if(values.city1 == city || values.city2 == city){

            // Loop through all the cities and check if the city is unvisited
            for(pair<string,bool> element : visited){

                if(element.first == values.city1 || element.first == values.city2){

                    // If the city is unvisited, consider it for the next step
                    if(element.second == 0){

                        // Update the minimum distance and next city to visit
                        if(minDistance > values.distance){
                            minDistance = values.distance;
                            nextCity = element.first;
                        }
                    }
                }
            }
        }
    }

    // Add the minimum distance found to the total distance
    distance += minDistance;

    // Recursively call calMinDistance for the next city
    calMinDistance(nextCity, data, visited, distance);
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

    // Variable to track the total distance for a path
    int distance = 0;
    int minDistance = INT16_MAX;

    // Try calculating the minimum distance starting from each city
    for(pair<string,bool> element: visited){
        calMinDistance(element.first, data, visited, distance);
        // Keep track of the smallest distance found
        minDistance = min(minDistance, distance);
        distance = 0; // Reset distance for the next attempt
    }

    // Output the minimum distance found
    cout << minDistance;

    return 0;
}
