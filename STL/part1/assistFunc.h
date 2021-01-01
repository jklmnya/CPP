#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

#define CSIZE 500000

long get_a_target_long() {
    long target = 0l;
    cout<<"target (0~"<<RAND_MAX<<"):";
    cin>>target;
    return target;
}

string get_a_target_string() {
    long target;
    char buf[10];
    cout<<"target (0~"<<RAND_MAX<<"):";
    cin>>target;

    snprintf(buf, 10, "%d", target);
    return string(buf);
}

int compareLongs(const void* a, const void* b) {
    return (*(long*)a - (*(long*)b));
}

int compareStrings(const void* a, const void* b) {
    if (*(string*)a > *(string*)b) { return 1;}
    else if (*(string*)a < *(string*)b) { return -1;}
    else { return 0; }
}