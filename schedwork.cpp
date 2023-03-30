#ifndef RECCHECK
#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // delete if necessary
#include <vector>
#include <map>
#include <algorithm>
#endif

// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here

bool workHelperFunc(
    const Worker_T& currWorker,
    vector<vector<Worker_T>>& sched,
    const int& day
);
void scheduleHelperFunc(
    const vector<vector<bool>>& avail,
    vector<vector<Worker_T>>& sched,
    int shiftNum[],
    int& day,
    const size_t dailyNeed,
    const size_t maxShifts,
    bool& valid
);


// Add your implementation of schedule() and other helper functions here

bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    // Add your code below

    vector<Worker_T> vecId;
    bool valid = false;
    int day = 0;

    for (int i = 0; i < (int)avail.size(); ++i) {
      sched.push_back(vecId);
    }

  int shiftNum[avail[0].size()];
  memset(shiftNum, 0, sizeof(shiftNum));
  
    scheduleHelperFunc(avail, sched, shiftNum, day, dailyNeed, maxShifts, valid);
    return valid;
}



bool workHelperFunc(
    const Worker_T& currWorker,
    vector<vector<Worker_T>>& sched,
    const int& day
)
{

  if (sched[day].size() == 0) { // no workers scheduled that day (vec of worker id)
    return true;
  }

  else { // atleast one worker scheduled for that day --> must iterate to check if the worker we are checking for is scheduld for that day 
    for (int i = 0; i < (int)sched[day].size(); ++i) {
      if (sched[day][i] == currWorker) {
        return false;
      }
    }
  return true; // if not found, then return true;
  }
}



void scheduleHelperFunc(
    const vector<vector<bool>>& avail,
    vector<vector<Worker_T>>& sched,
    int shiftNum[],
    int& day,
    const size_t dailyNeed,
    const size_t maxShifts,
    bool& valid
)
{

  for (int i = 0; i < (int)avail[0].size(); ++i) {
    Worker_T currWorker = (size_t)i;
    // if current worker is available on that day && current worker is not filled up max && current worker isn't already working that day 
    if (avail[day][currWorker] == true && shiftNum[currWorker] < (int)maxShifts && workHelperFunc(currWorker, sched, day)) {
      ++shiftNum[currWorker]; // add number of shift
      sched[day].push_back(currWorker); // add currworker to schedule

      if (sched[day].size() == dailyNeed) { // max workers filled for day
        if (day < (int)avail.size() - 1) { // if there are more days to be filled
          ++day; // move onto next day, recurse
          scheduleHelperFunc(avail, sched, shiftNum, day, dailyNeed, maxShifts, valid);

          if (valid) { // if valid schedule, then finish
            return;
          }
          else { // else if it gets here without creating a valid schedule, backtrack and recurse again. 
            --shiftNum[currWorker];
            --day;
            sched[day].pop_back();
          }
        }
        else { // final day complete
          valid = true;
          return;
        }
      }
      else { // can have workers that day
        scheduleHelperFunc(avail, sched, shiftNum, day, dailyNeed, maxShifts, valid); // recurse
        if (valid) {
          return;
        }
        else { // gets to here (THE END, but WORKERS ARE STILL NEEDED THAT DAY) --> otherwise backtrack 
          sched[day].pop_back();
          --shiftNum[currWorker];
        }
      }
    }
  }

}


