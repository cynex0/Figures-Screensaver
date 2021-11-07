#pragma once
#include <string>
using namespace std;

class ISerializable {
public:
	virtual string ToString() = 0;
	virtual void FromString(string s) = 0;
};
