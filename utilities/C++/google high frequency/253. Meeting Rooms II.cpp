// 253. Meeting Rooms II
/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool cmp(Interval a, Interval b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt = 0;
        for(int i=0;i<intervals.size();i++){
            if(pq.empty()){
                cnt++;
            }
            else if( intervals[i].start>=pq.top()){
                pq.pop();
            }
            else{
                cnt++;
            }
            pq.push(intervals[i].end);
        }
        return cnt;
    }
};


class Solution {
public:
    static bool cmp(Interval a, Interval b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start;
        vector<int> end;
        for(int i=0;i<intervals.size();i++){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(), end.end());
        int j = 0;
        int cnt=0;
        for(int i=0;i<start.size();i++){
            if(start[i]<end[j]){
                cnt++;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};