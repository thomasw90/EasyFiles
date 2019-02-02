/*
 * File.cpp
 *
 *  Created on: 02.01.2019
 *      Author: Thomas
 */

#include "file.h"
#include "directory.h"
#include "tinydir.h"
#include <math.h>

File::File(const std::string& a_fileName, Directory* a_parentDirectory)
	: m_fileName(a_fileName)
	, m_parentDirectory(a_parentDirectory)
{}

std::string File::fileName() const
{
	return m_fileName;
}

void File::changeFileNameToRandom(int a_digits)
{
	int min = 0;
	int max = 0;

	for(int i = 0 ; i < a_digits ; i++)
	{
		min += pow(10, i);
		max += pow(10, i) * 9;
	}

	int randNum = (rand()*rand())%(max-min + 1) + min;
    char newFileName[10];
    sprintf(newFileName, "%d%s", randNum, suffix().c_str());

	rename(m_fileName.c_str(), newFileName);
}

std::string File::suffix() const
{
    auto lastDotPosition = m_fileName.find_last_of(".");
    if (lastDotPosition == std::string::npos)
    {
    	return "";
    }
    else
    {
    	return m_fileName.substr(lastDotPosition, m_fileName.length()-1);
    }
}

Directory* File::parentDirectory()
{
	return m_parentDirectory;
}
