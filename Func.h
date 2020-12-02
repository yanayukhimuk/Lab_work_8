#pragma once
#include "Info.h"
#include <vector>

void dataLoad(vector<Data>& people, const string fileName);
void dataOutput(vector<Data>& people);
void dataAppend(vector<Data>& people, const string fileName);
void sortDataBySurname(vector<Data>& people);
void sortDataByAge(vector<Data>& people);
void printPeopleWithBirthMonth(vector<Data>& people, int givenMonth);
void printOldestOf(vector<Data>& people);
void printGroupedBy(vector<Data>& people, char firstLetterOfLastsNames);