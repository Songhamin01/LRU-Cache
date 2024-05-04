#include "cache.h"
// TODO: 필요한 함수 구현

Cache::Cache()
{
    Cur_size = 0;
    pHead = nullptr;
}

Cache::~Cache()
{
    while (pHead != nullptr)
    {
        struct node* temp = pHead;
        pHead = pHead->pNext;
        delete temp;
    }
}

// int를 cache에 추가한다
void Cache::add(std::string key, int value)
{
    struct node* pNode = new struct node;
    pNode->key = key;
    pNode->value_int = value;
    pNode->value_double = 0;
    pNode->pNext = nullptr;

    if (Cur_size == 0)
    {
        pHead = pNode;
        Cur_size++;
    }
    else
    {
        // cache에 정보가 이미 저장되어 있는 경우
        if (this->get(key, value))
        {
            struct node* temp = pHead;
            struct node* pPrev = new struct node;
            struct node* pHere = new struct node;
            while(temp->pNext != nullptr)
            {
                if (temp->key == key && temp->value_int == value)
                {
                    pHere = temp;
                    pPrev->pNext = temp->pNext;
                }
                pPrev = temp;
                temp = temp->pNext;
            }
            temp->pNext = pHere;
            pHere->pNext = nullptr;
            delete pPrev;
            delete temp;
            delete pHere;
        }
        else 
        {
            if (Cur_size >= Max_size)
            {
                struct node* temp = pHead;
                pHead = pHead->pNext;
                delete temp;
            }
            struct node* pLastNode = pHead;
            while (pLastNode->pNext != nullptr)
            {
                pLastNode = pLastNode->pNext;
            }
            pLastNode->pNext = pNode;
            Cur_size++;
            delete pLastNode;
        }
    }
}

// double을 cache에 추가한다
void Cache::add(std::string key, double value)
{
    struct node* pNode = new struct node;
    pNode->key = key;
    pNode->value_int = 0;
    pNode->value_double = value;
    pNode->pNext = nullptr;

    if (Cur_size == 0)
    {
        pHead = pNode;
        Cur_size++;
    }
    else
    {
        // cache에 정보가 이미 저장되어 있는 경우
        if (this->get(key, value))
        {
            struct node* temp = pHead;
            struct node* pPrev;
            struct node* pHere;
            while(temp->pNext != nullptr)
            {
                if (temp->key == key && temp->value_double == value)
                {
                    pHere = temp;
                    pPrev->pNext = temp->pNext;
                }
                pPrev = temp;
                temp = temp->pNext;
            }
            temp->pNext = pHere;
            pHere->pNext = nullptr;
            delete pPrev;
            delete temp;
            delete pHere;
        }
        else 
        {
            if (Cur_size >= Max_size)
            {
                struct node* temp = pHead;
                pHead = pHead->pNext;
                delete temp;
            }
            struct node* pLastNode = pHead;
            while (pLastNode->pNext != nullptr)
            {
                pLastNode = pLastNode->pNext;
            }
            pLastNode->pNext = pNode;
            Cur_size++;
            delete pLastNode;
        }
    }
}

// key에 해당하는 value를 cache에서 가져온다
// 타입과 key가 동일한 원소가 없다면 false를 반환한다.
bool Cache::get(std::string key, int &value)
{
    struct node* temp = pHead;
    while (temp != nullptr)
    {
        if (temp->key == key && temp->value_int != 0)
        {
            value = temp->value_int;
            return true;
        }
        temp = temp->pNext;
    }
    return false;
}
// key에 해당하는 value를 cache에서 가져온다.
// 타입과 key가 동일한 원소가 없다면 false를 반환한다.
bool Cache::get(std::string key, double &value)
{
    bool isThere = false;
    struct node* temp = pHead;
    while (temp != nullptr)
    {
        if (temp->key == key && temp->value_double != 0)
        {
            value = temp->value_double;
            return true;
        }
        temp = temp->pNext;
    }
    return false;
}

// 디버그 및 채점 용: 연결 리스트를 문자열로 표현하여 반환한다
// 다음과 같이 표현된 문자열을 반환한다
// [key1: value1] -> [key2: value2] -> ... -> [keyN: valueN]
std::string Cache::toString()
{
    std::string result = "";
    struct node* temp = pHead;
    while (temp != nullptr)
    {
        if (temp->value_int != 0)
        {
            result += "[" + temp->key + ": " + std::to_string(temp->value_int) + "]";
        }
        else
        {
            result += "[" + temp->key + ": " + std::to_string(temp->value_double) + "]";
        }
        if (temp->pNext != nullptr)
        {
            result += " -> ";
        }
        temp = temp->pNext;
    }
    result += "\n";
    return result;
}