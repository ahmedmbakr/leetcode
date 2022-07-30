//
// Created by bakr on 30/07/22.
//
//https://leetcode.com/problems/bus-routes/
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <queue>
using namespace std;

class Solution {
    struct Route;
    struct BusStop{
        int idx = -1;
        vector<pair<Route*, int>> associated_routes;//associated routes and its index in each route
    };
    struct Route{
        int route_id;
        vector<BusStop*> bus_stops;
        Route(int route_id){
            this->route_id = route_id;
        }
    };
    vector<Route*> routes_vec;
    BusStop bus_stops_arr[100000];
    bool visited_bus_stops[100000];
    bool visited_routes[500];
    struct QueueElem{
        int index_of_bus_stop_in_route;
        BusStop* bus_stop;
        int num_droven_buses;
        Route* route;
    };
    queue<QueueElem> q; // stop and num bases so far
    void add_all_siblings_to_bus_stop_in_route(QueueElem& queue_elem){
        //add bus stops in the same route
        if(!visited_routes[queue_elem.route->route_id]) {
            visited_routes[queue_elem.route->route_id] = true;
            for (int i = 1; i < queue_elem.route->bus_stops.size(); ++i) {
                int idx = (i + queue_elem.index_of_bus_stop_in_route) % queue_elem.route->bus_stops.size();
                BusStop & bus_stop = *queue_elem.route->bus_stops[idx];
                if (!visited_bus_stops[bus_stop.idx]) {
                    visited_bus_stops[bus_stop.idx] = true;
                    QueueElem new_queue_elem;
                    new_queue_elem.index_of_bus_stop_in_route = idx;
                    new_queue_elem.bus_stop = &bus_stop;
                    new_queue_elem.num_droven_buses = queue_elem.num_droven_buses;
                    new_queue_elem.route = queue_elem.route;
                    q.push(new_queue_elem);
                }
            }
        }
    }

    void add_bus_stops_in_adjacent_routes(BusStop& bus_stop, int num_droven_buses){
        QueueElem queue_elem;
        queue_elem.num_droven_buses = num_droven_buses + 1;
        queue_elem.bus_stop = &bus_stop;
        for(auto pair_val: bus_stop.associated_routes){
            Route* route = pair_val.first;
            int index_in_route = pair_val.second;
            queue_elem.route = route;
            queue_elem.index_of_bus_stop_in_route = index_in_route;
            if(!visited_routes[route->route_id]){
                q.push(queue_elem);
            }
        }
    }
    int bfs(int target){
        while(!q.empty()){
            QueueElem queue_elem = q.front();
            q.pop();
            if(queue_elem.bus_stop->idx == target)
                return queue_elem.num_droven_buses;
            add_all_siblings_to_bus_stop_in_route(queue_elem);
            add_bus_stops_in_adjacent_routes(*queue_elem.bus_stop, queue_elem.num_droven_buses);

        }
        return -1;
    }
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)return 0;
        QueueElem queue_elem;
        queue_elem.num_droven_buses = 1;
        for(int i = 0; i < routes.size(); ++i){
            routes_vec.push_back(new Route(i));
            queue_elem.route = routes_vec[i];
            for(int j = 0; j < routes[i].size(); ++j){
                BusStop &bus_stop = bus_stops_arr[routes[i][j]];
                if(bus_stop.idx == -1){
                    bus_stop.idx = routes[i][j];
                }
                if(routes[i][j] == source){
                    queue_elem.index_of_bus_stop_in_route = j;
                    queue_elem.bus_stop = &bus_stop;
                    q.push(queue_elem);
                }
                bus_stop.associated_routes.push_back(make_pair(routes_vec[i], j));
                routes_vec[i]->bus_stops.push_back(&bus_stop);
            }
        }
        return bfs(target);
    }
};

int main(){
    vector<vector<int>> routes = {{1,2,7},{3,6,7}};
    Solution sol;
    cout << sol.numBusesToDestination(routes, 1, 6);
    return 0;
}
