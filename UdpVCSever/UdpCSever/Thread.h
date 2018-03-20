#pragma once

#ifndef _Thread_H
#define _Thread_H

#include "stdio.h"  
#include "iostream"  
#include "Udp.h"
#include "DataPack.h"

DWORD WINAPI ThreadReceive(LPVOID lpParam);

//数据包初始化
extern DataPack dataPack;

//UDP初始化
extern UdpSever udpSever;

#endif






