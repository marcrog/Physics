#include<iostream>
#include"../../include/Engine.h"

//----------------------------------------------------------------------------
//#         CorpList DEFINITIONS

CorpList::CorpList(){}

int CorpList::size()
{
    int result = 0;
    for(auto it = corps.begin(); it != corps.end(); it++)
        result++;
    return result;
}

bool CorpList::add(Corp* b)
{
    int start_size = CorpList::size();
    corps.push_back(b);
    if(CorpList::size() == start_size + 1)
        return true;
    else
        return false;
}

bool CorpList::remove(Corp* b)
{
    int start_size = CorpList::size();
    corps.remove(b);
    if(CorpList::size() == start_size - 1)
        return true;
    else
        return false;
}

std::list<Corp*> CorpList::getCorps()
{
    return corps;
}

Corp* CorpList::getCorp(int i)
{
    int j = 0;
    for(auto it = corps.begin(); it != corps.end(); it++)
    {
        if(j == i)
            return *it;
        j++;
    }
    return NULL;
}