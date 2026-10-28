#pragma once 
#include <iostream>  
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#include <fstream>
#define FILENAME "empFile.txt"




class WorkerManager{
public:
    WorkerManager();
    void Show_Menu();
    ~WorkerManager();
}