﻿// LoginServer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "GameService.h"
#include "CrashReport.h"
#include "CommandLine.h"
#include "WatcherClient.h"

int main(int argc, char* argv[])
{
	SetCrashReport("LoginServer");

	CCommandLine cmdLine(argc, argv);

	if (CGameService::GetInstancePtr()->Init())
	{
		CGameService::GetInstancePtr()->Run();
	}

	CGameService::GetInstancePtr()->Uninit();

	UnSetCrashReport();

	return 0;
}

