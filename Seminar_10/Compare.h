#pragma once
class Compare
{
public:
	~Compare();
	virtual int CompareElements(void* e1, void* e2) = 0;
};

