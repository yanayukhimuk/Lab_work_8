#pragma once
#include "Info.h"
#include <vector>

//void OpenFile();
void dataLoad(std::vector<Data>& people, const std::string fileName);
void dataInput(std::vector<Data>& people);
void dataAppend(std::vector<Data>& people, const std::string fileName);
void dataSortSurname(std::vector<Data>& people);
void dataSortAge(std::vector<Data>& people);

void PeopleMonth(std::vector<Data>& people, int givenMonth);
void TheOldest(std::vector<Data>& people);
void SameLetter(std::vector<Data>& people, char firstLetterOfLastsNames);