// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogLoader.h"

DialogLoader::DialogLoader()
{
}

DialogLoader::~DialogLoader()
{
}

bool DialogLoader::FileSaveString(FString SaveTextB, FString FileNameB)
{
    return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::ProjectDir() + FileNameB));
}

bool DialogLoader::FileLoadString(FString FileNameA, FString& SaveTextA)
{
    return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::ProjectDir() + FileNameA));
}